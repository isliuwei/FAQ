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
	cout<<"\t资源分配情况\n"<<endl;
	cout<<"\tMax"<<"\t已分配"<<"\tNeed"<<endl;
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
			cout<<"系统不安全"<<endl;
			return -1;
		}
	}
    cout<<"系统是安全的"<<endl;
    cout<<"分配的序列:";
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
	cout<<"输入请求资源的进程："<<endl;
	cin>>flag;
	if (flag>=P)
	{
		cout<<"此进程不存在!"<<endl;
	}
	else
	{
		cout<<"输入此进程对各个资源的请求数量："<<endl;
		for (i=0;i<S;i++)
		{
			cin>>Request[i];
		}
		for (i=0;i<S;i++)
		{
			if (Request[i]>Need[flag][i])
			{
				cout<<"进程"<<flag<<"申请的资源大于它所需要的资源!"<<endl;
				cout<<"分配不合理不予分配!"<<endl;
				ch='N';
				break;
			}
			else if (Request[i]>Available[i])
			{
				cout<<"进程"<<flag<<"申请的资源大于可利用的资源。"<<endl;
				cout<<"分配不合理，不予分配!"<<endl;
				ch='N';
				break;
			}
		}
		if (ch=='Y')
		{
			Changedata(flag);
			if (Judgesafe()==-1)
			{
				cout<<"进程"<<flag<<"申请资源后，系统进入死锁状态，分配失败!"<<endl;
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
    cout<<"\t\t操作系统实验六"<<endl;
    cout<<endl;
    cout<<"输入资源种类："<<endl;
	cin>>s;
	S=s;
	cout<<"输入资源的名称和数量："<<endl;
	for(i=0;i<s;i++)
	{
		cin>>tempstring>>number;
		name[i]=tempstring;
		Available[i]=number;
	}
	cout<<"输入进程的数量："<<endl;
	cin>>p;
	P=p;
	cout<<"输入各进程资源最大需求量："<<endl;
	for (i=0;i<p;i++)
	{
		for (j=0;j<s;j++)
		{
			cin>>Max[i][j];
		}
	}
	cout<<"输入各进程资源已分配量："<<endl;
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
		
     cout<<"是否分配资源："<<endl;
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