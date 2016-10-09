# include <iostream>
# include <stdlib.h>
# include <malloc.h>
# include <stdio.h>
using namespace std;

typedef struct node
{
	int yehao;
	int kuaihao ;
	int zhuangtai ;
	struct node * next ;
} linkstack1 ;


typedef struct snode
{
	int yehao ;
	struct snode *next ;
	struct snode *rear;
} linkstack2 ;


int y_length , m_length , k_length , logical , phisical , count ,b,k=0;
int y_hao,y_dizhi;
int a[8][8];
char c;
double visit=0 , absent=0 ;
linkstack1 *l1 = ( linkstack1 *)malloc(sizeof( linkstack1 ));
linkstack2 *l2 = ( linkstack2 *)malloc(sizeof( linkstack2 ));
linkstack1 *s=l1;
linkstack2 *r=l2;
linkstack2 *m=l2;



void weishitu();
void zhuanhua();
void fifo();
void lru();
void zhan();
void yebiao();
int dizhi();
void xianshi();

void yebiao()
{
	linkstack1 *p=l1;
	if(p==NULL)
	{
		cout<<"Error!"<<endl;
	}
	while(p!=NULL)
	{
		cout<<p->yehao<<"	"<<p->kuaihao<<"	"<<p->zhuangtai<<endl;
		p=p->next;
	}
}


void zhan()
{
	linkstack2 *q=r;
	if(q==NULL)
	{
		cout<<"Error!"<<endl;
	}
	while(q!=m->next)
	{
		cout<<q->yehao<<endl;
		q=q->next;
	}
}


void weishitu()
{
	for( int j = 0;j <= 7;j ++ )
	{
		a[0][j] = 1 ;
	}
	for( int k = 1;k <= 7;k ++ ) 
	{
	   for( int j = 0;j <= 7;j ++ )
		   a[k][j] = rand()%2 ; 
	}
	cout << "位示图为: " << endl;
	for(int i = 0;i <= 7;i ++)
	{
		for(int j = 0;j <= 7;j ++)
		   cout << a[i][j] << " ";
		   cout << endl ;
	}
}
void fifo()
{
 	 linkstack2 *q,*n,*l;
 	 linkstack1 *p,*e,*b;
	 p=l1;
	 b=l1;
	 q=l2;
	 if(logical!=-1)
	 {
      zhuanhua();
	  if(y_hao>y_length)
      {
	  cout<<"越界中断！"<<endl;
	  exit(0);
	  }
 	 else
 	 {
	  if(k<m_length)
     {
	    while(p!=NULL)
	    {
		    if(p->yehao!=y_hao)
				p=p->next;
			else
			{ 
				if(p->zhuangtai==0)
				{
					p->kuaihao=dizhi();
					k++;
				    phisical=p->kuaihao*k_length*1024 + y_dizhi;
			        p->zhuangtai=1;
			        l2->yehao=p->yehao;
			        l2=l2->rear;
			        cout<<"物理地址为:"<<endl;
                    printf("%x\n",phisical);
					cout<<"位示图为: "<<endl;
	                for(int i=0;i<=7;i++)
					{
		              for(int j=0;j<=7;j++)
		              cout<<a[i][j]<<" ";
		               cout<<endl ;
					}
					absent++;
					cout<<"访问次数:"<<visit<<endl;
				    cout<<"缺页次数:"<<absent<<endl;
				    cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
					xianshi();
					fifo();
			        break;
				}
			
			    else
				{
					
					
                       phisical=p->kuaihao*k_length*1024+y_dizhi;
				       cout <<"物理地址为:"<< endl;
                       printf("%x\n",phisical);
				       cout<<"访问次数:"<<visit<<endl;
				       cout<<"缺页次数:"<<absent<<endl;
				       cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
				       xianshi();
				       fifo();
				       break;
				}
			}
	 }

  }
  else
  {
      while(p!=NULL)
      {
        if(p->yehao!=y_hao)
		   p=p->next;
        else
        {
		 	if(p->zhuangtai==1)
		 	{
	          phisical=p->kuaihao*k_length*1024 + y_dizhi;
	          cout <<"物理地址为:"<< endl;
              printf("%x\n",phisical);
			  cout<<"访问次数:"<<visit<<endl;
			  cout<<"缺页次数:"<<absent<<endl;
			  cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
              xianshi();
              fifo();
              break;
	        }
	        else
	        {
		 	  e=p;
			  while(b!=NULL)
			  {
 				if(b->yehao!=m->yehao)
		           b=b->next;
                else
                {  
				   e->kuaihao=b->kuaihao;
				   e->zhuangtai=1;
				   b->kuaihao=0;
				   b->zhuangtai=0;
				   n=(linkstack2 *)malloc(sizeof(linkstack2));
                   n->yehao=y_hao;
                   n->next=r;
                   r->rear=n;
                   n->rear=NULL;
                   r=n;
                   l=m;
                   m=m->rear;
                   free(l);
			   	   phisical=e->kuaihao*k_length*1024 + y_dizhi;
                   cout <<"物理地址为:"<< endl;
                   printf("%x\n",phisical);
				   absent++;
				   cout<<"访问次数:"<<visit<<endl;
				   cout<<"缺页次数:"<<absent<<endl;
				   cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
                   xianshi();
                   fifo();
                   break;
			 	}
		      }	
		 	}
 	    }
      }
  }
}
}
else
  {exit(0);
  getchar();
  getchar();}
}



