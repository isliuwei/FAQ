/********************************************************************/
/*                    The Assignment of Tenor                       */
/*                        Author:   wjq                             */
/********************************************************************/

#include <conio.h>
#include <bios.h>
#include <dos.h>
#include <time.h>
#include <stdlib.h>

#define  keyleft   0x4b00
#define  keyright  0x4d00
#define  enter     0x1c0d


/*************Type Variable****************/
typedef struct Tenor{
	char name[4];
	int timein;
	int timesv;
	int level;
}tenor;

tenor tenors[20];
int num;
int timep;
/*************Type Function****************/
void vSort(int state);
void vFCFS();
void vSJF();
void vTIME();
int iMainDisplay();
void vCreateTenor();
void vCpCtrl(int i);
void vDisplay();

void vSort(int state)
{
	int i,k,now;
	tenor temp;
	for(i=0;i<num;i++)
		{
			now=i;
			for(k=i+1;k<num;k++)
				{
					if(state==1)
						 if(tenors[now].timein<tenors[k].timein)
								now=now;
						 else
								now=k;
					if(state==2)
						 if(tenors[now].timesv<tenors[k].timesv)
								now=now;
						 else
								now=k;
				}
			temp=tenors[i];tenors[i]=tenors[now];tenors[now]=temp;
		}

}

main()
{
	int a;
	textbackground(0);
	clrscr();
	vDisplay();
	for(;;)
	{
		if(iMainDisplay()==1)
			break;
		vCreateTenor();
		vFCFS();
		vSJF();
		vTIME();
	}

}
void vCreateTenor()
{
	int i,k,same,temp;
	randomize();
	tenors[0].name[0]='A';
	tenors[0].name[1]='\0';
	tenors[0].timein=random(num);
	while(!(tenors[0].timesv=random(8)));
	for(i=1;i<num;i++)
	{
		same=0;
		while(same<i)
		{
			temp=random(num);
			for(k=0;k<i;k++)
			{
				if(temp==tenors[k].timein)
					{
						same=0;
						break;
					}
				else
					same++;
			}
		}
		tenors[i].name[0]='A'+i;
		tenors[i].name[1]='\0';
		tenors[i].timein=temp;
		while(!(tenors[i].timesv=random(8)));
	}
	window(21,2,80,2);
	textbackground(7);
	clrscr();
	for(i=0;i<num;i++)
	{
		cprintf("    %s",tenors[i].name);
	}
	window(21,3,80,4);
	textbackground(0);
	clrscr();
	for(i=0;i<num;i++)
	{
		gotoxy(i*5+1,1);
		cprintf("%5d",tenors[i].timein);
		gotoxy(i*5+1,2);
		cprintf("%5d",tenors[i].timesv);
	}
}
void vFCFS()
{
	int i,finish,turnover,at;
	float weighted,aw;
	vSort(1);
	window(21,5,80,5);
		textbackground(7);
		clrscr();
		for(i=0;i<num;cprintf("    %s",tenors[i].name),i++);
		gotoxy(52,1);
		cputs("AVERAGE");
	window(21,6,80,8);
		textbackground(0);
		clrscr();
		finish=0;
		at=0;aw=0.0;
		for(i=0;i<num;i++)
		{
			 gotoxy(i*5+1,1);
			 cprintf("%5d",finish+=tenors[i].timesv);
			 gotoxy(i*5+1,2);
			 cprintf("%5d",turnover=finish-tenors[i].timein);
			 at+=turnover;
			 gotoxy(i*5+1,3);
			 cprintf("%5.2f",weighted=(float)turnover/tenors[i].timesv);
			 aw+=weighted;
		}
	 gotoxy(53,2);
	 cprintf("%5.2f",(float)at/num);
	 gotoxy(53,3);
	 cprintf("%5.2f",(float)aw/num);

}
void vSJF()
{
	tenor temp;
	int i,k,finish,now,at,turnover;
	float weighted,aw;
	vSort(1);
	finish=tenors[0].timesv;
	for(i=1;i<num;i++)
	{
			if(tenors[i].timein>finish)
			{
				for(k=i;k<num;k++)
				{
					if(tenors[k].timein<=finish)
						break;
				}
				temp=tenors[i];tenors[i]=tenors[k];tenors[k]=temp;
			}
			now=i;
			for(k=i;k<num;k++)
			{
				if(tenors[k].timein<=finish)
				{
					if(tenors[now].timesv<=tenors[k].timesv)
						now=now;
					else
						now=k;
				}
			}
			temp=tenors[i];tenors[i]=tenors[now];tenors[now]=temp;
			finish=finish+tenors[i].timesv;
	}
	window(21,9,80,9);
		textbackground(7);
		clrscr();
		for(i=0;i<num;cprintf("    %s",tenors[i].name),i++);
		gotoxy(52,1);
		cputs("AVERAGE");
	window(21,10,80,12);
		textbackground(0);
		clrscr();
		finish=0;
		at=0;
		aw=0.0;
		for(i=0;i<num;i++)
			{
				gotoxy(i*5+1,1);
				cprintf("%5d",finish+=tenors[i].timesv);
				gotoxy(i*5+1,2);
				cprintf("%5d",turnover=finish-tenors[i].timein);
				at+=turnover;
				gotoxy(i*5+1,3);
				cprintf("%5.2f",weighted=(float)turnover/tenors[i].timesv);
				aw+=weighted;
			}
	gotoxy(53,2);
	cprintf("%5.2f",(float)at/num);
	gotoxy(53,3);
	cprintf("%5.2f",(float)aw/num);
}


