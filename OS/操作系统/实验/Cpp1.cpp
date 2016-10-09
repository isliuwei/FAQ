#include<iostream>
#include<cstring>
using namespace std;
typedef struct mulu
{
	char name[10];
	char fu[10];
	int big;
	int star;
	struct mulu *next;
	int lx;
}mulu,*lin;
typedef struct link
{
	struct mulu *rear,*head;
}link1,*list;
int fat[256];
int wei[16][16]={
	{0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
	{0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},	
};
//===========================================================
void fenpei(lin &l)
{
	int i=0,j=0;
	int k=0,p;
	k=l->big;
	for(i=0;i<16;i++)
		for(j=0;j<16;j++)
		{
			if(k==l->big&&wei[i][j]==0)
			{
				l->star=(i+1)*16+j;
				wei[i][j]=1;
				p=(i+1)*16+j;
				k--;
				break;
			}
			
		}
		for(;i<16;i++)
			for(;j<16;j++)
			{
				if(wei[i][j]==0)
				{
					wei[i][j]=1;
					fat[p]=(i+1)*16+j;
					p=(i+1)*16+j;
					k--;
				}
				if(k==0)
				{ 
					fat[p]=2;
					return;
				}
			}
			
}
//===========================================================

void duichushihua(list &l)
{
	l->head=new mulu;
	l->rear=new mulu;
	l->head->next=NULL;
	l->rear=l->head;
}

//==============================================================

bool empty(list &l)
{
	if(l->head==l->rear)return false;
	else return true;
}

//=============================================================
void chudui(list &l)
{
	lin k;
	k=new mulu;
	k=l->head;
	while(k->next->next!=NULL)
	{
		k=k->next;
	}
	free(l->rear);
	l->rear=k;
	l->rear->next=NULL;	
}
void jindui(list &l,lin &e)
{
	if(empty(l))
	{
		e->next=l->head->next;
		l->head->next=e;
	}
	else
	{
		l->head->next=e;
		l->rear=e;
	}
}

//============================================================
void md(lin &l,list &l1,char b[])
{
	mulu *a;
	a=new mulu;
	a->next=NULL;
	a->lx=0;
	strcpy(a->name,b);
	strcpy(a->fu,l->name);
	jindui(l1,a);
	
}
//======================================
void cd(lin &l,list &l1,char b[])
{
	mulu *a;
	a=new mulu;
	a=l1->head->next;
	while(strcmp(a->name,b)!=0&&a!=NULL)
	{
		a=a->next;
	}
	if(a==NULL)
	{
		cout<<"该目录不存在"<<endl;
		return;
	}
	l=a;
}

//================================
void dir(lin &l,list &l1)
{
	mulu *a;
	int m=0;
	int n=0;
	a=new mulu;
	a=l1->head->next;
	while(a!=NULL)
	{
		if(strcmp(a->fu,l->name)==0&&a->lx==0)
		{
			cout<<a->name<<endl;
			m++;
		}
		if(strcmp(a->fu,l->name)==0&&a->lx==1)
		{
			cout<<a->name<<"    "<<a->big<<"个字节"<<endl;
n++;
		}
		a=a->next;
	}
		cout<<"有"<<m<<"个目录，"<<"有"<<n<<"个文件。"<<endl;
}
//=========================================
void xiechu(char a[],char b[],char c[])
{
	int i=0,j=0;
	while(a[i]!=' '&&a[i]!='\0')
	{
		b[i]=a[i];
		i++;
	}
	if(a[i]=='\0')
		return;
	b[i]='\0';
	i++;
	while(a[i]!='\0')
	{
		c[j]=a[i];
		j++;
		i++;
	}
	c[j]='\0';
}
//======================================
void mk(lin &l,list &l1,char b[])
{
	mulu *a;
	a=new mulu;
	a->next=NULL;
	a->lx=1;
	cout<<"请输入文件大小/K"<<endl;
	cin>>a->big;
	getchar();
	strcpy(a->name,b);
	strcpy(a->fu,l->name);
	jindui(l1,a);
	
}
//======================================
void rd(list &l1,char a[])
{
	mulu *k,*q;
	k=new mulu;
	q=new mulu;
	q=l1->head;
	k=l1->head->next;
	while(strcmp(k->name,a)!=0&&k!=NULL)
	{   
		q=q->next;
		k=k->next;
	}
	if(k==NULL)
	{
		cout<<"该目录不存在"<<endl;
		return;
	}
	mulu *p;
	p=new mulu;
	
	p=l1->head->next;
	while(p!=NULL)
	{
		if(strcmp(p->fu,a)==0)
			break;
		p=p->next;
		
	}
	if(p==NULL)
	{
		q->next=k->next;
		free(k);
	}
	else 
		cout<<"该目录不为空"<<endl;
	
}
//==============================
void del(list &l1,char a[])
{
	mulu *k,*q;
	k=new mulu;
	q=new mulu;
	q=l1->head;
	k=l1->head->next;
	while(strcmp(k->name,a)!=0&&k!=NULL)
	{   
		q=q->next;
		k=k->next;
	}
	if(k==NULL)
	{
		cout<<"该文件不存在"<<endl;
		return;
	}  
	q->next=k->next;
	free(k);
}
//============================================
void tree(lin &l,list &l1,int &k)
{
	int i=0;
	if(strcmp(l->name,"ml")==0)
	{
		cout<<l->name<<endl;
	}
	mulu *a;
	a=new mulu;
	a=l1->head->next;
	
	while(a!=NULL)
	{
		if(strcmp(a->fu,l->name)==0&&a->lx==0)
		{   
			
			for(i=0;i<k;i++)
			{   
			
					cout<<"|       ";
			}
			cout<<'|'<<endl;
		
			for(i=0;i<k;i++)
			{
				
					cout<<"|       ";
			}
			cout<<'|'<<endl;
		
			for(i=0;i<k;i++)
			{  
			
					cout<<"|       ";
			}
			cout<<"|----->"<<a->name<<endl;
			k++;
			tree(a,l1,k);
			k--;
		}
		if(strcmp(a->fu,l->name)==0&&a->lx==1)
		{	
			for(i=0;i<k;i++)
			{   
			
					cout<<"|       ";
			}
			cout<<'|'<<endl;
			for(i=0;i<k;i++)
			{
			
					cout<<"|       ";
			}
			cout<<'|'<<endl;
			for(i=0;i<k;i++)
			{  
			
					cout<<"|       ";
			}
			cout<<"|----->"<<a->name<<"    "<<a->big<<"个字节"<<endl;
			
		}
		a=a->next;
	}


}
//=================================

bool pipei1(char a[],char b[])
{
	int k,i=0;
	k=strlen(a);
	i=strlen(b);
	while(i!=0)
	{
		if(a[k-1]==b[i-1])
		{
			i--;
			k--;
		}
		else
			break;
	}
	if(i==0)return true;
	else return false;
}
bool pipei2(char a[],char b[])
{
	int k,i,j=0;
	k=strlen(a);
	i=strlen(b);
	while(j!=i)
	{
		if(a[j]==b[j])
		{
			j++;
		}
		else break;
	}
	if(j==i)return true;
	else return false;
}

//================================
void di(lin &l,list &l1,char g[])
{
	char q[10];
	int k,i=0;
	int m=0,n=0;
	k=strlen(g);
	if(g[0]=='*'&&g[k-1]!='*')
	{
		i=1;
		while(i<k)
		{
			q[i-1]=g[i];
			i++;
		}
		q[i-1]='\0';
		mulu *a;
		a=new mulu;
		a=l1->head->next;
		while(a!=NULL)
		{
			if(strcmp(a->fu,l->name)==0&&a->lx==0&&pipei1(a->name,q))
			{
				cout<<a->name<<endl;
				m++;
			}
			if(strcmp(a->fu,l->name)==0&&a->lx==1&&pipei1(a->name,q))
			{
				cout<<a->name<<"    "<<a->big<<"个字节"<<endl;
				n++;
			}
			a=a->next;
		}
		cout<<"有"<<m<<"个目录，"<<"有"<<n<<"个文件。"<<endl;
	}
	if(g[0]!='*'&&g[k-1]=='*')
	{
		
		
		i=0;
		while(i<k-1)
		{
			q[i]=g[i];
			i++;
		}
		q[i-1]='\0';
		mulu *a;
		a=new mulu;
		a=l1->head->next;
		while(a!=NULL)
		{
			if(strcmp(a->fu,l->name)==0&&a->lx==0&&pipei2(a->name,q))
				cout<<a->name<<endl;
			if(strcmp(a->fu,l->name)==0&&a->lx==1&&pipei1(a->name,q))
				cout<<a->name<<"    "<<a->big<<"个字节"<<endl;
			a=a->next;
		}
		cout<<"有"<<m<<"个目录，"<<"有"<<n<<"个文件。"<<endl;
	}
	
}
//================================
int main()
{   
	int k=0;
	char t[100];
	char b[10];
	char c[10];
	int i=0;
	mulu *a,*e;
	a=new mulu;
	e=new mulu;
	strcpy(a->name,"ml");
	e=a;
	e->next=NULL;
	a->next=NULL;
	
	link *l;
	l=new link;
	duichushihua(l);
	jindui(l,a);
	while(1)
	{
		gets(t);
		xiechu(t,b,c);
		if(strcmp(b,"md")==0)md(a,l,c);
		if(strcmp(b,"cd")==0)cd(a,l,c);
		if(strcmp(t,"dir")==0)dir(a,l);
		if(strcmp(b,"dir")==0)di(a,l,c);
		if(strcmp(b,"rd")==0)rd(l,c);
		if(strcmp(b,"mk")==0)mk(a,l,c);
		if(strcmp(b,"del")==0)del(l,c);
		if(strcmp(t,"tree")==0)tree(e,l,k);
		
	}
	return 0;
}