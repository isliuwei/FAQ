/**************************************************************/
/*                                                            */
/*                  The Simulation of Tenor                   */
/*                    Author: WJQ                             */
/*                                                            */
/**************************************************************/


#include <alloc.h>
#include <stdio.h>
#include <conio.h>
#include <bios.h>
#include <graphics.h>

/***********************Key type*******************************/

#define  keyc 11875
#define  keyp 6512
#define  keyb 12386
#define  keye 4709
#define  keyt 5236
#define  keyw 4471
#define  keyq 4209

#define  sc   setcolor
#define  sbc  setbkcolor
#define  sfs  setfillstyle

/***********************Datatype*******************************/


typedef struct node
{
	char ch[4];
	struct node * next;
}linklist;

typedef struct
{
	linklist *front,*rear;
}linkqueue;
linkqueue *NewTenor;
linkqueue *Ready;
linkqueue *Block;

int NoNT=10,NoR=0,NoB=0;
/***************************Fuction Type*******************************/

void vMainDisplay();
void vNewTenorDisplay();
void vReadyDisplay();
void vBlockDisplay();
void vCheckQueue(linkqueue *q);
void vInput();
void vExecuteDisplay(char *str);

/**************************Fuction Describ*****************************/
void vSetNull(linkqueue *q)
{
	q->front=malloc(sizeof(linklist));
	q->front->ch[0]='\0';
	q->front->next=NULL;
	q->rear=q->front;
}

int iEmpty(linkqueue *q)
{
	if(q->front==q->rear)
		return(1);
	else
		return(0);
}

char *cFront(linkqueue *q)
{

	if(iEmpty(q))
		{
			return NULL;
		}
	else
		return(q->front->next->ch+0);

}

void vDeQueue(linkqueue *q)
{
	linklist *s;
	if(iEmpty(q))
		{
			return;
		}
	else
		{
			 s=q->front->next;
			 q->front->next=s->next;
			 free(s);

		}
}

void vEnQueue(linkqueue *q)
{
	q->rear->next=malloc(sizeof(linklist));
	q->rear=q->rear->next;
	q->rear->ch[0]='\0';
	q->rear->next=NULL;

}


/********************************************************/

/*                       Main                           */

/********************************************************/

main()
{
	char execute[4];
	char str;
	int i,j;
	int key;
	clrscr();
	NewTenor=malloc(sizeof(linkqueue));
	Ready=malloc(sizeof(linkqueue));
	Block=malloc(sizeof(linkqueue));
	vSetNull(NewTenor);
	vSetNull(Ready);
	vSetNull(Block);
	for(i=0;i<10;i++)
		{
			vEnQueue(NewTenor);
		}
	vMainDisplay();
	for(;;)
		{
			key=bioskey(0);
			switch(key)
				{
				case keyc:           /*    New Tenor to Ready      */
					if(iEmpty(NewTenor))
						break;
					else
						{
							vDeQueue(NewTenor);
							NoNT--;
							vEnQueue(Ready);
							NoR++;

							vInput();

							vNewTenorDisplay(NewTenor);
							vReadyDisplay(Ready);

							break;
						}
				case keyp:           /*    Ready to Execute       */
					if((execute==NULL)||(iEmpty(Ready)))
						break;
					else
						{
							strcpy(execute,cFront(Ready));
							vDeQueue(Ready);
							NoR--;
							vReadyDisplay(Ready);
							vExecuteDisplay(execute);
							break;
						}
				case keyt:           /*      Execute to Ready       */
					if(execute==NULL)
						break;
					else
						{
							vEnQueue(Ready);
							NoR++;
							strcpy(Ready->rear->ch,execute);

							execute[0]='\0';
							vExecuteDisplay(execute);
							vReadyDisplay(Ready);
							break;
						}
				case keyb:            /*       Execute to Block       */
					if(execute==NULL)
						break;
					else
						{
							vEnQueue(Block);
							NoB++;
							strcpy(Block->rear->ch,execute);
							execute[0]='\0';
							vExecuteDisplay(execute);
							vBlockDisplay(Block);

							break;
						}
				case keyw:            /*        Block to Ready         */
					if(iEmpty(Block))
						break;
					else
						{
							vEnQueue(Ready);
							NoR++;
							strcpy(Ready->rear->ch,cFront(Block));
							vDeQueue(Block);
							NoB--;
							vBlockDisplay(Block);
							vReadyDisplay(Ready);
							break;
						}
				case keye:             /*        End Execute and Execute to New Tenor         */
					if(execute==NULL)
						break;
					else
						{
							execute[0]='\0';
							vEnQueue(NewTenor);
							NoNT++;
							vExecuteDisplay(execute);
							vNewTenorDisplay(NewTenor);
							break;
						}
				case keyq:             /*        Quit        */
				  exit(0);
				default:
					break;
				}


		}

	closegraph();

}

