 #include<iostream>
using namespace std;

struct PCB
{
	char name[10];
	char eqname[10];
	PCB *next;
};

struct CHCT
{
	char name[10];
	int sign;
	PCB *next_pcb;
	CHCT *next;
};

struct COCT
{
	char name[10];
	int sign;
	COCT *next;
	PCB *next_pcb;	
	CHCT *next_chct;
};

struct DCT
{
	char name[10];
	int sign;
	char type[3];
	DCT *next;
	PCB *next_pcb;
	COCT *next_coct;
};

struct SDT
{
	char name[10];
	char type[3];
	SDT *next;
	DCT *next_dct;
};

SDT *head_sdt;
DCT *head_dct;
COCT *head_coct;
CHCT *head_chct;
PCB *head_i,*head_o;



void init()
{   
	//chct
	CHCT *ch1,*ch2;
	ch1 = (CHCT *)malloc(sizeof(CHCT));
	ch2 = (CHCT *)malloc(sizeof(CHCT));

	strcpy(ch1->name,"CH1");
	strcpy(ch2->name,"CH2");

	ch1->sign = 0;
	ch2->sign = 0;

	head_chct = ch1;
	ch1->next = ch2;
	ch2->next = NULL;

	ch1->next_pcb = NULL;
	ch2->next_pcb = NULL;

	//coct
	COCT *co1,*co2,*co3;
	co1 = (COCT *)malloc(sizeof(COCT));
	co2 = (COCT *)malloc(sizeof(COCT));
	co3 = (COCT *)malloc(sizeof(COCT));

	strcpy(co1->name,"CO1");
	strcpy(co2->name,"CO2");
	strcpy(co3->name,"CO3");

	co1->sign = 0;
	co2->sign = 0;
	co3->sign = 0;

	head_coct = co1;
	co1->next = co2;
	co2->next = co3;
	co3->next = NULL;

	co1->next_pcb = NULL;
	co2->next_pcb = NULL;
	co3->next_pcb = NULL;

	co1->next_chct = ch1;
	co2->next_chct = ch2;
	co3->next_chct = ch2;

	//dct
	DCT *dct1,*dct2,*dct3,*dct4;
	dct1 = (DCT *)malloc(sizeof(DCT));
	dct2 = (DCT *)malloc(sizeof(DCT));
	dct3 = (DCT *)malloc(sizeof(DCT));
	dct4 = (DCT *)malloc(sizeof(DCT));

	strcpy(dct1->name,"K");
	strcpy(dct2->name,"M");
	strcpy(dct3->name,"T");
	strcpy(dct4->name,"P");

	dct1->sign = 0;
	dct2->sign = 0;
	dct3->sign = 0;
	dct4->sign = 0;

	strcpy(dct1->type,"I");
	strcpy(dct2->type,"I");
	strcpy(dct3->type,"O");
	strcpy(dct4->type,"O");

	head_dct = dct1;
	dct1->next = dct2;
	dct2->next = dct3;
	dct3->next = dct4;
	dct4->next = NULL;

	dct1->next_pcb = NULL;
	dct2->next_pcb = NULL;
	dct3->next_pcb = NULL;
	dct4->next_pcb = NULL;

	dct1->next_coct = co1;
	dct2->next_coct = co1;
	dct3->next_coct = co2;
	dct4->next_coct = co3;

	//sdt
	SDT *k,*m,*t,*p;
	k = (SDT *)malloc(sizeof(SDT));
	m = (SDT *)malloc(sizeof(SDT));
	t = (SDT *)malloc(sizeof(SDT));
	p = (SDT *)malloc(sizeof(SDT));

	strcpy(k->name,"K");
	strcpy(m->name,"M");
	strcpy(t->name,"T");
	strcpy(p->name,"P");

	strcpy(k->type,"I");
	strcpy(m->type,"I");
	strcpy(t->type,"O");
	strcpy(p->type,"O");

	head_sdt = k;
	k->next = m;
	m->next = t;
	t->next = p;
	p->next = NULL;

	k->next_dct = dct1;
	m->next_dct = dct2;
	t->next_dct = dct3;
	p->next_dct = dct4;
}

