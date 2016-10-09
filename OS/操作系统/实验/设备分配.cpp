#include <iostream>
using namespace std;
#define PROCESSNAME 20//进程名大小
#define DEVICESIZE 20//设备名字大小
#define CHANNELSSIZE 20//通道名字大小
#define CONTROLSIZE 20//控制器名字大小
#define DEVICENUMBER 4//默认设备数
#define COMMANDNUMBER 3//一次输入命令个数
#define length 100


typedef struct PROCESS
{
	char processName[PROCESSNAME];
	char deviceName[DEVICESIZE];
	struct PROCESS * next;
}Process;//进程名和设备名



typedef struct ChannelsControlTable//CHCT
{
	char channelsName[CHANNELSSIZE];
	bool state;
	char processName[PROCESSNAME];//存在于进程的结构体
	char deviceName[DEVICESIZE];//存在于设备的结构体
	Process * block;
	struct ChannelsControlTable * next;
}CHCT;//通道控制表



typedef struct ControlControlTable
{
	char controlName[CONTROLSIZE];
	bool state;
	char processName[PROCESSNAME];
	char deviceName[DEVICESIZE];
	CHCT *chct;//用来与chct相联系
	Process * block;
	struct ControlControlTable * next;
}COCT;//控制器控制表



typedef struct DeviceControlTable
{
	char deviceName[DEVICESIZE];
	bool state;
	char processName[PROCESSNAME];
	COCT * coct;
	Process * block;
	DeviceControlTable * next;
}DCT;//设备控制表



typedef struct SystemDeviceTable
{
	char processName[PROCESSNAME];
	char deviceName[DEVICESIZE];
	struct SystemDeviceTable * next;
}SDT;//系统设备表





//////////////////////////////////内存分配时的初始化///////////////////////////////////////////
Process * initProcess(Process *p)//进程
{
	int i;//用于初始化
	for(i=0;i<PROCESSNAME;i++)
		p->deviceName[i]='\0';
	for(i=0;i<DEVICESIZE;i++)
		p->processName[i]='\0';
	p->next=NULL;
	return p;
}
CHCT * initCHCT(CHCT *chct)//通道控制表
{
	int i;
	for(i=0;i<CHANNELSSIZE;i++)
		chct->channelsName[i]='\0';
	chct->state=0;
	for(i=0;i<PROCESSNAME;i++)
		chct->deviceName[i]='\0';
	for(i=0;i<DEVICESIZE;i++)
		chct->processName[i]='\0';
	chct->block=NULL;
	chct->next=NULL;
	return chct;
}
COCT * initCOCT(COCT *coct)//控制器控制表
{
	int i;
	for(i=0;i<CONTROLSIZE;i++)
		coct->controlName[i]='\0';

	coct->state=0;
	for(i=0;i<PROCESSNAME;i++)
		coct->deviceName[i]='\0';
	for(i=0;i<DEVICESIZE;i++)
		coct->processName[i]='\0';
	coct->chct=NULL;
	coct->block=NULL;
	coct->next=NULL;
	return coct;
}

