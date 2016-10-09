/*****************************************************************/
/*          				 The Samlation of PageRam                    */
/*                                                               */
/*                        Author:  WJQ                           */
/*****************************************************************/

#include <stdlib.h>
#include <time.h>
#include <bios.h>
#include <conio.h>
#include <dos.h>


#define  ESC     0x011b
#define  RETRUN  0x1c0d
#define  RIGHT   0x4d00
#define  LEFT    0x4b00
#define  UP      0x4800
#define  DOWN    0x5000

/************************Variable  Type***************************/

typedef struct PageList{
int num;
int state;
}pagelist;
pagelist pageram[64];
pagelist stack[6];
pagelist temp;

int method,pagesize,ramsize,number;

char *cmethod[]={"     FIFO       ",
								"      LRU       "};
char *cpagesize[]={"        1K      ",
									 "        2K      ",
									 "        3K      ",
									 "        4K      "};
char *cramsize[]={"      64K       ",
									"      48K       ",
									"      32K       ",
									"      16k       "};
char *cnumber[]={"        3        ",
								 "        4        ",
								 "        5        ",
								 "        6        "};
char *ok[]={"       OK      ",
						"      EXIT     "};
int raw=0,line=0;
int state[4]={0,0,0,0};
int ps[4]={1,2,3,4};
int rs[4]={64,48,32,16};
int no[4]={3,4,5,6};
unsigned int realaddr[64];
int logicaddr[64];
unsigned int queue[12];
int s[12];
/*************************Fuction  Type*****************************/
void vMainDisplay()
{
	int i;
	textmode(3);
	textbackground(0);
	clrscr();
	textcolor(7);
	window(1,1,80,1);
		textbackground(1);
		clrscr();
		gotoxy(2,1);
		putch(254);
		gotoxy(27,1);
		cprintf("The Samlation of PageRam");
		gotoxy(79,1);
		putch(254);
	textbackground(0);
	window(1,2,80,22);
		for(i=2;i<80;i++)
			{
				 gotoxy(i,1);
				 putch(205);
				 gotoxy(i,9);
				 putch(196);
				 gotoxy(i,19);
				 putch(205);
			}
		gotoxy(1,1);
		putch(213);
		gotoxy(80,1);
		putch(184);
		gotoxy(1,19);
		putch(212);
		gotoxy(80,19);
		putch(190);
		for(i=2;i<19;i++)
			{
				if(i==9)
					{
						gotoxy(1,i);
						putch(195);
						gotoxy(80,i);
						putch(180);
					}
				else
					{
						gotoxy(1,i);
						putch(179);
						gotoxy(80,i);
						putch(179);
					}
			}
	window(1,21,80,21);
		textbackground(4);
		clrscr();
		gotoxy(6,1);
		cprintf("METHOD");
		gotoxy(21,1);
		cprintf("PAGESIZE");
		gotoxy(37,1);
		cprintf("RAMSIZE");
		gotoxy(54,1);
		cprintf("NUMBER");
	window(1,22,80,25);
		textbackground(1);
		clrscr();
		gotoxy(1,2);
		textbackground(0);
		cprintf("%s",cmethod[0]);
		gotoxy(17,1);
		cputs(cpagesize[0]);
		gotoxy(33,1);
		cputs(cramsize[0]);
		gotoxy(49,1);
		cputs(cnumber[0]);
		gotoxy(66,2);
		cputs(ok[0]);
		textbackground(1);
		gotoxy(1,3);
		cputs(cmethod[1]);
		for(i=2;i<5;i++)
			{
				gotoxy(17,i);
				cputs(cpagesize[i-1]);
				gotoxy(33,i);
				cputs(cramsize[i-1]);
				gotoxy(49,i);
				cputs(cnumber[i-1]);
			}
		gotoxy(66,3);
		cputs(ok[1]);
}
void vGetKey();
void vProcDisplay();
void vProcData();
void vFIFO();
void vLRU();

main()
{
	int key;
	union REGS r;
	r.h.ah=1;
	r.h.ch=1;
	r.h.cl=0;
	int86(0x10,&r,&r);
	vMainDisplay();
	while(1)
	{
		 vGetKey();
	}


}

void vGetKey()
{
	int key;
	key=bioskey(0);
	switch(key)
	{
		case UP:
		{
			if(raw==0)
				{
					state[0]--;
					if(state[0]<0)
						state[0]=0;
				}
			else
				if(raw==4)
				{
					line--;
					if(line<0)
						line=0;
				}
				else
					{
						state[raw]--;
						if(state[raw]<0)
							state[raw]=0;
					}
			vProcDisplay();
			return;
		}
		case DOWN:
		{
			if(raw==0)
				{
					state[0]=(state[0]+1)%2;
				}
			else
				if(raw==4)
					line=(line+1)%2;
				else
					{
						state[raw]=(state[raw]+1)%4;
					}
			vProcDisplay();
			return;
		}
		case RIGHT:
		{
			raw=(raw+1)%5;
			return;
		}
		case LEFT:
		{
			raw=(raw-1);
			if(raw<0)
				raw=0;
			return;
		}
		case RETRUN:
		{
			if((raw==4)&&(line==1))
				exit(0);
			else
				vProcData();
			return;
		}
		case ESC:
		{
			exit(0);
		}
	}
}