void show()
{
	
	cout<<"\t|--------------------------------------------------------|"<<endl;
	//sdt
	if(head_sdt == NULL)
		cout<<"\t|    ���豸\t\t\t\t\t\t |"<<endl;
	else
	{
		SDT *sdt_p;
		sdt_p = head_sdt;
		while(sdt_p != NULL)
		{
			cout<<"\t|    �豸�� :"<<sdt_p->name<<"  ���� : "<<sdt_p->type<<"  ״̬ : "<<sdt_p->next_dct->sign<<"   ���ӿ�������:"<<sdt_p->next_dct->next_coct->name<<"    |"<<endl;
			sdt_p = sdt_p->next;
		}
		cout<<"\t|\t\t\t\t\t\t\t |"<<endl;
	}

	//coct
	COCT *coct_p;
	coct_p = head_coct;
	while(coct_p != NULL)
	{
		cout<<"\t|    �������� :"<<coct_p->name<<"  ״̬ : "<<coct_p->sign<<"   ����ͨ���� : "<<coct_p->next_chct->name<<"\t\t |"<<endl;
		coct_p = coct_p->next;
	}
	cout<<"\t|\t\t\t\t\t\t\t |"<<endl;

	//chct
	CHCT *chct_p;
	chct_p = head_chct;
	while(chct_p != NULL)
	{
		cout<<"\t|    ͨ���� :"<<chct_p->name<<"   ״̬ : "<<chct_p->sign<<"\t\t\t\t |"<<endl;
		chct_p = chct_p->next;
	}
	cout<<"\t|--------------------------------------------------------|"<<endl;
	cout<<endl;
}

DCT *search_SDT(char *eqname)//����dct
{
	SDT *p;
	p = head_sdt;
	while(p)
	{
		if(strcmp(eqname,p->name) == 0)
			return p->next_dct;
		else
			p = p->next;
	}
	return NULL;
}

int search_COCT(char *co_name)  //�жϿ������Ƿ�����
{
	COCT *p;
	p = head_coct;
	while(p)
	{
		if(strcmp(co_name,p->name) == 0)
			return 0;
		else
			p = p->next;
	}
	return 1;
}

void addeq()  //����豸
{
	char eqname[10];   
	char type[3];      //�豸����
	int temp;          //�жϿ������Ƿ�����

	DCT *s;

	cout<<"  ��������豸������: "<<endl;
	cout<<">";
	cin>>eqname;	
	s = search_SDT(eqname);

	SDT *sdt_s,*sdt_p;
	DCT *dct_s,*dct_p;
	COCT *coct_s,*coct_p;

	if(s == NULL)     //����µĿ�����
	{
		cout<<"  �������豸����'I'�豸����'O'�豸"<<endl;
		cout<<">";
		cin>>type;
		if(strcmp(type,"I") != 0 && strcmp(type,"O") != 0)
		{
		
			cout<<"�豸�����������!"<<endl;
			return;
		}

		COCT *p;
		char dcname[10],chname[10];
		
		cout<<"  �����豸������������"<<endl;
		cout<<">";
		cin>>dcname;
		temp = search_COCT(dcname);

		if(temp == 1)
		{			
			CHCT *p;
			p = head_chct;

			cout<<"  ����ͨ��:  ";
			while(p)       //�����ǰ����ͨ��
			{
				cout<<p->name<<"\t";
				p = p->next;
			}
			cout<<endl;

			cout<<"  �������豸������Ҫ���ӵ�ͨ��������"<<endl;
			cout<<">";
			cin>>chname;

			p = head_chct;
			while(p)
			{
				if(strcmp(p->name,chname) == 0)
					break;
				else
					p = p->next;
			}
			if(p == NULL)
			{
				
				cout<<"����ͨ������"<<endl;
				return;
			}

			//COCT
			coct_s = (COCT *)malloc(sizeof(COCT));    //��ʼ���µĿ�����
			coct_s->next_chct = p;
			coct_s->next_pcb = NULL;
			coct_s->sign = 0;
			strcpy(coct_s->name,dcname);

			coct_p = head_coct;
			if(coct_p == NULL)
			{
				head_coct = coct_s;
				head_coct->next = NULL;
			}
			else
			{
				while(coct_p->next != NULL)
					coct_p = coct_p->next;
				coct_p->next = coct_s;
				coct_s->next = NULL;
			}		
		}
		else     			//������µ��豸������
		{
			p = head_coct;
			while(p)
			{
				if(strcmp(p->name,dcname) == 0)
					break;
				else
					p = p->next;
			}
			coct_s = p;
		}

		//�����豸�ĸ���ܽ�������

		//DCT
		dct_s = new DCT;                  //��ʼ��DCT
		dct_s->next_pcb = NULL;
		dct_s->next_coct = coct_s;
		dct_s->sign = 0;
		strcpy(dct_s->type,type);
		strcpy(dct_s->name,eqname);

		dct_p = head_dct;
		if(dct_p == NULL)
		{
			head_dct = dct_s;
			head_dct->next = NULL;
		}
		else
		{
			while(dct_p->next != NULL)
				dct_p = dct_p->next;
			dct_p->next = dct_s;
			dct_s->next = NULL;
		}
		
		//SDT
		sdt_s = new SDT;
		sdt_s->next_dct = dct_s;
		strcpy(sdt_s->type,type);
		strcpy(sdt_s->name,eqname);

		sdt_p = head_sdt;
		if(sdt_p == NULL)
		{
			head_sdt = sdt_s;
			head_sdt->next = NULL;
		}
		else
		{
			while(sdt_p->next != NULL)
				sdt_p = sdt_p->next;
			sdt_p->next = sdt_s;
			sdt_s->next = NULL;
		}
		
		cout<<"����豸�ɹ�"<<endl;
	}
	else
	{
		
		cout<<"���豸�Ѿ�����"<<endl;
	}

}