DCT * initDCT(DCT *dct)//设备控制表
{
	int i;
	for(i=0;i<PROCESSNAME;i++)
		dct->deviceName[i]='\0';
	dct->state=0;
	for(i=0;i<DEVICESIZE;i++)
		dct->processName[i]='\0';
	dct->coct=NULL;
	dct->block=NULL;
	dct->next=NULL;
	return dct;
}
SDT * initSDT(SDT *sdt)//系统控制表
{
	int i;
	for(i=0;i<PROCESSNAME;i++)
		sdt->deviceName[i]='\0';
	for(i=0;i<DEVICESIZE;i++)
		sdt->processName[i]='\0';
	sdt->next=NULL;
	return sdt;
}
/////////////////////////////////////////////////////////////////////////////
void init(DCT * dct,COCT * coct,CHCT * chct)                      //两个通道
{
	CHCT *ch1=(CHCT *)malloc(sizeof(CHCT));
	ch1=initCHCT(ch1);
	strcpy(ch1->channelsName,"CH1");
	chct->next=ch1;
	CHCT *ch2=(CHCT *)malloc(sizeof(CHCT));
	ch2=initCHCT(ch2);
	strcpy(ch2->channelsName,"CH2");
	chct->next->next=ch2;
	
	/////////////////////////////////////////////
	COCT *co1=(COCT *)malloc(sizeof(COCT));                     //三个控制器  一个1  两个2
	co1=initCOCT(co1);
	strcpy(co1->controlName,"CO1");
	co1->chct=ch1;
	coct->next=co1;

	COCT *co2=(COCT *)malloc(sizeof(COCT));
	co2=initCOCT(co2);
	strcpy(co2->controlName,"CO2");
	co2->chct=ch2;
	coct->next->next=co2;


	COCT *co3=(COCT *)malloc(sizeof(COCT));
	co3=initCOCT(co3);
	strcpy(co3->controlName,"CO3");
	co3->chct=ch2;
	coct->next->next->next=co3;

	////////////////////////////////////////////KM1T2P3的初始化
	DCT *k=(DCT *)malloc(sizeof(DCT));
	k=initDCT(k);
	strcpy(k->deviceName,"K");
	k->coct=co1;
	dct->next=k;
	DCT *m=(DCT *)malloc(sizeof(DCT));
	m=initDCT(m);
	strcpy(m->deviceName,"M");
	m->coct=co1;
	dct->next->next=m;
	
	DCT *t=(DCT *)malloc(sizeof(DCT));
	t=initDCT(t);
	strcpy(t->deviceName,"T");
	t->coct=co2;
	dct->next->next->next=t;
	
	DCT *p=(DCT *)malloc(sizeof(DCT));
	p=initDCT(p);
	strcpy(p->deviceName,"P");
	p->coct=co3;
	dct->next->next->next->next=p;
	
}
void display(Process *process,DCT * dct,COCT * coct,CHCT * chct)
{
	cout<<"-------------------进程链表状态------------------------"<<endl;
	if(process->next==NULL)
		cout<<"此时无进程"<<endl;
	else
	{
	cout<<"进程名"<<"	"<<"设备名"<<endl;
	for(Process *t=process->next;t!=NULL;t=t->next)
	{
		
		printf("%6s  %6s\n",t->processName,t->deviceName);
	}
	}
	cout<<endl;

	cout<<"------------------ 设备控制表状态-----------------------"<<endl;
	cout<<"设备名"<<"  "<<"状态"<<"  "<<"进程名"<<endl;
	for(DCT *t=dct->next;t!=NULL;t=t->next)
	{
		printf("%6s  %4d  %6s\n",t->deviceName,t->state,t->processName);
		cout<<"阻塞队列:";
		if(t->block==NULL)
			cout<<"空"<<endl;
		else
		{
			for(Process *r=t->block;r!=NULL;r=r->next)
			{
				cout<<r->processName<<"  ";
			}
			cout<<endl;
			}
	}
	//cout<<endl;
	

	cout<<"----------------------控制器控制表状态---------------------"<<endl;
	cout<<"控制器"<<"  "<<"状态"<<"  "<<"进程名"<<"  "<<"设备名"<<endl;
	for(COCT *tt=coct->next;tt!=NULL;tt=tt->next)
	{
		printf("%6s  %4d  %6s  %6s\n",tt->controlName,tt->state,tt->processName,tt->deviceName);

		cout<<"阻塞队列:";
		if(tt->block==NULL)
			cout<<"空"<<endl;
		else
		{
			for(Process *r=tt->block;r!=NULL;r=r->next)
			{
				cout<<r->processName<<"  ";
			}
			cout<<endl;
			}
	}
	//cout<<endl;

	cout<<"---------------------通道控制表状态-------------------------"<<endl;
	cout<<"通道名"<<"  "<<"状态"<<"  "<<"进程名"<<"  "<<"设备名"<<endl;
	for(CHCT *ttt=chct->next;ttt!=NULL;ttt=ttt->next)
	{
		printf("%6s  %4d  %6s  %6s\n",ttt->channelsName,ttt->state,ttt->processName,ttt->deviceName);
		cout<<"阻塞队列:";
		if(ttt->block==NULL)
			cout<<"空"<<endl;
		else
		{
			for(Process *r=ttt->block;r!=NULL;r=r->next)
			{
				cout<<r->processName<<"  ";
			}
			cout<<endl;
			}
	}
	//cout<<endl;
}
int search(char *array,int start){
	int i=start;
	for(;array[i]!='\0'&&i<length;){
		if(array[i]==' ')
		{
			return i;
		}
		else{
			i++;
		}
	}
	return i;
}

