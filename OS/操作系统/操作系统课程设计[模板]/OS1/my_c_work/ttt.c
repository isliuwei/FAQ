#include <dos.h>
#include <fcntl.h>
#include <io.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "ggg.h"
#include "os.h"
#include "menu.h"


void draw_bar()
{   int y,color,yy;
    setbkcolor(HiColor(BK_COLOR));
    rect(0,0,SCREEN_W-1,SCREEN_H-1,HiColor(0xC0C0C0));

    for (color = 652, y = 92,yy=1; y <121; ++y, color += 2048,++yy)
   {
     hline(1,yy,480,color);
   }
   /* rectfill(1, 1, 480, 30,HiColor(0xFFFFFF));     */

    line(481,1,481,430,HiColor(0xFFFFFF));
    hline(1,434,SCREEN_W-2,HiColor(0xFFFFFF));

}

char *input(char *text)
{
    char *in;
    int i=0;
    in=calloc(12,sizeof(char));
      showMessage(text);
        in[i]=getch();
      while(in[i]!=13)
        {
      rectfill(5, 455, 5+(8*10), 455, HiColor(BK_COLOR));
      string_out(in,5,450);
      vsync();
      i++;
      if(i>10){
         return 0;
          }

      in[i]=getch();
      }
      in[i]=0;
      return in;

}
#define PCB_W 60
#define PCB_H 20
#define PCB_LEFT 30
#define LINE_H 10

void draw_PCB(int start_x,int start_y,int end_x,int end_y,int color,PCB *p,int text_color)
{
     set_str_color(HiColor(text_color));
     rectfill(start_x+PCB_LEFT,start_y+LINE_H,end_x-PCB_LEFT,end_y,color);
     line(start_x+PCB_LEFT+(PCB_W/2),start_y,start_x+PCB_LEFT+(PCB_W/2),start_y+LINE_H,0);
     if(p->hasname==1)
     textout(p->name,start_x+PCB_LEFT,start_y+LINE_H+5);
     set_str_color(1);

}
void draw_PCB_point(PCB_point *p)
{ 
     int i=0;
     int start_x,start_y;
     char c;
     PCB *temp;
     rectfill(p->start_x,p->start_y,p->end_x,p->end_y,HiColor(BK_COLOR));
     temp=p->next;
     set_str_color(HiColor(0x00ff00));
     string_out(p->name,p->start_x+10,6);
     for(i=0;i<p->num;i++)
     {
          start_x=p->start_x;
          start_y=p->this_y;
          draw_PCB(start_x,start_y,p->end_x,start_y+PCB_H+LINE_H,p->color,temp,p->text_color);
          p->this_y=start_y+PCB_H+LINE_H;
          temp=temp->link;
     }
     set_str_color(1);


     itoa(p->num,c,10);

     string_out(c,p->this_x,p->this_y);

}
char *show_input()
{
       char *n,*p;

        n=input("请输入进程名:");       
        p=calloc(100,sizeof(char));
        strcpy(p,"输入数据成功，你输入的数据为:  ");
        strcat(p,n);
        showMessage(p);
        return n;

}
void reset_this(PCB_point *p)
{
       p->this_x=p->start_x;
       p->this_y=p->start_y;
}
void create_proess()
{                           char *text;

                            scare_mouse();
                            showMessage("\nplease input text:");
                            /*text=(char *)malloc(100);*/
                            text=show_input();
                            create(text);
                            unscare_mouse();
}
void keymode()
{
        char choice;

        char *msg;
        /*printf("start:\n");   */
        PCB_point_init();
        while(1)
    {
        reset_this(freelist);
        reset_this(runlist);
        reset_this(runablelist);
        reset_this(blocklist);
        draw_PCB_point(freelist) ;
        draw_PCB_point(runlist) ;
        draw_PCB_point(runablelist) ;
        draw_PCB_point(blocklist) ;
        showMessage("请输入操作指令：");
        choice=getch();

                switch(choice)
                 {
                    case 'c':
                            create_proess();
                            break;
                    /*case 's':
                                list();
                                break;*/
                    case 'p':   dispatch();
                                break;
                    case 't':    timeout();
                                break;
                    case 'b':   block();
                                break;
                    case 'w':   wakeup();
                                break;
                    case 'e':
                                quit_PCB();
                                break;
                    case  'x': exit(0);
                 }
        }
}
void quit()
{
        exit(0);
}
#define BUTTON_W 80
#define BUTTON_H 30
void init_menu()
{
     button *b;

     btinsert(createbutton(521,30,521+BUTTON_W,30+BUTTON_H,"创建进程",create_proess));
     btinsert(createbutton(521,90,521+BUTTON_W,90+BUTTON_H,"调度进程",dispatch));
     btinsert(createbutton(521,150,521+BUTTON_W,150+BUTTON_H,"阻塞进程",block));
     btinsert(createbutton(521,210,521+BUTTON_W,210+BUTTON_H,"唤醒进程",wakeup));
     btinsert(createbutton(521,270,521+BUTTON_W,270+BUTTON_H,"时间片到",timeout));
     btinsert(createbutton(521,330,521+BUTTON_W,330+BUTTON_H,"结束进程",quit_PCB));
     btinsert(createbutton(521,390,521+BUTTON_W,390+BUTTON_H,"退出程序",quit));
     b=btlist->next;
        while(b!=NULL)
   {
   button_fill(b);
   b=b->link;
   }
}
void update(PCB_point *t)
{
        if(t->changed)
        {
               reset_this(t);
               draw_PCB_point(t) ;
               t->changed=0;
        }
}
void main()
{
        char *n,*p;
        PCB_point *li;
        neo_init();
        set_vbe_mode(VBE640X480X64K);
        install_timer(new_1ch_int);
        /*change_timer(50);  */
         /*set_cn_size(0);  */
        install_mouse();
        /*设置鼠标移动范围*/
        set_mouse_range(0, 0, SCREEN_W, SCREEN_H);
        draw_bar();
        PCB_point_init();
        /*
        keymode();
        draw_PCB(0,31,120,31+PCB_H+LINE_H,HiColor(0xFF0000));
        li=(PCB_point *)malloc(sizeof(PCB_point));
        set_PCB_point(li,NULL,10,10,0,31,120,431,HiColor(0xFF0000));
         draw_PCB_point(li) ;            */
        init_menu();

        while(1){

                update(freelist);
                update(runlist);
                update(runablelist);
                update(blocklist);

                mouse_refresh();
                chk_mouse();
                LOOP_END_OF_TIMER();
        }

        showMessage("按任意键退出！");
        getch();
        quit();

}
