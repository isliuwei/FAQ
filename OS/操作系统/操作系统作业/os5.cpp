#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<IOMANIP>
using namespace std;

int A[5]={7,3,9,2,4};
int B[5]={5,2,0,2,3};
int C[5]={3,2,2,2,3};
int Avail[3]={3,3,2};
int A_alloction[5]={0,2,3,2,0};
int B_alloction[5]={1,0,0,1,0};
int C_alloction[5]={0,0,2,1,2};
int A_need[5]={7,1,6,0,4};
int B_need[5]={4,2,0,1,3};
int C_need[5]={3,2,0,1,1};
int priority[100]={-1};
int flag[100]={0};//ֻҪ����С�걻��һ��������ռ��
int Flag[5]={0};

void bankeruser()
{
	string c1;
	int n=0,i=0,j=0;
	string c2;
	int num1,num2,num3;
	cout<<"������:";
	cin>>c1;
	cout<<"��Դ����:";
	cin>>num1>>num2>>num3;
	if(c1=="p0")
	{
			if(Avail[0]<num1||Avail[1]<num2||Avail[2]<num3||A_need[0]<num1||B_need[0]<num2||C_need[0]<num3)
				cout<<"��ǰ��Դ�������������������"<<endl;
			else
			{
				if(num1==0&&num2==2&&num3==0)
				{	cout<<"��ǰϵͳ����ȫ��"<<endl;
				return;
				}
				Avail[0]-=num1;
				A_need[0]-=num1;
				A_alloction[0]+=num1;

				Avail[1]-=num2;
				B_need[0]-=num2;
				B_alloction[0]+=num2;

				Avail[2]-=num3;
				C_need[0]-=num3;
				C_alloction[0]+=num3;
				
				if(A_need[0]==0&&B_need[0]==0&&C_need[0]==0)
				{	Flag[0]=1;
					Avail[0]+=A_alloction[0];
					Avail[1]+=B_alloction[0];
					Avail[2]+=C_alloction[0];
					n++;
				}
				while(n<5)
				{
					if(Flag[i]==0&&A_need[i]<=Avail[0]&&B_need[i]<=Avail[1]&&C_need[i]<=Avail[2])
					{
						Flag[i]=1;
						Avail[0]+=A_alloction[i];
						Avail[1]+=B_alloction[i];
						Avail[2]+=C_alloction[i];
						cout<<"p"<<i<<"  ";
						cout<<"������Դ��:"<<Avail[0]<<" "<<Avail[1]<<" "<<Avail[2]<<endl;
						n++;
					
					}
					j++;
					i++;
					if(i>=5)
						i=i%5;
					if(j==200)
					{	
						cout<<"ϵͳ���벻��ȫ״̬��"<<endl;
						break;
					}
				}
					if(n==5)
					cout<<"��ǰϵͳ״̬��ȫ"<<endl;
			}
	}
	if(c1=="p1")
	{
	//	cout<<A_need[1]<<B_need[1]<<C_need[1]<<endl;;
		if(Avail[0]<num1||Avail[1]<num2||Avail[2]<num3||A_need[1]<num1||B_need[1]<num2||C_need[1]<num3)
		{
			cout<<"��ǰ��Դ�������������������"<<endl;
		}
		else
		{
			Avail[0]-=num1;
			A_need[1]-=num1;
			A_alloction[1]+=num1;

			Avail[1]-=num2;
			B_need[1]-=num2;
			B_alloction[1]+=num2;

			Avail[2]-=num3;
			C_need[1]-=num3;
			C_alloction[1]+=num3;
			if(A_need[1]==0&&B_need[1]==0&&C_need[1]==0)
			{
				Flag[1]=1;
				Avail[0]+=A_alloction[1];
				Avail[1]+=B_alloction[1];
				Avail[2]+=C_alloction[1];
				n++;
			}
			while(n<5)
			{
				if(Flag[i]==0&&A_need[i]<=Avail[0]&&B_need[i]<=Avail[1]&&C_need[i]<=Avail[2])
				{
					Flag[i]=1;
					Avail[0]+=A_alloction[i];
					Avail[1]+=B_alloction[i];
					Avail[2]+=C_alloction[i];
					cout<<"p"<<i<<"  ";
					cout<<"������Դ��:"<<Avail[0]<<" "<<Avail[1]<<" "<<Avail[2]<<endl;
					n++;
				
				}
				j++;
				i++;
				if(i>=5)
					i=i%5;
				if(j==500)
				{	
					cout<<"ϵͳ���벻��ȫ״̬��"<<endl;
					break;
				}
			}
				if(n==5)
				cout<<"��ǰϵͳ״̬��ȫ"<<endl;
		}
	}
	if(c1=="p2")
	{
		if(Avail[0]<num1||Avail[1]<num2||Avail[2]<num3||A_need[2]<num1||B_need[2]<num2||C_need[2]<num3)
		{	
			cout<<"��ǰ��Դ�������������������"<<endl;
		}
		else
		{
				Avail[0]-=num1;
				A_need[2]-=num1;
				A_alloction[2]+=num1;

				Avail[1]-=num2;
				B_need[2]-=num2;
				B_alloction[2]+=num2;

				Avail[2]-=num3;
				C_need[2]-=num3;
				C_alloction[2]+=num3;

				if(A_need[2]==0&&B_need[2]==0&&C_need[2]==0)
				{	Flag[2]=1;
				Avail[0]+=A_alloction[2];
				Avail[1]+=B_alloction[2];
				Avail[2]+=C_alloction[2];
				n++;
				}

				while(n<5)
				{
					if(Flag[i]==0&&A_need[i]<=Avail[0]&&B_need[i]<=Avail[1]&&C_need[i]<=Avail[2])
					{
						Flag[i]=1;
						Avail[0]+=A_alloction[i];
						Avail[1]+=B_alloction[i];
						Avail[2]+=C_alloction[i];
						cout<<"p"<<i<<"   ";
						cout<<"������Դ��:"<<Avail[0]<<" "<<Avail[1]<<" "<<Avail[2]<<endl;
						n++;
					
					}
					j++;
					i++;
					if(i>=5)
						i=i%5;
					if(j==100)
					{	
						cout<<"ϵͳ���벻��ȫ״̬��"<<endl;
						break;
					}
				}
					if(n==5)
					cout<<"��ǰϵͳ״̬��ȫ"<<endl;
		}
	}
	if(c1=="p3")
	{
			if(Avail[0]<num1||Avail[1]<num2||Avail[2]<num3||A_need[3]<num1||B_need[3]<num2||C_need[3]<num3)
				cout<<"��ǰ��Դ�������������������"<<endl;
			else
			{
				Avail[0]-=num1;
				A_need[3]-=num1;
				A_alloction[3]+=num1;

				Avail[1]-=num2;
				B_need[3]-=num2;
				B_alloction[3]+=num2;

				Avail[2]-=num3;
				C_need[3]-=num3;
				C_alloction[3]+=num3;

				if(A_need[3]==0&&B_need[3]==0&&C_need[3]==0)
				{	Flag[3]=1;
					Avail[0]+=A_alloction[3];
				Avail[1]+=B_alloction[3];
				Avail[2]+=C_alloction[3];
				n++;
				}

			
				while(n<5)
				{
					if(Flag[i]==0&&A_need[i]<=Avail[0]&&B_need[i]<=Avail[1]&&C_need[i]<=Avail[2])
					{
						Flag[i]=1;
						Avail[0]+=A_alloction[i];
						Avail[1]+=B_alloction[i];
						Avail[2]+=C_alloction[i];
						cout<<"p"<<i<<"  ";
						cout<<"������Դ��:"<<Avail[0]<<" "<<Avail[1]<<" "<<Avail[2]<<endl;
						n++;
					
					}
					j++;
					i++;
					if(i>=5)
						i=i%5;
					if(j==200)
					{	
						cout<<"ϵͳ���벻��ȫ״̬��"<<endl;
						break;
					}
				}
				if(n==5)
					cout<<"��ǰϵͳ״̬��ȫ"<<endl;
			}
	}
	if(c1=="p4")
	{
		if(Avail[0]<num1||Avail[1]<num2||Avail[2]<num3||A_need[4]<num1||B_need[4]<num2||C_need[4]<num3)
				cout<<"��ǰ��Դ�������������������"<<endl;
			else
			{
				Avail[0]-=num1;
				A_need[4]-=num1;
				A_alloction[4]+=num1;

				Avail[1]-=num2;
				A_need[1]-=num2;
				A_alloction[4]+=num2;

				Avail[2]-=num3;
				A_need[4]-=num3;
				A_alloction[4]+=num3;

				if(A_need[4]==0&&B_need[4]==0&&C_need[4]==0)
				{
					Flag[4]=1;
					Avail[0]+=A_alloction[4];
					Avail[1]+=B_alloction[4];
					Avail[2]+=C_alloction[4];
					n++;
				}

				while(n<5)
				{
					if(Flag[i]==0&&A_need[i]<=Avail[0]&&B_need[i]<=Avail[1]&&C_need[i]<=Avail[2])
					{
						Flag[i]=1;
						Avail[0]+=A_alloction[i];
						Avail[1]+=B_alloction[i];
						Avail[2]+=C_alloction[i];
						cout<<"p"<<i<<"  ";
						cout<<"������Դ��:"<<Avail[0]<<" "<<Avail[1]<<" "<<Avail[2]<<endl;
						n++;
					
					}
					j++;
					i++;
					if(i>=5)
						i=i%5;
					if(j==100)
					{	
						cout<<"ϵͳ���벻��ȫ״̬��"<<endl;
						break;
					}
				}
				if(n==5)
					cout<<"��ǰϵͳ״̬��ȫ"<<endl;
			}
	}
}
int main()
{
	string c1;
	char dou;
	cout<<"���м��㷨��ʼ�����£�"<<endl;
	cout<<"�������p0,p1,p2,p3,p4       3����ԴA,B,C ������Դ����Ŀ�ֱ�Ϊ10��5��7"<<endl;
	cout<<endl;
	cout<<"          Max        ALLOCATION        NEED          AVAILABLE"<<endl;
	cout<<"������   A B C          A B C          A B C          A B C"<<endl;
	cout<<"p0       7 5 3          0 1 0          7 4 3          3 3 2"<<endl;
	cout<<"p1       3 2 2          2 0 0          1 2 2          "<<endl;	
	cout<<"p2       9 0 2          3 0 2          6 0 0          "<<endl;
	cout<<"p3       2 2 2          2 1 1          0 1 1          "<<endl;
	cout<<"p4       4 3 3          0 0 2          4 3 1          "<<endl;
	bankeruser();
	cout<<"�Ƿ����?(y/n)"<<endl;
	cin>>dou;
	while(dou=='Y'||dou=='y')
	{
		Avail[0]=3;
		Avail[1]=3;
		Avail[2]=2;

		A_alloction[0]=0;
		A_alloction[1]=2;
		A_alloction[2]=3;
		A_alloction[3]=2;
		A_alloction[4]=0;

		B_alloction[0]=1;
		B_alloction[1]=0;
		B_alloction[2]=0;
		B_alloction[3]=1;
		B_alloction[4]=0;

		C_alloction[0]=0;
		C_alloction[1]=0;
		C_alloction[2]=2;
		C_alloction[3]=1;
		C_alloction[4]=2;

		A_need[0]=7;
		A_need[1]=1;
		A_need[2]=6;
		A_need[3]=0;		
		A_need[4]=4;

		B_need[5]=4;
		B_need[5]=2;
		B_need[5]=0;
		B_need[5]=1;
		B_need[5]=3;

		C_need[5]=3;
		C_need[5]=2;
		C_need[5]=0;
		C_need[5]=1;
		C_need[5]=1;
		Flag[0]=0;
		Flag[1]=0;
		Flag[2]=0;
		Flag[3]=0;
		Flag[4]=0;
		bankeruser();
		cout<<"�Ƿ����?(y/n)"<<endl;
		cin>>dou;
	}
}