void addProcess(DCT * dct,COCT * coct,CHCT * chct,Process * temp,DCT * d)
{
	//////////////////////设备控制表
	if(d->state==1)
	{
		Process *p1=(Process *)malloc(sizeof(Process));
		p1=initProcess(p1);//初始化
		strcpy(p1->processName,temp->processName);
		strcpy(p1->deviceName,temp->deviceName);
		if(d->block==NULL)
		{
			d->block=p1;
			
		}
		else
		{
			Process * p;
			for(p=d->block;p->next!=NULL;p=p->next);
			p->next=p1;
		}
		return;
	}
	else
	{
		strcpy(d->processName,temp->processName);
		strcpy(d->deviceName,temp->deviceName);
		d->state=1;
	}
////////////////////////////////////////////////////控制器控制表
	if(d->coct->state==1)//coct的状态为占用
	{
		Process *p1=(Process *)malloc(sizeof(Process));
		p1=initProcess(p1);
		strcpy(p1->processName,d->processName);
		strcpy(p1->deviceName,d->deviceName);
		if(d->coct->block==NULL)
		{
			d->coct->block=p1;
			
		}
		else
		{
			Process * p;
			for(p=d->coct->block;p->next!=NULL;p=p->next);
			p->next=p1;
		}
		return;
	}
	else
	{
		strcpy(d->coct->processName,d->processName);
		strcpy(d->coct->deviceName,d->deviceName);
		d->coct->state=1;
	}

///////////////////////////////////////////////////////////////通道控制表
	if(d->coct->chct->state==1)
	{
		Process *p1=(Process *)malloc(sizeof(Process));
		p1=initProcess(p1);
		strcpy(p1->processName,d->coct->processName);
		strcpy(p1->deviceName,d->coct->deviceName);
		if(d->coct->chct->block==NULL)
		{
			d->coct->chct->block=p1;
			
		}
		else
		{
			Process * p;
			for(p=d->coct->chct->block;p->next!=NULL;p=p->next);
			p->next=p1;
		}
	}
	else
	{
		strcpy(d->coct->chct->processName,d->coct->processName);
		strcpy(d->coct->chct->deviceName,d->coct->deviceName);
		d->coct->chct->state=1;
	}
}


