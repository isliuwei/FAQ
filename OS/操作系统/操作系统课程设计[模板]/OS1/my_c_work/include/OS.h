#include "stdlib.h"
#include "stdio.h"
#include "ggg.h"

#ifndef  OS_H
#define  OS_H
typedef struct PCB{
        char *name;
        struct PCB *link;
		int hasname;
		
}PCB;
typedef struct PCB_point{
        PCB *next;
		char *name;
        int num;
        int maxnum;
        int start_x;
        int start_y;
        int end_x;
        int end_y;
		int this_y;
		int this_x;
        int color;
		int text_color;
		int changed;
}PCB_point;

PCB_point *freelist,*runlist,*runablelist,*blocklist;

void dispatch();

void set_PCB_point(PCB_point *t,PCB *p,int n,int maxn,int st_x,int st_y,int ed_x,int ed_y,int clor,char *name1,int text_col)
{
        t->next=p;
        t->maxnum=maxn;
        t->num=n;
        t->start_x=st_x;
        t->start_y=st_y;
        t->end_x=ed_x;
        t->end_y=ed_y;
        t->color=clor;
		t->this_y=st_y;
		t->this_x=st_x;
		t->name=name1;
		t->text_color=text_col;
		t->changed=1;
}
void PCB_point_init()
{
        freelist=(PCB_point *)calloc(1,sizeof(PCB_point));
        runlist=(PCB_point *)calloc(1,sizeof(PCB_point));
        runablelist=(PCB_point *)calloc(1,sizeof(PCB_point));
        blocklist=(PCB_point *)calloc(1,sizeof(PCB_point));
		 set_PCB_point(freelist,NULL,10,10,0,31,120,431,HiColor(0x0000FF),"空闲态列表",0);
		set_PCB_point(runablelist ,NULL,0,1,121,31,240,431,HiColor(0xFFFF00),"就绪态列表",0);
		 set_PCB_point(runlist,NULL,0,10,241,31,360,431,HiColor(0x00FF00),"运行态列表",0x9900cc);
		  set_PCB_point(blocklist,NULL,0,10,361,31,480,431,HiColor(0xFF0000),"阻塞态列表",0xffffff);
       /* set_PCB_point(freelist,NULL,10,10,0,0,0);
        set_PCB_point(runlist,NULL,0,1,0,0,0);
        set_PCB_point(runablelist,NULL,0,10,0,0,0);
        set_PCB_point(blocklist,NULL,0,10,0,0,0);
        	*/
}
void insert(PCB_point *t,PCB *p)
{
        PCB *temp;
        temp=t->next;
        if (temp==NULL)
        {
           t->next=p;
        }
        else
        {
        while(temp->link!=NULL)
              temp=temp->link;
        temp->link=p;
        }
        t->num+=1;
		t->changed=1;
}
void remove_head(PCB_point *t)
{
        t->next=t->next->link;
        t->num-=1;
		t->changed=1;
}
void create(char *text)
{
       PCB *temp;
	   if(freelist->num>0)
	{
       temp=(PCB *)malloc(sizeof(PCB));
       temp->name=text;
       temp->link=NULL;
	   temp->hasname=1;
       freelist->num-=1;
	   freelist->changed=1;
       insert(runablelist,temp);
	}
	else		
	{
		showMessage("出错了！没有更多的资源要被创建。");		
		/*   error,no more progess         */
	}
}
void timeout()
{
      dispatch();
}
void dispatch1()
{
                runlist->next=runablelist->next;
                remove_head(runablelist);
                runlist->next->link=NULL;
				runlist->changed=1;
                }
void dispatch()
{
        if(runlist->num==0)
        {
        if(runablelist->num==0)
        {
			showMessage("出错了！NULL runable");
		
               /* printf("NULL runable\ndispatch failed\n");*/
        }
        else
        {
                dispatch1();
                runlist->num+=1;

              /*  printf("dispatch success\n");*/
        }
        }
       else
       {        runlist->num-=1;
                insert(runablelist,runlist->next);
                 dispatch1();
                runlist->num+=1;
                
               /* printf("dispatch success\n");*/
              
       }
}
void block()
{
        if(blocklist->num==0)
        {
                 if(runlist->num==1)
                {
				blocklist->next=runlist->next;
               /* printf("block ok");*/
                blocklist->num+=1;
				blocklist->changed=1;
                runlist->num-=1;
                runlist->next=NULL;
				runlist->changed=1;
                dispatch();
				}				
                else
                {
					showMessage("出错了！ no Run");
		                    /*printf("ERROR : no Run");*/
				}
        }
        else
        {
                if(runlist->num==1)
                {
                        insert(blocklist,runlist->next);
                       
                        runlist->num-=1;
                        runlist->next=NULL;
						runlist->changed=1;
                        dispatch();
                       /* printf("block ok");*/
                }
                else
                {
					showMessage("出错了！ no Run");		            
                        /*printf("ERROR : no Run");*/
                }
        }

}
void wakeup()
{
        PCB *temp;
        if(blocklist->num==0)
        {
			showMessage("出错了！ no block。");
		
               /* printf("error: no block");*/
        }
        else
        {
             temp=blocklist->next;
             remove_head(blocklist);
             temp->link=NULL;
             insert(runablelist,temp);
            /* printf("wakeup ok");*/


        }
        if(runlist->num==0)
        {
              dispatch();
            /*  printf("wakeup ok");*/
        }
}

void quit_PCB()
{
        if(runlist->num==0)
        {
			showMessage("出错了！ no Run。");
                /*printf("NO RUN");*/
        }
        else
        {
           free(runlist->next);
           /* printf("end ok");   */
           runlist->next=NULL;
           runlist->num-=1;
		   runlist->changed=1;
           freelist->num+=1;
		   freelist->changed=1;
           dispatch();
        }
}
void list1(PCB_point *t)
{       PCB *temp;
        temp=t->next;
        printf("\nnumber:  %d",t->num);
        printf("\nmax number:  %d",t->maxnum);
        printf("\ndata:\n") ;
        while(temp!=NULL)
        {
                printf("%s\n",temp->name);
                temp=temp->link;
        }
        printf("date ends\n");
}
void list()
{
    printf("freelist: ");
    list1(freelist);
    printf("runlist: ");
    list1(runlist);
    printf("runablelist: ");
    list1(runablelist);
    printf("blocklist: ");
    list1(blocklist);
}
/*
void main()
{
        char choice;
        char *text;
        printf("start:\n");
        PCB_point_init();
        while(1)
        {
        printf("choice:");
        choice=getchar();getchar();

                switch(choice)
                 {
                    case 'c':
                            printf("\nplease input text:");
                            text=(char *)malloc(100);
                            gets(text);
                            create(text);
                            break;
                    case 's':
                                list();
                                break;
                    case 'p':   dispatch();
                                break;
                    case 't':    timeout();
                                break;
                    case 'b':   block();
                                break;
                    case 'w':   wakeup();
                                break;
                    case  'x': exit(0);
                 }
        }
}
*/

#endif 