void deleq()  //ɾ���豸
{
	char eqname[10];

	cout<<"  ����ɾ���豸������: "<<endl;
	cout<<">";
	cin>>eqname;
	
	DCT *s;
	s = search_SDT(eqname);
	
	if(s != NULL)
	{		
		if(s->sign == 1)
		{
			
			cout<<"����ʹ�õ��豸����ɾ��"<<endl;
			return;
		}
		COCT *coct_temp;
		DCT *dct_temp;
		SDT *sdt_temp;
		
		sdt_temp = head_sdt;
		coct_temp = s->next_coct;
		
		//��sdt��ɾ���豸
		if(s == head_sdt->next_dct)
			head_sdt = head_sdt->next;
		else
		{
			while(sdt_temp->next->next_dct != s)
				sdt_temp = sdt_temp->next;
			sdt_temp->next = sdt_temp->next->next;
		}
		
		//��dct��ɾ��
		dct_temp = head_dct;
		if(s == head_dct)
			head_dct = head_dct->next;
		else
		{
			while(dct_temp->next != s)
				dct_temp = dct_temp->next;
			dct_temp->next = dct_temp->next->next;
		}

		//����co
		sdt_temp = head_sdt;
		while(sdt_temp)
		{
			if(sdt_temp->next_dct->next_coct == s->next_coct)
				break;
			else
				sdt_temp = sdt_temp->next;
		}
		if(sdt_temp == NULL)
		{
			//���豸��������coct��ɾ��
			coct_temp = head_coct;
			if(head_coct == s->next_coct)
				head_coct = head_coct->next;
			else
			{
				while(coct_temp->next != s->next_coct)
					coct_temp = coct_temp->next;
				coct_temp->next = coct_temp->next->next;
			}
		}
		cout<<"�豸ɾ���ɹ�"<<endl;
	}
	else
	{
	
		cout<<"���豸������,����ɾ��"<<endl;
	}
}

void insertPCB(PCB *head,char *pcb_name,char *pcb_eqname)   //������Ӧ����������
{
	PCB *p;
	p = head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	p->next = (PCB *)malloc(sizeof(PCB));
	strcpy(p->next->name,pcb_name);
	strcpy(p->next->eqname,pcb_eqname);
	p->next->next = NULL;
}

void appeq(char pcbname[10],char eqname[10])  //�����豸
{
	DCT *s;
	s = search_SDT(eqname);
	if(s == NULL)
	{
	
		cout<<"��������豸"<<endl;
		return;
	}
	if(s->sign == 0)
	{
		s->sign = 1;
		if(s->next_coct->sign == 0)
		{
			s->next_coct->sign = 1;
			if(s->next_coct->next_chct->sign == 0)
			{
				s->next_coct->next_chct->sign = 1;
				
				cout<<"����"<<pcbname<<"�ɹ�����豸: "<<eqname<<endl;
			}
			else    //����ͨ����������
			{
			
				cout<<"����"<<pcbname<<"����豸"<<eqname<<"��������"<<s->next_coct->next_chct->name<<"����"<<endl;
				if(s->next_coct->next_chct->next_pcb != NULL)
					insertPCB(s->next_coct->next_chct->next_pcb,pcbname,eqname);
				else
				{
					s->next_coct->next_chct->next_pcb = (PCB *)malloc(sizeof(PCB));
					strcpy(s->next_coct->next_chct->next_pcb->name,pcbname);
					strcpy(s->next_coct->next_chct->next_pcb->eqname,eqname);
					s->next_coct->next_chct->next_pcb->next = NULL;
				}
			}
		}
		else     //�����������������
		{
		
			cout<<"����"<<pcbname<<"����豸"<<eqname<<"��������"<<s->next_coct->name<<"����"<<endl;			
			if(s->next_coct->next_pcb != NULL)
				insertPCB(s->next_coct->next_pcb,pcbname,eqname);
			else
			{
				s->next_coct->next_pcb = (PCB *)malloc(sizeof(PCB));
				strcpy(s->next_coct->next_pcb->name,pcbname);
				strcpy(s->next_coct->next_pcb->eqname,eqname);
				s->next_coct->next_pcb->next = NULL;
			}
		}
	}
	else   //�����豸��������
	{
	
		cout<<"����"<<pcbname<<"��������"<<s->name<<"����"<<endl;		
		if(s->next_pcb != NULL)
			insertPCB(s->next_pcb,pcbname,eqname);
		else
		{
			s->next_pcb = (PCB *)malloc(sizeof(PCB));
			strcpy(s->next_pcb->name,pcbname);
			strcpy(s->next_pcb->eqname,eqname);
			s->next_pcb->next = NULL;
		}
	}	
}