void zhuanhua()
{
   cout << "请输入逻辑地址(十六进制): " << endl;
   scanf("%x",&logical);
   y_hao=logical/(k_length*1024);
   y_dizhi=logical%(k_length*1024);
   cout<<"页号为:"<<endl;
   cout<<y_hao<<endl;
   cout<<"页内地址为:"<< endl;
   cout<<y_dizhi<<endl;
   visit++;
}




int dizhi()
{
  for(int i = 0;i <= 7;i ++)
  {
	  for(int j = 0;j <= 7;j ++)
	  {
		  if(a[i][j] == 0)
		  {
			  a[i][j] =1 ;
		      b=(i * 8) + (j +1);
			  return b;
		  }
			 
	  }
  }
  
}



void lru()
{
     linkstack2 *q,*n,*l,*f,*g;
 	 linkstack1 *p,*e,*b;
	 p=l1;
	 b=l1;
	 q=r;
	 if(logical!=-1)
	 {
     zhuanhua();
     if(y_hao>y_length)
     {
	 cout<<"越界中断！"<<endl;
     exit(0);
	 }
     else
     {
 	 if(k<m_length)
     {
	    while(p!=NULL)
	    {
		    if(p->yehao!=y_hao)
				p=p->next;
			else
			{ 
				if(p->zhuangtai==0)
				{
					p->kuaihao=dizhi();
					k++;
					cout<<k<<endl;
				    phisical=p->kuaihao*k_length*1024 + y_dizhi;
			        p->zhuangtai=1;
			        l2->yehao=p->yehao;
			        l2=l2->rear;
			        cout<<"物理地址为:"<<endl;
                    printf("%x\n",phisical);
					cout<<"位示图为: "<<endl;
	                for(int i=0;i<=7;i++)
					{
		              for(int j=0;j<=7;j++)
		              cout<<a[i][j]<<" ";
		               cout<<endl ;
					}
					absent++;
					cout<<"访问次数:"<<visit<<endl;
				    cout<<"缺页次数:"<<absent<<endl;
				    cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
					xianshi();
					lru();
			        break;
				}
			
			    else
				{
                  while(q!=NULL)
				  {
				   if(q->yehao!=y_hao)
				      q=q->next;
			      else
				  {
					if(q==l2->next)
					{
   	                phisical=p->kuaihao*k_length*1024 + y_dizhi;
	                cout <<"物理地址为:"<< endl;
                    printf("%x\n",phisical);
			        cout<<"访问次数:"<<visit<<endl;
			        cout<<"缺页次数:"<<absent<<endl;
			        cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
                    xianshi();
                    lru();
                    break;
					}
					else if((q!=l2->next)&&(q==m))
					{
						g=l2->next;
						f=q;
						m=m->rear;
                        n=(linkstack2 *)malloc(sizeof(linkstack2));
				        n->yehao=f->yehao;
	                    n->next=g;
						l2->next=n;
	                    g->rear=n;
	                    n->rear=l2;
						free(f);
						phisical=p->kuaihao*k_length*1024 + y_dizhi;
	                    cout <<"物理地址为:"<< endl;
                        printf("%x\n",phisical);
				        cout<<"访问次数:"<<visit<<endl;
				        cout<<"缺页次数:"<<absent<<endl;
				        cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
                        xianshi();
				        lru();
                        break;
					}
					else
					{
                        f=q;
						g=l2->next;
			 	        f->rear->next=f->next;
			 	        f->next->rear=f->rear;
	                    n=(linkstack2 *)malloc(sizeof(linkstack2));
				        n->yehao=f->yehao;
	                    n->next=g;
						l2->next=n;
	                    g->rear=n;
	                    n->rear=l2;
						free(f);
	                    phisical=p->kuaihao*k_length*1024 + y_dizhi;
	                    cout <<"物理地址为:"<< endl;
                        printf("%x\n",phisical);
				        cout<<"访问次数:"<<visit<<endl;
				        cout<<"缺页次数:"<<absent<<endl;
				        cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
                        xianshi();
				        lru();
                        break;
					}
				  }
				 }
				}
			}
	 }

  }
     else
     {
 	
      while(p!=NULL)
      {
        if(p->yehao!=y_hao)
		   p=p->next;
		   
        else
        {
		 	if(p->zhuangtai==1)
		 	{
	          while(q!=NULL)
	          {
				if(q->yehao!=y_hao)
				 q=q->next;
			    else
			    {
			 	
				 if((q==r)||((q==m)&&(m->rear==NULL)))
			 		{
 			           phisical=p->kuaihao*k_length*1024 + y_dizhi;
	                   cout <<"物理地址为:"<< endl;
                       printf("%x\n",phisical);
			           cout<<"访问次数:"<<visit<<endl;
			           cout<<"缺页次数:"<<absent<<endl;
			           cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
                       xianshi();
                       lru();
                       break;
 			        }
				 else if(q==m)
				 {
					 f=q;
					 m=m->rear;
					 n=(linkstack2 *)malloc(sizeof(linkstack2));
                     n->yehao=f->yehao;
					 n->next=r;
					 r->rear=n;
					 r=n;
					 free(f);
					 phisical=p->kuaihao*k_length*1024 + y_dizhi;
	                 cout <<"物理地址为:"<< endl;
                     printf("%x\n",phisical);
				     cout<<"访问次数:"<<visit<<endl;
				     cout<<"缺页次数:"<<absent<<endl;
				     cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
                     xianshi();
				     lru();
                     break;
				 }
				 else
				 {
			 	   f=q;
			 	   f->rear->next=f->next;
			 	   f->next->rear=f->rear;
	               n=(linkstack2 *)malloc(sizeof(linkstack2));
				   n->yehao=f->yehao;
	               n->next=r;
	               r->rear=n;
	               n->rear=NULL;
	               r=n;
	               free(f);
	               phisical=p->kuaihao*k_length*1024 + y_dizhi;
	               cout <<"物理地址为:"<< endl;
                   printf("%x\n",phisical);
				   cout<<"访问次数:"<<visit<<endl;
				   cout<<"缺页次数:"<<absent<<endl;
				   cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
                   xianshi();
				   lru();
                   break;
				 }
				 }
			  }
	        }
	        else
	        {
		 	  e=p;
			  while(b!=NULL)
			  {
 				if(b->yehao!=m->yehao)
		           b=b->next;
                else
                {  
				   e->kuaihao=b->kuaihao;
				   e->zhuangtai=1;
				   b->kuaihao=0;
				   b->zhuangtai=0;
				   n=(linkstack2 *)malloc(sizeof(linkstack2));
                   n->yehao=y_hao;
                   n->next=r;
                   r->rear=n;
                   n->rear=NULL;
                   r=n;
                   l=m;
                   m=m->rear;
                   free(l);
			   	   phisical=e->kuaihao*k_length*1024 + y_dizhi;
                   cout <<"物理地址为:"<< endl;
                   printf("%x\n",phisical);
				   absent++;
				   cout<<"访问次数:"<<visit<<endl;
				   cout<<"缺页次数:"<<absent<<endl;
				   cout<<"缺页率:"<<((absent/visit)*100)<<"%"<<endl;
                   xianshi();
				   lru();
                   break;
			 	}
		      }	
		 	}
 	    }
      } 
	 }
	 }
	 }
	 else
	 {exit(0);
	 getchar();
	 getchar();}
 }