void vTIME()
{
	int i,k,finish,at,turnover,timesv[20],finash[20],turn[20],weigh[20];
	float weighted,aw;
	int nos=num,times=0;
	vSort(1);
	for(i=0;i<num;i++)
		{
			timesv[i]=tenors[i].timesv;
		}
	window(1,18,80,23);
	textbackground(0);
	clrscr();
	while(nos>0)
	{
		for(k=0;k<num;k++)
			{
				for(i=0;i<timep;i++)
					{
						if(tenors[k].timesv>0)
							{
								tenors[k].timesv--;
								textcolor(k+2);
								cputs(tenors[k].name);

								times++;
								if(tenors[k].timesv==0)
									{
										nos--;
										finash[k]=times;
										break;
									}
							}
					}
				if(nos==0)
					break;
			}
	}
	window(21,13,80,13);
	textbackground(7);
	textcolor(15);
	clrscr();
	for(i=0;i<num;cprintf("    %s",tenors[i].name),i++);
	gotoxy(52,1);
	cputs("AVERAGE");
	window(21,14,80,16);
	textbackground(0);
	clrscr();
	at=0;
	aw=0.0;
	for(i=0;i<num;i++)
	{
		gotoxy(i*5+1,1);
		cprintf("%5d",finash[i]);
		gotoxy(i*5+1,2);
		cprintf("%5d",turnover=finash[i]-timesv[i]);
		at+=turnover;
		gotoxy(i*5+1,3);
		cprintf("%5.2f",weighted=(float)turnover/timesv[i]);
		aw+=weighted;
	}
	gotoxy(53,2);
	cprintf("%5.2f",(float)at/num);
	gotoxy(53,3);
	cprintf("%5.2f",(float)aw/num);

}