void releq()  //�黹�豸
{
	char dname[10];
	
	cout<<"  ������Ҫ�黹�豸������: "<<endl;
	cout<<">";
	cin>>dname;

	DCT *s;
	s = search_SDT(dname);

	if(s != NULL && s->sign == 1)
	{
		
		cout<<dname<<"�豸�Ѿ����黹"<<endl;

		s->next_coct->next_chct->sign = 0;    //�޸�״̬λ
		s->next_coct->sign = 0;
		s->sign = 0;

		if(s->next_coct->next_chct->next_pcb != NULL)    //ͨ���µ���������
		{
			s->next_coct->next_chct->sign = 1;
		
			cout<<"����"<<s->next_coct->next_chct->next_pcb->name<<"�ɹ�����豸: "<<s->next_coct->next_chct->next_pcb->eqname<<endl;

			//�޸Ŀ��������豸��״̬
			SDT *sdt_p = head_sdt;
			while(sdt_p)
			{
				if(strcmp(sdt_p->name,s->next_coct->next_chct->next_pcb->eqname) == 0)
				{
					sdt_p->next_dct->sign = 1;
					sdt_p->next_dct->next_coct->sign = 1;
					sdt_p->next_dct->next_coct->next_chct->sign = 1;
					break;
				}
				else
				{
					sdt_p = sdt_p->next;
				}
			}
			s->next_coct->next_chct->next_pcb = s->next_coct->next_chct->next_pcb->next;
		}

		if(s->next_coct->next_pcb != NULL)       //�������µ���������
		{
			s->next_coct->sign = 1;
			if(s->next_coct->next_chct->sign == 0)
			{
				s->next_coct->next_chct->sign = 1;
			
				cout<<"����"<<s->next_coct->next_pcb->name<<"�ɹ�����豸: "<<s->next_coct->next_pcb->eqname<<endl;
				SDT *sdt_p = head_sdt;
				while(sdt_p)
				{
					if(strcmp(sdt_p->name,s->next_coct->next_pcb->eqname) == 0)
					{
						sdt_p->next_dct->sign = 1;
						sdt_p->next_dct->next_coct->sign = 1;
						sdt_p->next_dct->next_coct->next_chct->sign = 1;
						break;
					}
					else
					{
						sdt_p = sdt_p->next;
					}
				}
			}
			else
			{
			
				cout<<"����"<<s->next_coct->next_pcb->name<<"����豸"<<s->next_coct->next_pcb->eqname<<"��������"<<s->next_coct->next_chct->name<<"����"<<endl;
				//������������
				if(s->next_coct->next_chct->next_pcb != NULL)
					insertPCB(s->next_coct->next_chct->next_pcb,s->next_coct->next_pcb->name,s->next_coct->next_pcb->eqname);
				else
				{
					s->next_coct->next_chct->next_pcb = (PCB *)malloc(sizeof(PCB));
					strcpy(s->next_coct->next_chct->next_pcb->name,s->next_coct->next_pcb->name);
					strcpy(s->next_coct->next_chct->next_pcb->eqname,s->next_coct->next_pcb->eqname);
					s->next_coct->next_chct->next_pcb->next = NULL;
				}
				SDT *sdt_p = head_sdt;
				while(sdt_p)
				{
					if(strcmp(sdt_p->name,s->next_coct->next_pcb->eqname) == 0)
					{
						sdt_p->next_dct->sign = 1;
						sdt_p->next_dct->next_coct->sign = 1;
						sdt_p->next_dct->next_coct->next_chct->sign = 1;
						break;
					}
					else
						sdt_p = sdt_p->next;
				}
			}
			s->next_coct->next_pcb = s->next_coct->next_pcb->next;
		}
		if(s->next_pcb != NULL)
		{
			s->sign = 1;
			if(s->next_coct->sign == 0)
			{
				s->next_coct->sign = 1;
				if(s->next_coct->next_chct->sign == 0)
				{
					s->next_coct->next_chct->sign = 1;
				
					cout<<"����"<<s->next_pcb->name<<"�ɹ�����豸: "<<s->next_pcb->eqname<<endl;
				}
				else
				{
				
					cout<<"����"<<s->next_pcb->name<<"����豸"<<s->next_pcb->eqname<<"��������"<<s->next_coct->next_chct->name<<"����"<<endl;
					//������������
					if(s->next_coct->next_pcb != NULL)
						insertPCB(s->next_coct->next_chct->next_pcb,s->next_pcb->name,s->next_pcb->eqname);
					else
					{
						s->next_coct->next_pcb = new PCB;
						strcpy(s->next_coct->next_chct->next_pcb->name,s->next_pcb->name);
						strcpy(s->next_coct->next_chct->next_pcb->eqname,s->next_pcb->eqname);
						s->next_coct->next_pcb->next = NULL;
					}
				}
			}
			else
			{
				
				cout<<"����"<<s->next_pcb->name<<"����豸"<<s->next_pcb->eqname<<"��������"<<s->next_coct->name<<"����"<<endl;
				//������������
				if(s->next_coct->next_pcb != NULL)
					insertPCB(s->next_coct->next_pcb,s->next_pcb->name,s->next_pcb->eqname);
				else
				{
					s->next_coct->next_pcb = new PCB;
					strcpy(s->next_coct->next_pcb->name,s->next_pcb->name);
					strcpy(s->next_coct->next_pcb->eqname,s->next_pcb->eqname);
					s->next_coct->next_pcb->next = NULL;
				}
			}
			SDT *sdt_p = head_sdt;
			while(sdt_p)
			{
				if(strcmp(sdt_p->name,s->next_pcb->eqname) == 0)
				{
					sdt_p->next_dct->sign = 1;
					sdt_p->next_dct->next_coct->sign = 1;
					sdt_p->next_dct->next_coct->next_chct->sign = 1;
					break;
				}
				else
					sdt_p = sdt_p->next;
			}
			s->next_pcb = s->next_pcb->next;
		}
		if(strcmp(s->type,"I") == 0 && head_i != NULL && s->sign == 0)
		{
			appeq(head_i->name,dname);
			head_i = head_i->next;
		}
		if(strcmp(s->type,"O") == 0  && head_o != NULL && s->sign == 0)
		{
			appeq(head_o->name,dname);
			head_o = head_o->next;
		}
	}
	else if(s != NULL && s->sign == 0)
	{
		
		cout<<dname<<"�豸���������ͷ�"<<endl;
	}
	else
	{
	
		cout<<"û����Ϊ"<<dname<<"���豸�����ͷ�"<<endl;
	}
}

