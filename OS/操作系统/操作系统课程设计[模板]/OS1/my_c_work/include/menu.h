
#ifndef  MENU_H
#define  MENU_H
 
#include <dos.h>
#include <fcntl.h>
#include <io.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "ggg.h"


typedef struct button
{
       int start_x;
        int start_y;
        int end_x;
        int end_y;
        char *text;
        void (*action)();
        int mousedown;
        int mouseover;
        void (*onmouseover)(struct button *);
        void (*onmouseout)(struct button *);
		void (*onmouseclick)(struct button *);
        struct button *link;
}button;
typedef struct buttonlist
{
        button *next;
}buttonlist;
buttonlist *btlist=NULL;
void click(struct button *b);
void over(struct button *p);
void out(struct button *p);
void init_but(button *b,int st_x,int st_y,int e_x,int e_y,char *txt,void (*act)(),void (*ove)(),void (*ou)())
{
        b->start_x=st_x;
        b->start_y=st_y;
        b->end_x=e_x;
        b->end_y=e_y;
        b->text=txt;
        b->action=act;
        b->onmouseover=ove;
        b->mouseover=0;
        b->mousedown=0;
        b->onmouseout=ou;
		b->onmouseclick=click;
        b->link=NULL;
}
void btinsert(button *b)
{
        button *temp;
        if(btlist==NULL)
        {
           btlist=(buttonlist *)malloc(sizeof(buttonlist));
           btlist->next=NULL;
        }
        if(btlist->next==NULL)
        {
                        btlist->next=b;
        }
        else
        {
                temp=btlist->next;
                while(temp->link!=NULL)
        	{
                        	temp=temp->link;
        	}
                temp->link=b;
        }
}
button *createbutton(int st_x,int st_y,int e_x,int e_y,char *txt,void (*act)())
{
        button *temp;
        temp=(button *)malloc(sizeof(button));
        init_but(temp,st_x,st_y, e_x, e_y,txt,act,over,out);
        return temp;
}
void pt()
{
        rectfill(300,300,640,330,HiColor(BK_COLOR));
        string_out("you click mouse in button 1!",300,300);
}
void pt2()
{       rectfill(300,300,640,330,HiColor(BK_COLOR));
        string_out("you click mouse in button 222222!",300,300);
}
void button_fill(button *bb)
{       int color;
        color=0x477bf5;
        /*
        x=bb->start_x;
        y=bb->start_y;
        for (yy = 0; yy < bb->end_y-bb->start_y;++yy)
   {
      
      line(x+1, y+yy, bb->end_x,y+yy,r|g|b);
      if(yy%2==0)
        {
        r=62;
        g=117;
        b=244;
         }
      else
      {
      r=71;
        g=123;
        b=245;
      }
   }
   line(x, y, bb->end_x,y,HiColor(0xffffff));
   line(x, y, x,bb->end_y,HiColor(0xffffff));
   line(x+1, bb->end_y, bb->end_x,bb->end_y,HiColor(0x000000));
   line(bb->end_x, y+1, bb->end_x,bb->end_y ,HiColor(0x000000));
   */
   line(bb->start_x,bb->start_y,bb->end_x,bb->start_y,HiColor(0xffffff));
   line(bb->start_x,bb->start_y,bb->start_x,bb->end_y,HiColor(0xffffff));
   rectfill(bb->start_x+1,bb->start_y+1,bb->end_x-1,bb->end_y-1,HiColor(color));
   line(bb->start_x, bb->end_y, bb->end_x,bb->end_y,HiColor(0x000000));
   line(bb->end_x, bb->start_y, bb->end_x,bb->end_y ,HiColor(0x000000));
   string_out(bb->text,bb->start_x+15,bb->start_y+(bb->end_y-bb->start_y)/3);

}
void click(struct button *bb)
{
	int color;
        color=0x477bf5;
	 if(bb->mousedown==0)
        {
		  hide_mouse();
		  rectfill(bb->start_x+1,bb->start_y+1,bb->end_x-1,bb->end_y-1,HiColor(color+0xff0000));
		  string_out(bb->text,bb->start_x+15,bb->start_y+(bb->end_y-bb->start_y)/3);
		  show_mouse();
		 bb->action();
		 bb->mousedown=1;
        }
}
void over(struct button *p)
{
       /* rectfill(400,400,640,450,HiColor(BK_COLOR));
        string_out(p->text,400,400);
        */
       hide_mouse();
       rect(p->start_x,p->start_y,p->end_x,p->end_y,HiColor(0x0000ff));
	rect(p->start_x+1,p->start_y+1,p->end_x-1,p->end_y-1,HiColor(0xffff00));
      show_mouse();


}
void out(struct button *bb)
{       /*
        rectfill(400,400,640,450,HiColor(BK_COLOR));
        string_out(p->text,400,400); */ 
        hide_mouse(); 
   button_fill(bb);
    show_mouse();
}

void chk_mouse()
{
        int x,y;
        button *b;
        x=get_mouse_x();
        y=get_mouse_y();
        b=btlist->next;
        while(b!=NULL)
        {
			     
                if(get_click_info()==1)
                {
                        if(x>b->start_x&&x<b->end_x&&y>b->start_y&&y<b->end_y)
                        {
                          b->onmouseclick(b);
                        }

                }
				else
                {
                       if(x>b->start_x&&x<b->end_x&&y>b->start_y&&y<b->end_y)
                        {
						    
                                if(b->mouseover!=1)
                                {
								
                                b->onmouseover(b);
                                b->mouseover=1;
                                }
                        }
                        else
                        {      if(b->mouseover==1)
                                {
                                b->onmouseout(b);
                                b->mouseover=0;
                                button_fill(b);
                                }
                        }
						
						if(b->mousedown==1)
					{
						hide_mouse();
						 rectfill(b->start_x+1,b->start_y+1,b->end_x-1,b->end_y-1,HiColor(0x477bf5));
						  string_out(b->text,b->start_x+15,b->start_y+(b->end_y-b->start_y)/3);
                         b->mousedown=0;
						show_mouse();
					}
                        
                }
                b=b->link;
				
        }
}
/*
void main()
{  button *b;
   neo_init();
   set_vbe_mode(VBE640X480X64K);
   install_timer(new_1ch_int);
   change_timer(30);
   install_mouse();
   setbkcolor(HiColor(BK_COLOR));
   

  
 
   btinsert(createbutton(100,100,200,125,"创建进程",pt));
   btinsert(createbutton(100,200,200,225,"调度进程",pt2));
   b=btlist->next;
   while(b!=NULL)
   {
   button_fill(b);
   b=b->link;
   }
   while(!kbhit()){
               
                mouse_refresh();
                  hide_mouse();
                 show_mouse();

                chk_mouse();
                LOOP_END_OF_TIMER();
    }
     getch();

}
*/
#endif   