void vProcDisplay()
{
	int i;
	window(1,22,80,25);
	switch(raw)
	{
		case 0:
			for(i=0;i<2;i++)
				{
					textbackground(1);
					gotoxy(1,i+2);
					cputs(cmethod[i]);
				}
			textbackground(0);
			gotoxy(1,state[0]+2);
			cputs(cmethod[state[0]]);
			return;
		case 1:
			for(i=0;i<4;i++)
				{
					textbackground(1);
					gotoxy(17,i+1);
					cputs(cpagesize[i]);
				}
			textbackground(0);
			gotoxy(17,state[1]+1);
			cputs(cpagesize[state[1]]);
			return;
		case 2:
			for(i=0;i<4;i++)
				{
					textbackground(1);
					gotoxy(33,i+1);
					cputs(cramsize[i]);
				}
			textbackground(0);
			gotoxy(33,state[2]+1);
			cputs(cramsize[state[2]]);
			return;
		case 3:
			for(i=0;i<4;i++)
				{
					textbackground(1);
					gotoxy(49,i+1);
					cputs(cnumber[i]);
				}
			textbackground(0);
			gotoxy(49,state[3]+1);
			cputs(cnumber[state[3]]);
			return;
		case 4:
			for(i=0;i<2;i++)
				{
					textbackground(1);
					gotoxy(66,i+2);
					cputs(ok[i]);
				}
			textbackground(0);
			gotoxy(66,line+2);
			cputs(ok[line]);

			return;


	}

}
void vProcData()
{
	int i,pageno,l;
	int temp,k,same=1;
	int P,d;
	/*      Make Address Image    */
	randomize();
	pageno=rs[state[2]]/ps[state[1]];
	window(2,3,79,9);
	textbackground(0);
	clrscr();
	gotoxy(29,1);
	textcolor(14);
	cprintf("Address Image List");
	textcolor(7);
	l=2;
	gotoxy(2,l);
	for(i=0;i<pageno;i++)
		{
			logicaddr[i]=i;
			pageram[i].num=i;
			pageram[i].state=0;
			same=0;
			if(i==0)
				realaddr[i]=random(pageno);
			else
			{
				while(same<i)
				{
					temp=random(pageno);
					for(k=0;k<i;k++)
						{
							if(temp==realaddr[k])
								{
									same=0;
									break;
								}
							else
								same++;
						}
				}
				realaddr[i]=temp;
			}
			if(((i%11)==0)&&(i!=0))
			gotoxy(2,++l);
			cprintf("%2x--%2x ",i,realaddr[i]);
		}
	for(i=0;i<12;i++)
		{
			queue[i]=logicaddr[random(pageno)]*1024*ps[state[1]]+random(400);
		}
 window(2,13,79,13);
 textbackground(2);
 clrscr();
 textcolor(15);
		for(i=0;i<12;i++)
			{
				gotoxy(6*i+1,1);
				s[i]=queue[i]/(1024*ps[state[1]]);
				cprintf("%5x ",s[i]);
			}
 window(2,11,79,12);
 textbackground(0);
 clrscr();
 gotoxy(1,1);
 for(i=0;i<12;i++)
	{
		P=realaddr[queue[i]/(1024*ps[state[1]])]*(1024*ps[state[1]]);
		d=queue[i]%(1024*ps[state[1]]);
		gotoxy(6*i+1,1);
		cprintf("%5x ",P+d);
		gotoxy(6*i+1,2);
		cprintf("%5x ",queue[i]);
	}
	textcolor(7);
	for(i=0;i<6;i++)
		{
			stack[i].num=0;
			stack[i].state=0;
		}
	if(state[0]==0)    /*   FIFO   */
		{
			vFIFO();
			return;
		}
	else           /*    LRU   */
		{
			vLRU();
			return;
		}

}

void vFIFO()
{
	int i,k;
	float per;
	int bp,sp,num=no[state[3]];
	int false;
	false=0;
	sp=0;
	bp=num;
	window(2,14,79,19);
	clrscr();

	for(i=0;i<12;i++)
	{
		if(pageram[s[i]].state!=1)
			{
				if(sp==bp)
					{
						pageram[stack[0].num].state=0;
						for(k=0;k<bp-1;k++)
							{
								stack[k]=stack[k+1];
							}
						stack[sp-1]=pageram[s[i]];
						pageram[s[i]].state=1;
					}
				else
					{
						stack[sp]=pageram[s[i]];
						pageram[s[i]].state=1;
						sp++;

					}
				false++;
			}
		for(k=0;k<num;k++)
			{
				gotoxy(6*i+1,k+1);
					cprintf("%5x ",stack[k].num);
			}
	}
	gotoxy(73,6);
	per=((float)false/12.00)*100.00;
	cprintf("%2.1f",per);
	return;
}

void vLRU()
{
	int i,k;
	float per;
	int sp,bp,num=no[state[3]];
	int false;
	false=0;
	sp=0;
	bp=num;
	window(2,14,79,19);
	clrscr();
	for(i=0;i<12;i++)
	{
		if(pageram[s[i]].state!=1)
			{
				if(sp=bp)
					{
							pageram[stack[0].num].state=0;
							for(k=0;k<bp-1;k++)
								{
									stack[k]=stack[k+1];
								}
							stack[sp-1]=pageram[s[i]];
							pageram[s[i]].state=1;
					}
				else
					{
						stack[sp]=pageram[s[i]];
						pageram[s[i]].state=1;
						sp++;
					}
				false++;
			}
		else
			{
				 if(sp!=1)
					 {
						 for(k=0;k<sp;k++)
							 {
									if(stack[k].num==s[i])
											break;
							 }
						 temp=stack[k];
						 for(k=k;k<sp-1;k++)
							 {
								 stack[k]=stack[k+1];
							 }
						 stack[sp-1]=temp;
					 }
			}
	for(k=0;k<num;k++)
		{
			gotoxy(6*i+1,k+1);
			cprintf("%5x ",stack[k].num);
		}
	getch();
	}
	per=((float)false/12.00)*100.00;
	gotoxy(73,6);
	cprintf("%2.1f",per);
	return;
}