/****************************************************************/
/*                                                              */
/*                     Graph  Portion                           */
/*                                                              */
/****************************************************************/


void vMainDisplay()
{
	int i;
	int driver,mode;
	driver=VGA;
	mode=VGAHI;
	initgraph(&driver,&mode,"");
	cleardevice();
	sfs(1,1);
	bar(0,0,640,18);
	sfs(1,15);
	bar(5,4,15,14);
	bar(624,4,634,14);
	sc(7);
	settextstyle(0,0,1);
	outtextxy(217,7,"The Simelation of Tenor");
	setcolor(WHITE);
	rectangle(50,98,90,382);
	sfs(1,3);
	for(i=0;i<10;i++)
		{

			 bar(54,102+28*i,86,102+28*i+24);
		}
	outtextxy(36,80,"New Tenor");
	rectangle(150,98,593,120);
	outtextxy(342,80,"Ready");
	outtextxy(334,203,"Execute");
	outtextxy(372,342,"Block");
	rectangle(150,360,593,382);
	rectangle(320,220,400,250);
	rectangle(550,220,593,250);
	sc(15);
	outtextxy(561,232,"END");
	line(400,235,550,235);
	line(545,230,550,235);
	sfs(1,2);
	bar(323,223,397,247);
	sfs(1,3);
	bar(0,462,640,480);
	sc(15);

	line(90,109,150,109);
	line(145,104,150,109);

	line(328,120,328,220);
	line(323,215,328,220);

	line(393,120,393,220);
	line(398,125,393,120);

	line(360,250,360,360);
	line(365,355,360,360);

	line(173,120,173,360);
	line(168,125,173,120);
	sc(14);
	settextstyle(0,0,2);
	outtextxy(118,90,"C");
	outtextxy(310,160,"P");
	outtextxy(400,160,"T");
	outtextxy(367,290,"B");
	outtextxy(152,234,"W");
	outtextxy(468,216,"E");
	settextstyle(0,0,1);
	outtextxy(30,440,"Press 'E' to End Execute.");
	outtextxy(470,440,"Press 'Q' to Quit.");
	sc(6);
	outtextxy(0,468," INPUT TENOR'S NAME:");


}

void vReadyDisplay()
{
	linklist *s;
	int i;
	s=Ready->front->next;
	sc(7);
	settextstyle(0,0,1);
	sfs(1,0);
	bar(153,101,590,117);
	sfs(1,14);
	for(i=0;i<NoR;i++)
		{

			bar(151+i*44+2,101,150+i*44+44,117);
			sc(0);
			outtextxy(160+i*44+2,106,s->ch);
			s=s->next;
		}

	return;
}

void vBlockDisplay()
{
	 linklist *s;
	 int i;
	 s=Block->front->next;
				sfs(1,0);
				bar(153,363,590,379);
				sfs(1,RED);
				for(i=0;i<NoB;i++)
					{
						bar(153+i*44,363,194+i*44,379);
						outtextxy(162+i*44,367,s->ch);
						s=s->next;
					}
			 return;
}
void vNewTenorDisplay()
{
	 int i;

				sfs(1,0);
				bar(54,99,86,380);
				sfs(1,3);
				for(i=0;i<NoNT;i++)
					{

						 bar(54,102+28*i,86,102+28*i+24);
					}
				return;

}

void vExecuteDisplay(char *str)
{
	sfs(1,2);
	if(str[0]=='\0')
		bar(323,223,397,247);
	else
		sc(15);
		outtextxy(348,231,str);
}

void vCheckQueue(linkqueue *q)
{
	linklist *s;
	int i=0;
	s=q->front->next;
	sc(15);
	moveto(20,20);
	while(s!=NULL)
		{
			printf("%d",i++);
			outtext(s->ch);

			s=s->next;
		}
	printf(" ");
	return;
}
/*       INPUT CONTROL      */

void vInput()
{
	int j;
	sfs(1,3);
	bar(0,462,640,480);
	sc(6);
	outtextxy(0,468," INPUT TENOR'S NAME:");
	moveto(160,468);
	for(j=0;j<3;j++)
		{
			Ready->rear->ch[j]=bioskey(0);
			Ready->rear->ch[j+1]='\0';
			outtextxy(160,468,Ready->rear->ch);

		}

}