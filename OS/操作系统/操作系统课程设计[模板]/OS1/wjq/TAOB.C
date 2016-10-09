/***************************************************/
/*             The Algorithm of Banker             */
/*								 Author:  WJQ                    */
/***************************************************/

/********Inclode********/
#include <time.h>
#include <conio.h>
#include <bios.h>
#include <stdlib.h>
#include <dos.h>

/********Define*********/

#define enter  0x1c0d
#define esc   0x011b

/********Tpye Variable********/
typedef struct process{
int work[3];
int allocation[3];
int need[3];
int finish;
}processes;

processes proc[10];
int stack[50];
int num;
int Available1[3];
int Available[3];
int sp=0;
char table1[]={218,196,196,196,194,196,196,196,196,196,196,196,196,
							196,196,196,196,194,196,196,196,196,196,196,196,196,
							196,196,196,196,194,196,196,196,196,196,196,196,196,
							196,196,196,196,194,196,196,196,196,196,196,196,196,
							196,196,196,196,191};
char table2[]={195,196,196,196,197,196,196,196,196,196,196,196,196,
							196,196,196,196,197,196,196,196,196,196,196,196,196,
							196,196,196,196,197,196,196,196,196,196,196,196,196,
							196,196,196,196,197,196,196,196,196,196,196,196,196,
							196,196,196,196,180};
char table3[]={192,196,196,196,193,196,196,196,196,196,196,196,196,
							196,196,196,196,193,196,196,196,196,196,196,196,196,
							196,196,196,196,193,196,196,196,196,196,196,196,196,
							196,196,196,196,193,196,196,196,196,196,196,196,196,
							196,196,196,196,217};
/********Tpye Function*********/
void vCreat()
{
	int i,k,mini;
	Available[0]=10;
	Available[1]=5;
	Available[2]=7;
	for(i=0;i<5;i++)
	{
		proc[i].finish=0;
		proc[i].work[0]=random(10);
		proc[i].work[1]=random(5);
		proc[i].work[2]=random(7);
		for(k=0;k<3;k++)
		{
			if(proc[i].work[k]<Available[k])
				mini=proc[i].work[k];
			else
				mini=Available[k];
			if(mini>0)
				proc[i].allocation[k]=random(mini);
			else
				proc[i].allocation[k]=mini;
			Available[k]-=proc[i].allocation[k];
			Available1[k]=Available[k];
			proc[i].need[k]=proc[i].work[k]-proc[i].allocation[k];
		}
	}
}

void vDisplay()
{
	int i,k,ii;
	window(1,1,80,25);
	clrscr();
	gotoxy(11,3);
	for(i=0;i<57;i++)
		printf("%c",table1[i]);
	for(i=0;i<57;i++)
		if((i==0)||(i==4)||(i==17)||(i==30)||(i==43)||(i==56))
			{gotoxy(11+i,4);putch(179);}
	gotoxy(20,4);cputs("Work");
	gotoxy(33,4);cputs("Need");
	gotoxy(43,4);cputs("Allocation");
	gotoxy(57,4);cputs("Available");
	for(i=0;i<57;i++)
		if((i==0)||(i==4)||(i==17)||(i==30)||(i==43)||(i==56))
			{ gotoxy(11+i,5);putch(179);}
	gotoxy(17,5);cputs(" A   B   C");
	gotoxy(30,5);cputs(" A   B   C");
	gotoxy(43,5);cputs(" A   B   C");
	gotoxy(56,5);cputs(" A   B   C");
	gotoxy(11,6);
	for(i=0;i<57;i++)
		printf("%c",table2[i]);
	for(ii=0;ii<5;ii++)
	{
		for(i=0;i<57;i++)
			if((i==0)||(i==4)||(i==17)||(i==30)||(i==43)||(i==56))
				{ gotoxy(11+i,7+ii*2);putch(179);
					if(ii<4)
					{gotoxy(11+i,8+ii*2);putch(179);}}
		gotoxy(13,7+2*ii);printf("%d",ii);
		for(i=0;i<3;i++)
			{
				gotoxy(16+i*4,7+ii*2);printf("%3d",proc[ii].work[i]);
				gotoxy(29+i*4,7+ii*2);printf("%3d",proc[ii].need[i]);
				gotoxy(42+i*4,7+ii*2);printf("%3d",proc[ii].allocation[i]);
			}
	}
	gotoxy(11,16);
	for(i=0;i<57;i++)
		printf("%c",table3[i]);
	gotoxy(55,7);
	for(i=0;i<3;i++)
	{	gotoxy(55+i*4,7);printf("%3d",Available1[i]);}
	gotoxy(2,20);
	cputs("The Queue of Tenor is");
	if(sp==5)
		{
			cputs(" SafeQueue!");
			for(i=0;i<sp;i++)
				cprintf("%d,",stack[i]);
		}
	else
		cputs(" not safe!");
	window(1,18,80,19);
	clrscr();
}

int iAOB()
{
	int i,k;
	int AOB;
	int state=0;
	int tnum=0;
	for(i=0;i<5;i++)
	{
		if(proc[i].finish==0)
		{
			state=0;
			for(k=0;k<3;k++)
			{
				if(proc[i].need[k]<=Available[k])
					state++;
				else break;
			}
			if(state==3)
			{
				proc[i].finish=1;
				for(k=0;k<3;Available[k]+=proc[i].allocation[k],k++);
				printf("+%d,",i);
				getch();
				stack[sp]=i;
				sp++;
				AOB=iAOB();
				if(AOB==1)
				{
					return 1;
				}
				else
				{
					for(k=0;k<3;Available[k]-=proc[i].allocation[k],k++);
					proc[i].finish=0;
					sp--;
					printf("-%d,",i);
					getch();
				}
			}
		}
		else {tnum++;continue;}
	}
	if(tnum==5)	return 1;
	else return 0;
}

void vCpCtrl()
{
	union REGS r;
	r.h.ah=1;
	r.h.ch=1;
	r.h.cl=0;
	int86(0x10,&r,&r);
}

main()
{
	int i;
	int key;
	int state=1;
	textcolor(7);
	clrscr();
	vCpCtrl();
	randomize();
	gotoxy(28,1);
	cputs("THE ALGORITHM OF BANKER");

	for(;;)
	{
		vCreat();
		window(1,1,80,25);
		gotoxy(1,24);
		cputs("IF YOU WANT TO APPLY PLEASE PRESS ENTER,OR PRESS ESC.");
		key=bioskey(0);
		switch(key)
		{
			case enter:
				{
					 state=1;
					 gotoxy(1,1);
					 vDisplay();
					 iAOB();
					 vDisplay();
					 sp=0;
					 break;
				}
			case esc:
				{
					 state=0;
					 break;
				}
			default:
				break;
		}
		if(state==0) break;
	}
	gotoxy(38,12);
	cputs("EXIT");
}