void addProcess(Process *process,DCT * dct,COCT * coct,CHCT * chct,Process * temp)
{
	if(process->next!=NULL)//进程名存在
	{
		for(Process *p=process->next;p!=NULL;p=p->next)
			if(strcmp(p->processName,temp->processName)==0)
				{
					cout<<temp->processName<<"进程已存在"<<endl;
					return;
				}
	}
	
	int flag=0;
	DCT *d;
	for(d=dct->next;d!=NULL;d=d->next)//设备名存在
	{
		if(strcmp(d->deviceName,temp->deviceName)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"不存在设备 "<<temp->deviceName<<endl;
		return;
	}
	Process *p=process;
	for(;p->next!=NULL;p=p->next);//找尾部加入
	p->next=temp;
	addProcess(dct,coct,chct,temp,d);
}

void delProcess(Process *process,DCT * dct,COCT * coct,CHCT * chct,Process * temp)
{
	if(process->next==NULL)
	{
		cout<<"此时没有设备不用删除"<<endl;
		return;
	}
	int flag=0;
	Process * p; //指向要删除的进程的前一个进程
	for(p=process;p->next!=NULL;p=p->next)//进程名存在
	{
		if(strcmp(p->next->processName,temp->processName)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"不存在进程"<<temp->processName<<endl;
		return;
	}
	flag=0;

	for(CHCT *c=chct->next;c!=NULL;c=c->next)//进程是否占用通道
	{
		if(strcmp(c->processName,temp->processName)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"进程"<<temp->processName<<"没有占用通道 不能删除"<<endl;
		return;
	}
	DCT *d;//查找要删除的设备
	for(d=dct->next;d!=NULL;d=d->next)
	{
		if(strcmp(d->processName,temp->processName)==0)
			break;
	}
	p->next=p->next->next;//从进程链表中删除
	/////////////////////////////////////////////////
	d->state=0;
	int i;
	for(i=0;i<PROCESSNAME;i++)
		d->processName[i]='\0';

	d->coct->state=0;
	for(i=0;i<PROCESSNAME;i++)
		d->coct->processName[i]='\0';
	for(i=0;i<DEVICESIZE;i++)
		d->coct->deviceName[i]='\0';

	d->coct->chct->state=0;
	for(i=0;i<PROCESSNAME;i++)
		d->coct->chct->processName[i]='\0';
	for(i=0;i<DEVICESIZE;i++)
		d->coct->chct->deviceName[i]='\0';
	///////////////////////////////////////////////////////////设备控制表
	if(d->block!=NULL)
	{
			strcpy(d->processName,d->block->processName);
			d->state=1;
			d->block=d->block->next;
	}


	////////////////////////////////////////////////////////////控制器控制表
		if(d->coct->block!=NULL)
		{
			strcpy(d->coct->processName,d->coct->block->processName);
			strcpy(d->coct->deviceName,d->coct->block->deviceName);
			d->coct->state=1;
			d->coct->block=d->coct->block->next;
			if(d->state==1)
			{
			Process *p1=(Process *)malloc(sizeof(Process));
			p1=initProcess(p1);//初始化
			strcpy(p1->processName,d->processName);
			strcpy(p1->deviceName,d->deviceName);
			if(d->coct->block==NULL)
			{
				d->coct->block=p1;
			
			}
			else
			{
				Process * p;
				for(p=d->coct->block;p->next!=NULL;p=p->next);
				p->next=p1;
			}
			}
		}
	else
		{
			if(d->state==1)
			{
			strcpy(d->coct->processName,d->processName);
			strcpy(d->coct->deviceName,d->deviceName);
			d->coct->state=1;
			}
		}

///////////////////////////////////////////////////////////////通道控制表
	if(d->coct->chct->block!=NULL)
		{
			strcpy(d->coct->chct->processName,d->coct->chct->block->processName);
			strcpy(d->coct->chct->deviceName,d->coct->chct->block->deviceName);
			d->coct->chct->state=1;
			d->coct->chct->block=d->coct->chct->block->next;

			if(d->coct->state==1)
			{
			Process *p1=(Process *)malloc(sizeof(Process));
			p1=initProcess(p1);//初始化

			strcpy(p1->processName,d->coct->processName);
			strcpy(p1->deviceName,d->coct->deviceName);
			if(d->coct->chct->block==NULL)
			{
				d->coct->chct->block=p1;
			
			}
			else
			{
				Process * p;
				for(p=d->coct->chct->block;p->next!=NULL;p=p->next);
				p->next=p1;
			}
			}
		}
	else
	{
		if(d->coct->state==1)
		{
		strcpy(d->coct->chct->processName,d->coct->processName);
		strcpy(d->coct->chct->deviceName,d->coct->deviceName);
		d->coct->chct->state=1;
		}
	
	
	}
}

void delCH(COCT *coct,DCT *c)
{
	for(COCT *ll=coct;ll->next!=NULL;ll=ll->next)
	 {
		 if(strcmp(ll->next->controlName,c->next->coct->controlName)==0)
			 {
				 ll->next=ll->next->next;
				 break;
			 }
	 }
}
void delDevice(Process *process,DCT * dct,COCT * coct,CHCT * chct,char command[DEVICESIZE])
{
	int flag=0;
	DCT *c;//c->next指向要删除的设备
	for(c=dct;c->next!=NULL;c=c->next)
	{
		if(strcmp(c->next->deviceName,command)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"设备"<<command<<"不存在"<<endl;
		return;
	}

	if(c->next->state==1)
	{
		cout<<"设备 "<<command<<" 存在进程 :"<<c->next->processName<<endl;
		cout<<"是否确定删除    Y--是    N--否"<<endl;
		char y;
		cin>>y;
		switch(y)
		{
		case 'Y':
		case 'y':break;
		case 'N':
		case 'n':return;
		default :cout<<"输入错误"<<endl;return;
		}
	}
////////////////////////////////////////////////////////设备控制表   阻塞队列中的进程
	if(c->next->block!=NULL)
	{
		for(Process *temp=c->next->block;temp!=NULL;temp=temp->next)
			for(Process *p=process;p->next!=NULL;p=p->next)
			{
				if(strcmp(p->next->processName,temp->processName)==0)
				{
					p->next=p->next->next;
					break;
				}
			}
	}
///////////////////////////////////////////////////////////////控制器控制表  阻塞队列中和当前设备中进程名相等的进程

	if(c->next->coct->block!=NULL)
	{
		Process *temp;
		for(temp=c->next->coct->block;temp!=NULL;temp=temp->next)
		{
			if(strcmp(temp->processName,c->next->processName)==0)
			{
				break;
			}
		}

		if(c->next->coct->block==temp)
			c->next->coct->block=temp->next;
		else
		{
			for(Process *r=c->next->coct->block;r->next!=NULL;r=r->next)
			{
				if(r->next==temp)
				{
					r->next=temp->next;
					break;
				}
			}
			
		}
	}
////////////////////////////////////////////////////设备链表
	for(Process *p=process;p->next!=NULL;p=p->next)
	{
		if(strcmp(p->next->processName,c->next->processName)==0)
		{
			p->next=p->next->next;
			break;
		}
	}
//////////////////////////////////////////////////////////////////////////////
	if(strcmp(c->next->processName,c->next->coct->processName)==0)
	{
	c->next->coct->state=0;
	int i;
	for(i=0;i<PROCESSNAME;i++)
		c->next->coct->processName[i]='\0';
	for(i=0;i<DEVICESIZE;i++)
		c->next->coct->deviceName[i]='\0';
	}

	if(strcmp(c->next->processName,c->next->coct->chct->processName)==0)
	{
	int i;
	c->next->coct->chct->state=0;
	for(i=0;i<PROCESSNAME;i++)
		c->next->coct->chct->processName[i]='\0';
	for(i=0;i<DEVICESIZE;i++)
		c->next->coct->chct->deviceName[i]='\0';
	}

////////////////////////////////////////////////////////////////////////控制器控制表


	if(c->next->coct->block!=NULL&&c->next->coct->state==0)
	{
		strcpy(c->next->coct->processName,c->next->coct->block->processName);
		strcpy(c->next->coct->deviceName,c->next->coct->block->deviceName);
		c->next->coct->state=1;
		c->next->coct->block=c->next->coct->block->next;
	}
///////////////////////////////////////////////////////////////////////通道控制表
	if(c->next->coct->chct->block!=NULL)
	{
		strcpy(c->next->coct->chct->processName,c->next->coct->chct->block->processName);
		strcpy(c->next->coct->chct->deviceName,c->next->coct->chct->block->deviceName);
		c->next->coct->chct->state=1;
		c->next->coct->chct->block=c->next->coct->chct->block->next;

		if(c->next->coct->state=1)
		{
			Process *p1=(Process *)malloc(sizeof(Process));
			p1=initProcess(p1);//初始化
			strcpy(p1->processName,c->next->coct->processName);
			strcpy(p1->deviceName,c->next->coct->deviceName);
			if(c->next->coct->chct->block==NULL)
			{
				c->next->coct->chct->block=p1;
			
			}
			else
			{
				Process * p;
				for(p=c->next->coct->chct->block;p->next!=NULL;p=p->next);
				p->next=p1;
			}
		}
	}
	else
	{
		if(c->next->coct->state!=0)
		{
		strcpy(c->next->coct->chct->processName,c->next->coct->processName);
		strcpy(c->next->coct->chct->deviceName,c->next->coct->deviceName);
		c->next->coct->chct->state=1;
		}
	}
	flag=0;
	for(DCT *f=dct->next;f!=NULL;f=f->next)
	{
		if(f==c->next)
			continue;
		if(strcmp(f->coct->controlName,c->next->coct->controlName)==0)
		{
			flag=1;
			break;
		}
	}
		
	//cout<<"######################################################################################################"<<flag<<endl;
	if(flag==0)
	{
		cout<<"是否删除通道"<<c->next->coct->controlName<<"    Y --是      N--否"<<endl;
		char x;
loop5:
		cin>>x;
		switch(x)
		{
		case 'Y':
		case 'y':
			delCH(coct,c);
			break;
		case 'n':
		case 'N':break;
		default :cout<<"输入错误  请重新输入"<<endl; goto loop5;
		}
	}
	c->next=c->next->next;	
}

void interface()
{
	cout<<"*************************************************************************"<<endl;
	cout<<"s-申请进程        h-归还进程      c-增加设备    d-删除设备     q-退出    "<<endl;
    cout<<"*************************************************************************"<<endl;
}

void chooseCHCT(CHCT *chct,DCT *temp)
{
	cout<<"请输入要选择的通道名 ch1--1  ch2--2"<<endl;
loop:
	char flag;
	cin>>flag;
	switch(flag)
	{
	case '1':temp->coct->chct=chct->next;break;
	case '2':temp->coct->chct=chct->next->next;break;
	default:cout<<"输入错误"<<endl;goto loop;
	}
}

COCT * chooseCOCT(DCT *dct,COCT *coct,CHCT *chct,DCT *temp)
{
	loop:
			 cout<<"是否新建控制器      Y 是  N  否"<<endl;

			 char flag;
			 cin>>flag;
			if(flag=='Y'||flag=='y')
			{
loop1:
						cout<<"请输入要创建的控制器名"<<endl;
						COCT *c=(COCT *)malloc(sizeof(COCT));
						c=initCOCT(c);
						char name[CONTROLSIZE];
						cin>>name;

						int flag1=0;
						
						for(COCT *f=coct->next;f!=NULL;f=f->next)
						{
							if(strcmp(f->controlName,name)==0)
							{
								flag1=1;
								cout<<f->controlName<<"该控制器名已存在"<<endl;
								break;
							}
						}
						if(flag1==1)
							goto loop1;
						strcpy(c->controlName,name);
						COCT *cc;
						for(cc=coct->next;cc->next!=NULL;cc=cc->next);
						cc->next=c;
						temp->coct=c;
						chooseCHCT(chct,temp);
						return coct;
			}
			else
			if(flag=='N'||flag=='n')
			{
loop2:
				cout<<"请选择控制器名 : ";
					 int count=0;
					 for(COCT *s=coct->next;s!=NULL;s=s->next,count++)
						 cout<<s->controlName<<"--"<<count<<" ";
					 cout<<endl;
					 int i;
					 cin>>i;
					 if(i>=count)
					 {
						 cout<<"输入错误"<<endl;
						 goto loop2;
					 }
					 else
					 {
						 COCT *w=coct->next;
						 for(int j=0;j<i;j++)
							 w=w->next;
						 temp->coct=w;

					 }
			}
			else
			{
				cout<<"输入错误"<<endl;
				goto loop;
			}

			 return coct;
}
void function(Process *process,DCT * dct,COCT * coct,CHCT * chct)
{
    display(process,dct,coct,chct);
	interface();
loop:
	cout<<"请输入命令:"<<endl;
	char *array=new char[length];
	cin.getline(array,100);
	char command[COMMANDNUMBER][PROCESSNAME];//命令数和每个命令的字符数

	for(int  m=0;m<COMMANDNUMBER;m++)//命令数组初始化
		for(int n=0;n<PROCESSNAME;n++)
			command[m][n]='\0';

	int k=0;
	for(int i=0;array[i]!='\0'&&i<length;){
			int result=search(array,i);
			if(result==i){
			i++;	//接连空格
			}else{
				if(k<3)
				{
				for(int j=i,g=0;j<result;j++,g++){
				command[k][g]=array[j];
				}
				}
				i=result;
				k++;
			}
		}
	if(k>3)
	{
		cout<<"输入错误"<<endl;
		return;
	}
	if(command[0][1]!='\0')
	{
		cout<<"指令不合法"<<endl;
		return;
	}
	
	switch(command[0][0])
	{
	case 's':
	case 'S':if(command[1][0]!='\0'&&command[2][0]!='\0')
			 {
				Process * temp=(Process *)malloc(sizeof(Process));
				temp=initProcess(temp);//初始化
				strcpy(temp->deviceName,command[2]);
				strcpy(temp->processName,command[1]);
				addProcess(process,dct,coct,chct,temp);
			 }
			 else
			 {
				 cout<<"没有输入添加进程名或设备名"<<endl;
			 }
		break;
	case 'h':
	case 'H':if(command[1][0]!='\0'&&command[2][0]=='\0')
			 {
				Process * temp=(Process *)malloc(sizeof(Process));
				temp=initProcess(temp);//初始化
				strcpy(temp->processName,command[1]);
				delProcess(process,dct,coct,chct,temp);
			 }
			 if(command[2][0]!='\0')
			 {
				 cout<<"命令格式错误"<<endl; goto loop;
			 }
			 if(command[1][0]=='\0')
			 {
				 cout<<"没有输入要删除的进程名"<<endl;
			 }
			 break;
	case 'c':
	case 'C':if(command[1][0]!='\0'&&command[2][0]=='\0')
			 {
				 int flag=0;
				 for(DCT *g=dct->next;g!=NULL;g=g->next)
				 {
					 if(strcmp(g->deviceName,command[1])==0)
					 {
						 flag=1;
						 break;
					 }
				 }


				 if(flag==0)//重名检查
				 {
					DCT *temp=(DCT *)malloc(sizeof(DCT));
					temp=initDCT(temp);
					strcpy(temp->deviceName,command[1]);
					DCT *d;
					for(d=dct->next;d->next!=NULL;d=d->next);
					d->next=temp;
					coct=chooseCOCT(dct,coct,chct,temp);
				 }
				 else
				 {
					 cout<<"设备"<<command[1]<<"已存在"<<endl;
				 }
				 
			 }
			 else
			 if(command[2][0]!='\0')
			 {
				 cout<<"命令格式错误"<<endl;goto loop;
			 }
			 else
			 {
				 cout<<"没有输入要添加的设备名"<<endl;
			 }
			 break;
	case 'd':
	case 'D':if(command[1][0]!='\0'&&command[2][0]=='\0')
			 {
				 if(strcmp(command[1],"K")==0)
				 {
					 cout<<"K 是系统设备 不能删除"<<endl;
					 goto loop;
				 }
				 if(strcmp(command[1],"M")==0)
				 {
					 cout<<"M 是系统设备 不能删除"<<endl;
					 goto loop;
				 }
				 if(strcmp(command[1],"T")==0)
				 {
					 cout<<"T 是系统设备 不能删除"<<endl;
					 goto loop;
				 }
				 if(strcmp(command[1],"P")==0)
				 {
					 cout<<"P 是系统设备 不能删除"<<endl;
					 goto loop;
				 }
				delDevice(process,dct,coct,chct,command[1]);
			 }
			 else
			 if(command[2][0]!='\0')
			 {
				 cout<<"命令格式错误"<<endl;goto loop;
			 }
			 else
			 {
				 cout<<"没有输入要添加的设备名"<<endl;
			 }break;
	case 'q':
	case 'Q':exit(0);break;
	default:cout<<"输入错误"<<endl;break;

	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	Process *process=(Process *)malloc(sizeof(Process));//进程链
	DCT * dct=(DCT *)malloc(sizeof(DCT));//设备控制链
	COCT * coct=(COCT *)malloc(sizeof(COCT));//控制器控制链
	CHCT * chct=(CHCT *)malloc(sizeof(CHCT));//通道控制链
	////////////////////////////////////////////////
	process=initProcess(process);
	dct=initDCT(dct);
	coct=initCOCT(coct);
	chct=initCHCT(chct);
	init(dct,coct,chct);//初始化

	while(1)
	{
	
	function(process,dct,coct,chct);
	//system("CLS");
	display(process,dct,coct,chct);
	
	}	
	return 0;
}