void xianshi()
{
   	cout<<"**********页表**********"<<endl;
	cout<<"页号"<<"	"<<"块号"<<"	"<<"状态"<<endl;
	yebiao();
	cout<<"**********内存**********"<<endl;
	cout<<"页号"<<endl;
	zhan();
}


int main()
{
    int d=1;
	weishitu() ;
	cout << "请输入页表长度: " << endl ;
	cin >> y_length ;
	cout << "请输入内存的长度: " << endl ;
	cin >> m_length ;
	cout << "请输入块大小(K): " << endl ;
	cin >> k_length ;
	l1->yehao = 0;
	l1 -> kuaihao = 0 ;
    l1 -> zhuangtai = 0 ;
    l2 -> yehao = 0;
	l1->next=NULL;
	l2->next=NULL;
	l2->rear=NULL;
    linkstack1 *h ;
	linkstack2 *k ;
	
    for(int i = 0;i < y_length-1; i++)
	{
		h = ( linkstack1 *)malloc(sizeof( linkstack1 )) ;
		h-> yehao = d;
		h -> kuaihao = 0 ;
	    h -> zhuangtai = 0 ;
		s -> next = h ;
		s = s -> next ;
		d++;
	   
	}
	s->next=NULL;
	for(int j=0;j < m_length-1; j++)
	{
		k = ( linkstack2 *)malloc(sizeof( linkstack2 )) ;
		k -> yehao = 0;
		k -> next = r ;
		r -> rear = k ;
		r =  k;
	}
	xianshi();
	cout<<"请选择页面置换算法:" <<endl;
	cout<<"F--FIFO算法"<<endl;
	cout<<"L--LRU算法"<<endl;
	cout<<"#--退出程序"<<endl; 
	cin>>c; 
	switch(c)
	{
      case 'F':fifo();
               break;
      case 'L':lru();
               break;
      case '#':exit(0);
               break;
      default:printf("error\n");
    }
}
