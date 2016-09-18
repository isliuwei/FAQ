#include "stdlib.h"
#include "stdio.h"
#include "string.h"
struct PCB{
   char name[10];
   struct PCB *next;
};
 struct PCB *ready;
 struct PCB *running;
 struct PCB *blocked;

 void add(struct PCB *p,struct PCB *head){
     struct PCB *tmp=head;
	 while (tmp->next!=NULL)
		 tmp=tmp->next;
	 tmp->next=p;
	 p->next=NULL;
}
 struct PCB *removeFirst(struct PCB *head){
     struct PCB *p=head->next;
	 if(p!=0){
	 head->next=p->next;
	 p->next=0;
	 return p;
	 }
	 return(struct PCB*)0;
 }
 void creat(){
    struct PCB *p;
	p=(struct PCB*)malloc(sizeof(struct PCB));
	printf("Name:");
	scanf("%s",p->name);
	add(p,ready);
	if(running==NULL)
	{
		running=removeFirst(ready);
	}

 }
 int size(struct PCB *p){
	 int i=0;
	 struct PCB *tmp=p;
	 while(tmp->next!=NULL){
	 i++;
	 tmp=tmp->next;
     }
	 printf("\n");
	 return i;
 }
 void display(){
    struct PCB *tmp;
	printf("running:");
	if(running!=0)
	printf("%s",running->name);
	tmp=ready->next;
	printf("\nReady:");
	while(tmp!=0)
    {printf("%s",tmp->name);
	tmp=tmp->next;
	}
	tmp=blocked->next;
	printf("\nBloced\n:");
	while(tmp!=0){
	  printf("%s",tmp->name);
	  tmp=tmp->next;
	}
	printf("\n");
 }
 void main ()
 {   
   char i;
     ready=(struct PCB *)malloc(sizeof(struct PCB));
	 ready->next=NULL;
	 strcpy(ready->name,"Ready");
	 blocked=(struct PCB *)malloc(sizeof(struct PCB));
	 blocked->next=NULL;
	 strcpy(blocked->name,"Blocked");
	 printf("C--创建进程\n");
	 printf("B--阻塞进程\n");
	 printf("I--时间片到了\n");
	 printf("F--进程运行结束\n");
	 printf("W--唤醒进程\n");
	  printf("Enter\n");
	  while(1){
	     scanf("%c",&i);
		 switch(i){
			 case'C':
				 creat();
				 display();
				 break;
			 case'I':{
				 if(running!=0){
				 add(running,ready);
				 running=removeFirst(ready);
				 display();
				 }
				 else return;
				break;
					 }
			 case'B':{
				 if(running!=0){
				add(running,blocked);

				 }
				 else 
					 printf("NO running\n");
		             running=removeFirst(ready);
					 display();
					 break;

					 }
			 case'W':{
					 if(size(blocked)!=0)
						 add(removeFirst(blocked),ready);
					 else
					 printf("NO blocked\n");
					 if(running==NULL){
						 running=removeFirst(ready);
					 }
					 display();
					 break;
					 }
			 case'F':{
					 free(running);
					 running=removeFirst(ready);
					 if(running==NULL)
					 	  printf("NO running\n");
				  display();
				  break;
					 }

					 }
		 }
	  
	  }
	  