int main()
{
	head_sdt = (SDT *)malloc(sizeof(SDT));
	head_dct = (DCT *)malloc(sizeof(DCT));
	head_coct = (COCT *)malloc(sizeof(COCT));
	head_chct = (CHCT *)malloc(sizeof(CHCT));

	init();
	show();
	char ch;
	cout<<"  ����豸A, ɾ���豸D, �����豸S, �ͷ��豸R, �˳�#"<<endl<<endl;
	cout<<">";
	while(cin>>ch && ch != '#')
	{
		switch(ch)
		{
		case 'a':
		case 'A': addeq();
			break;
		case 'd':
		case 'D': deleq();
			break;
		case 's':
		case 'S': 
			{
				char pcbname[10];
				char eqname[10];

				cout<<"  ���������"<<endl;
				cout<<">";
				cin>>pcbname;

				cout<<"  ���������豸��:"<<endl;
				cout<<">";
				cin>>eqname;

				appeq(pcbname,eqname);
				break;
			}
		case 'r':
		case 'R': releq();
			break;
		default: {
				
					cout<<endl<<"  �����������������."<<endl;
				 }
		}
		cout<<endl;
		show();
		cout<<"  ����豸A��ɾ���豸D�������豸S���黹�豸R���˳�#"<<endl<<endl;
		cout<<">";
	}
	return 0;	
}
