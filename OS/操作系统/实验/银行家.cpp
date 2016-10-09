#include <iostream>
using namespace std;
#define False 0
#define True 1
int Max[100][100]={0};
int Allocation[100][100]={0};
int Need[100][100]={0};
int Available[100]={0};
int Work[100]={0};
char name[100]={0};
int temp[100]={0};
int S=100,P=100;
int safequeue[100]={0};
int Request[100]={0};
//
void Showdata()
{
	int i,j,k,l;
	cout<<"\t��Դ�������\n"<<endl;
	cout<<"\tMax"<<"\t�ѷ���"<<"\tNeed"<<endl;
	cout<<"\t";
	for(j=0;j<3;j++)
	{
		for (i=0;i<S;i++)
		{
			cout<<name[i]<<" ";
		}
		cout<<"\t";
	}
	cout<<endl;
	for(i=0;i<P;i++)
	{
		cout<<i<<"\t";
		for (j=0;j<S;j++)
		{
			cout<<Max[i][j]<<" ";
		}
		cout<<"\t";
		for (k=0;k<S;k++)
		{
			cout<<Allocation[i][k]<<" ";
		}
		cout<<"\t";
		for (l=0;l<S;l++)
		{
			cout<<Need[i][l]<<" ";
		}
		cout<<endl;
	}
	cout<<"\nAvailable"<<endl;
	for (i=0;i<S;i++)
	{
		cout<<name[i]<<" ";
	}
	cout<<endl;
	for (i=0;i<S;i++)
	{
		cout<<Available[i]<<" ";
	}
	cout<<endl;
}

int Judgesafe()
{
	int tempwork[100][100]={0};
	int i,x,k=0,m,apply,Finish[100]={0};
	int j;
	int flag=0;
	for (i=0;i<S;i++)
	{
		Work[i]=Available[i];
	}
	for(i=0;i<P;i++)
	{ 
		apply=0;
		for(j=0;j<S;j++)
		{
			if (Finish[i]==False&&Need[i][j]<=Work[j])
			{   
				apply++;
				if(apply==S)
				{
					for(m=0;m<S;m++)
					{
						tempwork[i][m]=Work[m];
						Work[m]=Work[m]+Allocation[i][m];
					}
					Finish[i]=True;
					temp[k]=i;
					i=-1; 
					k++;
					flag++;
				}
			}
		}
	}
	for(i=0;i<P;i++)
	{
		if(Finish[i]==False)
		{
			cout<<"ϵͳ����ȫ"<<endl;
			return -1;
		}
	}
    cout<<"ϵͳ�ǰ�ȫ��"<<endl;
    cout<<"���������:";
	for(i=0;i<P;i++)
	{
		cout<<temp[i];
		if(i<P-1) cout<<"->";
	}
	cout<<endl;
    return 0;
}

void Changedata(int flag)
{
	for (int i=0;i<S;i++)
	{
		Available[i]=Available[i]-Request[i];
		Allocation[flag][i]=Allocation[flag][i]+Request[i];
		Need[flag][i]=Need[flag][i]-Request[i];
	}
}
//
void Share()
{
	int i,flag;
	char ch='Y';
	cout<<"����������Դ�Ľ��̣�"<<endl;
	cin>>flag;
	if (flag>=P)
	{
		cout<<"�˽��̲�����!"<<endl;
	}
	else
	{
		cout<<"����˽��̶Ը�����Դ������������"<<endl;
		for (i=0;i<S;i++)
		{
			cin>>Request[i];
		}
		for (i=0;i<S;i++)
		{
			if (Request[i]>Need[flag][i])
			{
				cout<<"����"<<flag<<"�������Դ����������Ҫ����Դ!"<<endl;
				cout<<"���䲻���������!"<<endl;
				ch='N';
				break;
			}
			else if (Request[i]>Available[i])
			{
				cout<<"����"<<flag<<"�������Դ���ڿ����õ���Դ��"<<endl;
				cout<<"���䲻�����������!"<<endl;
				ch='N';
				break;
			}
		}
		if (ch=='Y')
		{
			Changedata(flag);
			if (Judgesafe()==-1)
			{
				cout<<"����"<<flag<<"������Դ��ϵͳ��������״̬������ʧ��!"<<endl;
				for (int i=0;i<S;i++)
				{
					Available[i]=Available[i]+Request[i];
					Allocation[flag][i]=Allocation[flag][i]-Request[i];
					Need[flag][i]=Need[flag][i]+Request[i];
				}
			}
			else
			{
				//////////////////////////
			}
		}
	}
}




int main()
{
	int i,j,p,s,number;
	char choice,tempstring;
    cout<<"\t\t����ϵͳʵ����"<<endl;
    cout<<endl;
    cout<<"������Դ���ࣺ"<<endl;
	cin>>s;
	S=s;
	cout<<"������Դ�����ƺ�������"<<endl;
	for(i=0;i<s;i++)
	{
		cin>>tempstring>>number;
		name[i]=tempstring;
		Available[i]=number;
	}
	cout<<"������̵�������"<<endl;
	cin>>p;
	P=p;
	cout<<"�����������Դ�����������"<<endl;
	for (i=0;i<p;i++)
	{
		for (j=0;j<s;j++)
		{
			cin>>Max[i][j];
		}
	}
	cout<<"�����������Դ�ѷ�������"<<endl;
	for (i=0;i<p;i++)
	{
		for (j=0;j<s;j++)
		{
			cin>>Allocation[i][j];
			Available[j]=Available[j]-Allocation[i][j];
		}
	}
	for (i=0;i<p;i++)
	{
		for (j=0;j<s;j++)
		{
			Need[i][j]=Max[i][j]-Allocation[i][j];
		}
	}
	Showdata();
	Judgesafe();	
	while (true)
	{
		
     cout<<"�Ƿ������Դ��"<<endl;
		cin>>choice;
		switch (choice)
		{
		case 'n':
			exit(0);
		default:
			Share();
			break;
		}
		Showdata();
		Judgesafe();
	}
	return 0;
}