void vDisplay()
{
	window(1,2,10,16);
		textbackground(3);
		textcolor(15);
		clrscr();
		gotoxy(2,2);
		cputs("INSTANCE");
		gotoxy(2,6);
		cputs("  FCFS  ");
		gotoxy(2,10);
		cputs("   SJF  ");
		gotoxy(2,14);
		cputs("  TIME  ");
	window(11,2,80,2);
		textbackground(7);
		clrscr();
		cputs("     NAME:");
	window(11,3,80,4);
		textbackground(0);
		gotoxy(1,1);
		cputs("    REACH:");
		gotoxy(1,2);
		cputs("   SERVER:");
	window(11,5,80,5);
		textbackground(7);
		clrscr();
		cputs("     NAME:");
		window(11,6,80,8);
		textbackground(0);
		gotoxy(1,1);
		cputs("   FINISH:");
		gotoxy(1,2);
		cputs(" TURNOVER:");
		gotoxy(1,3);
		cputs(" WEIGHTED:");
	window(11,9,80,9);
		textbackground(7);
		clrscr();
		cputs("     NAME:");
		window(11,10,80,12);
		textbackground(0);
		gotoxy(1,1);
		cputs("   FINISH:");
		gotoxy(1,2);
		cputs(" TURNOVER:");
		gotoxy(1,3);
		cputs(" WEIGHTED:");
	window(11,13,80,13);
		textbackground(7);
		clrscr();
		cputs("     NAME:");
	window(11,14,80,16);
		textbackground(0);
		clrscr();
		gotoxy(1,1);
		cputs("   FINISH:");
		gotoxy(1,2);
		cputs(" TURNOVER:");
		gotoxy(1,3);
		cputs(" WEIGHTED:");
 window(1,17,80,17);
	textbackground(1);
	clrscr();
	gotoxy(2,1);
	putch(254);
	gotoxy(79,1);
	putch(254);
	gotoxy(24,1);
	cputs("Display The Queue of Pieces of Time");
 window(1,18,80,23);
	textbackground(0);
	clrscr();
}


int iMainDisplay()
{
	int key,st;
	window(1,1,80,1);
		textbackground(1);
		textcolor(15);
		clrscr();
		gotoxy(2,1);
		putch(254);
		gotoxy(28,1);
		cputs("The Assignment of Tenor");
		gotoxy(79,1);
		putch(254);
	window(1,23,80,23);
		textbackground(1);
		clrscr();
		gotoxy(2,1);
		putch(254);
		gotoxy(37,1);
		cputs("CONTROL");
		gotoxy(79,1);
		putch(254);
	window(1,24,80,25);
		textbackground(3);
		clrscr();
	window(50,25,80,25);
		textbackground(3);
		textcolor(15);
		clrscr();
		gotoxy(10,1);
		textbackground(2);
		cputs(" >  OK  < ");
		gotoxy(20,1);
		textbackground(3);
		cputs("   EXIT   ");
		window(1,24,80,24);
			textbackground(3);
			textcolor(14);
			cputs("INPUT THE NUM OF TENORS:");
			gotoxy(31,1);
			cputs("INPUT THE PIECE OF TIME:");
		window(55,24,60,24);
			textbackground(0);
			clrscr();
		window(25,24,30,24);
			textbackground(0);
			textcolor(7);
			clrscr();
			vCpCtrl(2);
			scanf("%d",&num);
		window(55,24,60,24);
			clrscr();
			scanf("%d",&timep);
			vCpCtrl(1);
			st=0;
			window(50,25,80,25);
				for(;;)
					{
						 key=bioskey(0);
						 textcolor(15);
						 switch(key)
							{
								case keyleft:
									{
										if(st==0)
											break;
										else
											{
												st--;
												textbackground(2);
												gotoxy(10,1);
												cputs(" >  OK  < ");
												textbackground(3);
												gotoxy(20,1);
												cputs("   EXIT   ");
												break;
											}
									}
								case keyright:
									{
										if(st==1)
											break;
										else
											{
												st++;
												textbackground(3);
												gotoxy(10,1);
												cputs("    OK    ");
												textbackground(2);
												gotoxy(20,1);
												cputs(" > EXIT < ");
												break;
											}
									 }
								case enter:
									{
										if(st==0)
											{
												return 0;
											}
										else
											return 1;
									}
							}
					}

}

void vCpCtrl(int i)
{
	union	REGS r;
	r.h.ah=1;
	if(i==1)
		{
			r.h.ch=1;
			r.h.cl=0;
		}
	else
		{
			r.h.ch=6;
			r.h.cl=7;
		}
	int86(0x10,&r,&r);
}