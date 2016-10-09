/*
        文件摘要：完成各种基本图形模式下函数，结构，变量的声明及定义。
                  有关时钟、鼠标控制的各种函数、结构、全局变量
                  的声明及定义



*/
#ifndef  GGG_H
#define  GGG_H



    /*            以下是基本图形函数的结构，变量，函数的声明及定义 */
#define FALSE 0
#define TRUE  !FALSE
#define F     0
#define T     !F
#define BK_COLOR 0xd4d0c8

#define closegraph()              set_vbe_mode(0x3)
#define getgraphmode()            get_vbe_mode()
#define setgraphmode(mode)        set_vbe_mode(mode)
#define setviewport(l, t, r, b,c) c?screen(l, t, r, b):0
#define getmaxx()                 max_x()
#define getmaxy()                 max_y()
#define setwritemode(mode)        set_draw_mode(mode)
#define setcolor(color)           (g_frt_color = color)
#define setbkcolor(color)         clear_to_color(color)
#define getcolor(color)           g_frt_color
#define setrgbpalette(cn, r, g,b) set_color(cn, r, g, b)
#define putpixel(x, y, color)     dot(x, y, color)
#define getpixel(x, y)            get_dot(x, y)
#define bar(x0, y0, x1, y1)       rectfill(x0-1, y0-1, x1-1, y1-1, g_frt_color)
#define rectangle(x0, y0, x1, y1) rect(x0, y0, x1, y1, g_frt_color)
#define textcolor(color)          set_str_color(color)
#define outtextxy(x, y, str)      textout(str, x, y)
#define textwidth()               textheight()
#define  _WHITE   0xf
#define  _BLACK   0

#define  max_x()  g_screen_h
#define  max_y()  g_screen_v
#define  get_color_depth() g_color_depth

#define  VBE320X200X256   0X13
#define  VBE640X400X256   0X100
#define  VBE640X480X256   0X101
#define  VBE800X600X256   0X103
#define  VBE1024X768X256  0X105
#define  VBE1280X1024X256 0X107

#define  VBE320X200X32K   0X10D
#define  VBE640X480X32K   0X110
#define  VBE800X600X32K   0X113
#define  VBE1024X768X32K  0X116
#define  VBE1280X1024X32K 0X119

#define  VBE320X200X64K   0X10E
#define  VBE640X480X64K   0X111
#define  VBE800X600X64K   0X114
#define  VBE1024X768X64K  0X117
#define  VBE1280X1024X64K 0X11A

#define  SCREEN_W    g_screen_h
#define  SCREEN_H    g_screen_v


enum COLORS
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
};

enum TPTCOLOR
{
   TPT8,
   TPT15 = 0X7C1F,
   TPT16 = 0XF81F,
   TPT24 = 0XFF00FFL,
   TPT32 = 0XFF00FFL,
};
    
enum DRAWIMAGEOPS
{
   COPY_PUT,
   XOR_PUT,
   OR_PUT,
   AND_PUT,
   NOT_PUT
};

typedef struct RGB
{
   unsigned char r;
   unsigned char g;
   unsigned char b;
}RGB, *RGB_ptr;


typedef struct PIC_RGB
{
   unsigned char blue;
   unsigned char green;
   unsigned char red;
   unsigned char reserved;
}PIC_RGB, *PIC_RGB_ptr;


/*
ModeInfoBlock STRUC

; 强制信息

ModeAttributes dw ? ; 模式属性

WinAAttributes db ? ; 窗口A属性

WinBAttributes db ? ; 窗口B属性

WinGranularity dw ? ; 窗口间隔尺寸

WinSize dw ? ; 窗口大小

WinASegment dw ? ; 窗口A开始段地址

WinBSegment dw ? ; 窗口B开始段地址

WinFuncPtr dd ? ; 窗口函数指针

BytesPerScanLine dw ? ; 每行字节数

; 过去的可选信息（现在是强制信息）

XResolution dw ? ; 水平分辨率

YResolution dw ? ; 垂直分辨率

XCharSize db ? ; 字符单元宽度

YCharSize db ? ; 字符单元高度

NumberOfPlanes db ? ; 内存平面数

BitsPerPixel db ? ; 每点的位数

NumberOfBanks db ? ; 存储区数

MemoryModel db ? ; 内存模式类型

BankSize db ? ; 存储区K字节数

NumberOfImagePages db ?; 图象数

Reserved db 1 ; 保留给页函数

; 新的直接色彩区域

RedMaskSize db ? ; 红色遮盖位数

RedFieldPosition db ? ; 红色遮盖位址

GreenMaskSize db ? ; 绿色遮盖位数

GreenFieldPosition db ? ; 绿色遮盖位址

BlueMaskSize db ? ; 兰色遮盖位数

BlueFieldPosition db ? ; 兰色遮盖位址

RsvdMaskSize db ? ; 直接色彩保留遮盖位数

RsvdFieldPosition db ? ; 直接色彩保留遮盖位址

DirectColorModeInfo db ? ; 直接色彩模式属性

Reserved db 216 dup(?) ; 模式信息块剩余

ModeInfoBlock ENDS
*/
typedef struct ModeInfoBlock
{
unsigned short mode_attributes; /* Mode attributes */
unsigned char  win_a_attributes; /* Window A attributes */
unsigned char  win_b_attributes; /* Window B attributes */
unsigned short win_granularity; /* Window granularity in k */
unsigned short win_size; /* Window size in k */
unsigned short win_a_segment; /* Window A segment */
unsigned short win_b_segment; /* Window B segment */
void (far *win_func_ptr)(void); /* Pointer to window function */
unsigned short bytes_per_scan_line; /* Bytes per scanline */
unsigned short x_resolution; /* Horizontal resolution */
unsigned short y_resolution; /* Vertical resolution */
unsigned char  x_char_size; /* Character cell width */
unsigned char  y_char_size; /* Character cell height */
unsigned char  number_of_planes; /* Number of memory planes */
unsigned char  bits_per_pixel; /* Bits per pixel */
unsigned char  number_of_banks; /* Number of CGA style banks */
unsigned char  memory_model; /* Memory model type */
unsigned char  bank_size; /* Size of CGA style banks */
unsigned char  number_of_image_pages; /* Number of images pages */
unsigned char  res1; /* Reserved */
unsigned char  red_mask_size; /* Size of direct color red mask */
unsigned char  red_field_position; /* Bit posn of lsb of red mask */
unsigned char  green_mask_size; /* Size of direct color green mask */
unsigned char  green_field_position; /* Bit posn of lsb of green mask */
unsigned char  blue_mask_size; /* Size of direct color blue mask */
unsigned char  blue_field_position; /* Bit posn of lsb of blue mask */
unsigned char  rsvd_mask_size; /* Size of direct color res mask */
unsigned char  rsvd_field_position; /* Bit posn of lsb of res mask */
unsigned char  direct_color_mode_info; /* Direct color mode attributes */
unsigned char  res2[216]; /* Pad to 256 byte block size */
}mode_info_t;



#define PAL_SIZE     256
typedef RGB PALLETE[PAL_SIZE];
#define PALETTE      PALLETE
/*     全局变量      */
char g_routines = 0;     /*最低位为1:处于图形模式;第2位为1:高级鼠标例程被加载;第3位为1:时钟例程被加载;第4位为1:键盘
　　　　　　　　　　　　　例程被加载;*/


float   g_time_factor = 0.055;
double  g_time_total  = 0.0;
float  g_time_cnt = 0;
unsigned g_block_num = 0; /*要分几次读取*/
int      g_block_cnt = -1; /*已经读了几次*/
float    g_block_time= 0.0; /*读取一次能播放的时间*/
unsigned char g_play_mode = 1;


char far *g_videoptr = (char far *)0xa0000000;
char g_page_num;
char g_green_mask = 0;
char g_green_bit  = 0;
char g_color_depth = 0;   /*记录当前图形模式的色深，为0表示非图形模式*/
int  g_screen_h;          /*当前分辨率下的屏幕宽度*/
int  g_screen_v;          /*当前分辨率下的屏幕高度*/
long g_screen_size;       /*记录当前图形模式的屏幕面积*/
unsigned g_blit_fix;      /*目前用于blit()函数的临时变量*/
int  g_cur_vbe_page = 0;  /*当前所处的显示页*/
/*----------------------------------------------------------------------------------------------------*/
int  g_frt_color = 1;
int  g_tptcolor  = 0;     /*指定透明色(Transparent color)*/
char g_draw_mode = 0;     /*绘图模式,分为COPY_PUT,XOR_PUT,OR_PUT,AND_PUT,NOT_PUT,与TC中Graphics的绘图模式意义相同*/
/*以下4个变量用来支持裁剪输出,分别代表裁剪区域的左上角及右下角坐标*/
int  g_rect_left;
int  g_rect_right;
int  g_rect_top;
int  g_rect_bottom;
char g_dac_size_fix = 2;    /*记录DAC调色板宽度修正值，由8-当前DAC宽度得来，默认为2*/


char get_page_num();
char screen(unsigned left, unsigned top, unsigned right, unsigned bottom);
void show_mouse();     /*鼠标图形光标显示.*/
void hide_mouse();     /*鼠标图形光标隐藏.*/
void vsync();

/*            函数开始             */


int HiColor(long truecolor)
{

unsigned long red,green,blue,hicolor;
red=(truecolor>>8)&0xf800;
green=(truecolor>>5)&0x7e0;
blue=(truecolor>>3)&0x1f;
hicolor=red|green|blue;
return  hicolor;
}


void vsync()
{
   while  ( inportb(0x3da)&0x08 ) ;
   while (!(inportb(0x3da)&0x08)) ;
}


char set_vbe_mode(int mode)
{
   mode_info_t mode_info;
   struct SREGS segs;
   union REGS r;
   char far *modeinfo = (char far *)&mode_info;

   r.x.ax = 0x4f02;
   r.x.bx = mode;
   int86(0x10, &r, &r);

   if (mode < 0x100)
   {
      if (mode == 0x13)
      {
         g_color_depth = 8;
         g_rect_left   = g_rect_top = 0;
         g_rect_right  = (g_screen_h = 320) - 1;
         g_rect_bottom = (g_screen_v = 200) - 1;
         g_screen_size = g_screen_h * g_screen_v;
         g_tptcolor = TPT8;
         screen(0, 0, g_rect_right, g_rect_bottom);
         return TRUE;
      }
      else
         return FALSE; /* Ignore non-VBE modes */
   }
   else
   {
      r.x.ax = 0x4f01;
      /*
01h-返回超级VGA模式信息

该函数返回一个指定的超级VGA显示模式的相关信息。该函数根据调用者给定的地址填充一个模式信息块。模式信息块最大为256K。

此函数返回的一些信息是由VESA模式号暗中定义的。但是一些超级VGA可能支持其它的显示模式而不是由VESA所定义的。为了提供对该模式的访问，函数也返回一些各种各样的相关信息。

输入：AH = 4Fh 超级VGA支持

AL = 01h 返回超级VGA模式信息

CX = 超级VGA模式号（模式号必须为函数00h返回值之一）

ES:DI = 256字节缓冲区指针

输出：AX = 状态


      */
      r.x.cx = mode;
      r.x.di = FP_OFF(modeinfo);
      segs.es = FP_SEG(modeinfo);
      int86x(0x10, &r, &r, &segs);
      if (r.x.ax != 0x4F) return FALSE;
/*
 状态信息

函数向AX寄存器返回一个状态信息。状态字的格式如下：

AL==4Fh 函数被支持

AL!=4Fh 函数不被支持

AH==00h 函数调用成功

AH==01h 函数调用失败

当AH寄存器的值为非零时，软件就应该认为是失败。
*/
   }

   switch (mode) /*临时使用*/
   {
      case 0x101:
      g_blit_fix = 45056;
      break;
      case 0x103:
      g_blit_fix = 21248;
      break;
      case 0x105:
      g_blit_fix = 65534;
      break;
      default:
      g_blit_fix = 0;
      break;
   }


   g_green_mask  = mode_info.green_mask_size;
   g_color_depth = mode_info.bits_per_pixel;
   g_rect_left   = g_rect_top = 0;
   g_rect_right  = (g_screen_h = mode_info.x_resolution) - 1;
   g_rect_bottom = (g_screen_v = mode_info.y_resolution) - 1;
   g_screen_size = g_screen_h * g_screen_v;
   screen(0, 0, g_rect_right, g_rect_bottom);

   switch (g_color_depth)
   {

      case 8:
      g_tptcolor = TPT8;
      break;
      case 15:
      g_tptcolor = TPT15;
      g_green_bit= 3;
      break;
      case 16:
      g_tptcolor = TPT16;
      g_green_bit= 2;
      break;
      case 24:
      g_tptcolor = TPT24;
      break;
      case 32:
      g_tptcolor = TPT32;
      break;
      default:
      g_tptcolor = TPT8;
      break;
   }

   g_routines |= 1;
   g_page_num = get_page_num();
   return TRUE;
}

char set_vbe_mode1()
{  int mode;
   mode_info_t mode_info;
   struct SREGS segs;
   union REGS r;
   char far *modeinfo = (char far *)&mode_info;
   mode=0x112;

   r.x.ax = 0x4f02;
   r.x.bx = 0x4112;
   int86(0x10, &r, &r);

   if (mode < 0x100)
   {
      if (mode == 0x13)
      {
         g_color_depth = 8;
         g_rect_left   = g_rect_top = 0;
         g_rect_right  = (g_screen_h = 320) - 1;
         g_rect_bottom = (g_screen_v = 200) - 1;
         g_screen_size = g_screen_h * g_screen_v;
         g_tptcolor = TPT8;
         screen(0, 0, g_rect_right, g_rect_bottom);
         return TRUE;
      }
      else
         return FALSE; /* Ignore non-VBE modes */
   }
   else
   {
      r.x.ax = 0x4f01;
      /*
01h-返回超级VGA模式信息

该函数返回一个指定的超级VGA显示模式的相关信息。该函数根据调用者给定的地址填充一个模式信息块。模式信息块最大为256K。

此函数返回的一些信息是由VESA模式号暗中定义的。但是一些超级VGA可能支持其它的显示模式而不是由VESA所定义的。为了提供对该模式的访问，函数也返回一些各种各样的相关信息。

输入：AH = 4Fh 超级VGA支持

AL = 01h 返回超级VGA模式信息

CX = 超级VGA模式号（模式号必须为函数00h返回值之一）

ES:DI = 256字节缓冲区指针

输出：AX = 状态


      */
      r.x.cx = mode;
      r.x.di = FP_OFF(modeinfo);
      segs.es = FP_SEG(modeinfo);
      int86x(0x10, &r, &r, &segs);
      if (r.x.ax != 0x4F) return FALSE;
/*
 状态信息

函数向AX寄存器返回一个状态信息。状态字的格式如下：

AL==4Fh 函数被支持

AL!=4Fh 函数不被支持

AH==00h 函数调用成功

AH==01h 函数调用失败

当AH寄存器的值为非零时，软件就应该认为是失败。
*/
   }

   switch (mode) /*临时使用*/
   {
      case 0x101:
      g_blit_fix = 45056;
      break;
      case 0x103:
      g_blit_fix = 21248;
      break;
      case 0x105:
      g_blit_fix = 65534;
      break;
      default:
      g_blit_fix = 0;
      break;
   }


   g_green_mask  = mode_info.green_mask_size;
   g_color_depth = mode_info.bits_per_pixel;
   g_rect_left   = g_rect_top = 0;
   g_rect_right  = (g_screen_h = mode_info.x_resolution) - 1;
   g_rect_bottom = (g_screen_v = mode_info.y_resolution) - 1;
   g_screen_size = g_screen_h * g_screen_v;
   screen(0, 0, g_rect_right, g_rect_bottom);

   switch (g_color_depth)
   {

      case 8:
      g_tptcolor = TPT8;
      break;
      case 15:
      g_tptcolor = TPT15;
      g_green_bit= 3;
      break;
      case 16:
      g_tptcolor = TPT16;
      g_green_bit= 2;
      break;
      case 24:
      g_tptcolor = TPT24;
      break;
      case 32:
      g_tptcolor = TPT32;
      break;
      default:
      g_tptcolor = TPT8;
      break;
   }

   g_routines |= 1;
   g_page_num = get_page_num();
   return TRUE;
}

/*获得SVGA的显示模式*/
/*

*/
int get_vbe_mode(void)
{
   _AX = 0x4f03;
   /*
   03h-返回当前显示模式

此函数将当前显示模式返回到BX寄存器。VESA显示模式号在第二章有详细描述。

输入：AH = 4Fh 超级VGA支持

AL = 03h 返回当前显示模式

输出：AX = 状态

BX = 当前显示模式

（其它寄存器保持不变）

   */
   __int__(0x10); 

   return _BX;
}

char get_page_num()
{
   char pages[28] = {4, 5, 4, 8, 6, 12, 10, 20, -1, -1, -1, -1, -1, 2, 2, 3, 10, 10, 15,
                     15, 15,  22, 24, 24, 36, 40, 40, 60};
   int tmp;
   _AX = 0x4f03;
   __int__(0x10);   

   if ((tmp = _BX) >= 0x100)
   {
      return pages[tmp - 256];
   }
   else if (tmp == 0x13)
   {
      return 1;
   }
   return -1;
}

  /*指定剪切输出域(包括边线)*/
char screen(unsigned left, unsigned top, unsigned right, unsigned bottom)
{
   if(left>g_screen_h||top>g_screen_v||right<0||bottom<0||right<=left||bottom<=top)
      {return -1;}
  
   if (left < 0)
      {left = 0;}
   if (top < 0)
      {top = 0;}
   if (right >= g_screen_h)
      {right =  g_screen_h-1;}
   if (bottom >=g_screen_v)
      {bottom = g_screen_v-1;}

   g_rect_left  = left;
   g_rect_right = right;
   g_rect_top   = top;
   g_rect_bottom= bottom;   
}


/*显存换页函数*/
void set_vbe_page(char page)
{
   union REGS r;
   if (g_cur_vbe_page != page)
   {
      r.x.ax=0x4f05;
      r.x.bx=0;
      r.x.dx=g_cur_vbe_page = page;
      int86(0x10, &r, &r);
   }
}

 
void set_palette_range(char *pal_buf, int from, int to, int vsync_flag)
{
   struct REGPACK reg;
   if (from <= to && from >= 0 && from < 256 && to - from < 256)
   {
      if (vsync_flag)
         vsync();
      reg.r_ax = 0x1012;
      reg.r_bx = from;
      reg.r_cx = to - from + 1;
      reg.r_es = FP_SEG(pal_buf);
      reg.r_dx = FP_OFF(pal_buf);
      intr(0x10,&reg);
   }
}


void get_palette_range(char *pal_buf, int from, int to)
{
   struct REGPACK regs;
   if (from <= to && from >= 0 && from < 256 && to - from < 256)
   {
      regs.r_ax = 0x1017;
      regs.r_bx = from;
      regs.r_cx = to - from + 1;
      regs.r_es = FP_SEG(pal_buf);
      regs.r_dx = FP_OFF(pal_buf);
      intr(0x10,&regs);
   }
}


/*---------------------------------------------------*
 *函数功能: 设置硬件调色板中指定颜色号的颜色分量.    *
 *参数说明: index为颜色号.                           *
 *          red,green,blue为此颜色号对应的红,绿,兰三 *
 *          原色分量,均应小于64)                     *
 *返回说明: 成功返回1;否则返回0.                     *
 *备    注: 颜色设置函数.用户程序可直接调用.  　     *
 *---------------------------------------------------*/
char set_color(int index, char red,char green, char blue)
{
   unsigned char color[3];

   color[0] = red;
   color[1] = green;
   color[2] = blue;
   set_palette_range(color, index, index, 0);
   return -1;
}

 /*通用画点函数,速度:17FPS*/
void dot(int x,int y,int color)
{
   long addr;
   int page;
   if ((x<g_rect_left) || (y<g_rect_top) || (x>g_rect_right) || (y>g_rect_bottom)) return;

   if (g_color_depth == 8)
   {

      page = (int)((addr = (long)y * g_screen_h + x) >> 16);

      if (g_cur_vbe_page != page)
      {
         _BX = 0;
         _DX = g_cur_vbe_page = page;
         _AX = 0x4f05;
         __int__(0x10);
      }

      switch(g_draw_mode)
      {
         case COPY_PUT : *(g_videoptr+(addr&0xffff)) = color;break;
         case XOR_PUT  : *(g_videoptr+(addr&0xffff))= *(g_videoptr+(addr& 0xffff))^(char)color;break;
         case NOT_PUT  : *(g_videoptr+(addr&0xffff))=~*(g_videoptr+(addr& 0xffff));break;
         case OR_PUT   : *(g_videoptr+(addr&0xffff))= *(g_videoptr+(addr& 0xffff))|(char)color;break;
         case AND_PUT  : *(g_videoptr+(addr&0xffff))= *(g_videoptr+(addr& 0xffff))&(char)color;break;
      }

      *(g_videoptr+(addr& 0xffff)) = (unsigned char)color;


      x += 0; y+=0; color+=0;

   }
   else /*if (g_color_depth == 16)*/ /*由于只支持256和64K色,所以暂时注释左边一句*/
   {

      int far *videoptr16 = (int far *)0xa0000000;
      page = (int)((addr = (long)y * g_screen_h + x) >> 15);

      if (g_cur_vbe_page != page)
      {
         _BX = 0;
         _DX = g_cur_vbe_page = page;
         _AX = 0x4f05;
         __int__(0x10);
      }

      switch(g_draw_mode)
      {
         case COPY_PUT : *(videoptr16+(addr&0xffff)) = color;break;
         case XOR_PUT  : *(videoptr16+(addr&0xffff))= *(videoptr16+(addr& 0xffff)) ^ color;break;
         case NOT_PUT  : *(videoptr16+(addr&0xffff))=~*(videoptr16+(addr& 0xffff)); break;
         case OR_PUT   : *(videoptr16+(addr&0xffff))= *(videoptr16+(addr& 0xffff)) | color;break;
         case AND_PUT  : *(videoptr16+(addr&0xffff))= *(videoptr16+(addr& 0xffff)) & color;break;
      }

      *(videoptr16 + (addr & 0xffff)) = color;



      x += 0; y+=0; color+=0;

   }
}

int  get_dot(int x, int y)
{
   /*union REGS r;*/
   long addr;
   int page;
   if ((x<0) || (y<0) || (x>g_screen_h) || (y>g_screen_v)) return -1;

   if (g_color_depth == 8)
   {

      page = (int)((addr = (long)y * g_screen_h + x) >> 16);
      if (g_cur_vbe_page != page)
      {
         _BX = 0;
         _DX = g_cur_vbe_page = page;
         _AX = 0x4f05;
         __int__(0x10);
      }
      return (peekb(0xa000,addr & 0xFFFF));

      x+=0; y+=0;

   }
   else
   {

      int far *videoptr = (int far *)0xa0000000;
      page = (int)((addr = (long)y * g_screen_h + x) >> 15);

      if (g_cur_vbe_page != page)
      {
         _BX = 0;
         _DX = g_cur_vbe_page = page;
         _AX = 0x4f05;
         __int__(0x10);
      }
      return *(videoptr + (addr & 0xffff));

      x += 0; y+=0;

   }
}

 /*通用的画线函数，用color颜色由(x1,y1)画到(x2,y2);速度:(16FPS)*/
void line(int x1, int y1, int x2, int y2, unsigned color)
{
   int  dt_x = x2 - x1, dt_y = y2 - y1, step_x, step_y, change;

   if (dt_x < 0)
   {
      dt_x = -dt_x;    /*从右向左画线*/
      step_x = -1;
   }
   else {step_x = 1;}  /*从左向右画线*/

   if (dt_y < 0)
   {
      dt_y = -dt_y;    /*从下向上画线*/
      step_y = -1;
   }
   else {step_y = 1;}
                       /*从上向下画线*/
   if (dt_x > dt_y)    /*x改变得比y快*/
   {
      change = dt_x >> 1;
      while (x1 != x2)
     {
        dot(x1, y1, color);
        x1 += step_x;
        change += dt_y;
        if(change > dt_x)
        {
           y1 += step_y;
           change -= dt_x;
        }
     }
   }
   else                 /*y改变得比x快*/
   {
      change = dt_y >> 1;
      while(y1 != y2)
      {
         dot(x1, y1, color);
         y1 += step_y;
         change += dt_x;
         if(change > dt_y)
         {
            x1 += step_x;
            change -= dt_y;
         }
      }
   }
   dot(x2, y2, color);
}


/*优化后的画水平线函数，用color颜色由(x,y)向右画长为width的水平线;速度: 8位65FPS; 16位32FPS*/
char hline(int x, int y, int width, unsigned color)
{
   long addr;
   int  k = 0;
   int  xx = x;
   int  rect_scr_h = g_rect_right + 1;
   int  len = 0, length/*直线有效长度*/ = 0;
   char page, odd;

   if (width < 0)
   {
      x -= width;
      width = -width;
   }
   if (g_color_depth == 8)
   {

      int origin = 0;
      unsigned char color8 = (unsigned char)color;
      unsigned int  color16 = color8 << 8;

      if ( (y > g_rect_bottom) || (y < g_rect_top) || width < 0)
      {
         return -1;
      }
      if (x >= 0 && x < rect_scr_h)
      {
         if (rect_scr_h - x >= width) /*直线完全显示*/
         {
            len = length = width + 1;
         }
         else                         /*直线右边溢出*/
         {
            len = length = rect_scr_h - x + 1;
         }
      }
      else if (x < 0 && x > (-width))
      {
         if (width + x >= rect_scr_h)  /*直线两端溢出*/
         {
            len = length = rect_scr_h + 1;
            xx = x = 0;
         }
         else                          /*直线左边溢出*/
         {
            len = (length = width + 1) + x;
            x = 0;
         }
      }
      else
      {
         return -1;
      }

      color16 += color8;
      len >>= 1;
      length -= (odd = length % 2);
      origin = (g_rect_left) >> 1;

      page = (char)((addr = (long)(y) * g_screen_h + x) >> 16);
      if (page == (addr + length) >> 16)
      {
         int far *d_tmp = (int far *)(g_videoptr + (addr & 0xffff));

         if (g_cur_vbe_page != page)
         {
            set_vbe_page(page);
         }
         for (; origin < len; ++origin)
         {

            switch(g_draw_mode)
            {
               case COPY_PUT : d_tmp[origin] = color16; break;
               case XOR_PUT  : d_tmp[origin] = d_tmp[origin] ^ color16; break;
               case NOT_PUT  : d_tmp[origin] = ~d_tmp[origin]; break;
               case OR_PUT   : d_tmp[origin] = d_tmp[origin] | color16; break;
               case AND_PUT  : d_tmp[origin] = d_tmp[origin] & color16; break;
            }

            d_tmp[origin] = color16;

         }
      }
      else
      {
            for (;k </*=*/ length; ++k)
               dot(k + xx, y,color8);
      }
      if (odd) dot(xx + length, y, color8);

      x += 0; y += 0; width += 0; color += 0;

      return 0;
   }
   else
   {

      if ( (y > g_rect_bottom) || (y < g_rect_top) || width < 0)
      {
         return -1;
      }
       if (x >= 0 && x < rect_scr_h)
      {
         if (rect_scr_h - x >= width) /*直线完全显示*/
         {
            len = length = width + 1;
         }
         else                         /*直线右边溢出*/
         {
            len = length = rect_scr_h - x + 1;
         }
      }
      else if (x < 0 && x > (-width))
      {
         if (width + x >= rect_scr_h)  /*直线两端溢出*/
         {
            len = length = rect_scr_h + 1;
            xx = x = 0;
         }
         else                          /*直线左边溢出*/
         {
            len = (length = width + 1) + x;
            x = 0;
         }
      }
      else
      {
         return -1;
      }

      page = (char)((addr = (long)(y) * g_screen_h + x) >> 15);
      if (page == (addr + length) >> 15)
      {
         int far *d_tmp = (int far *)(g_videoptr + ((addr<<1) & 0xffff));

         if (g_cur_vbe_page != page)
         {
            set_vbe_page(page);
         }
         for (k = g_rect_left; k < len; ++k)
         {

            switch(g_draw_mode)
            {
               case COPY_PUT : d_tmp[k] = color; break;
               case XOR_PUT  : d_tmp[k] = d_tmp[k] ^ color; break;
               case NOT_PUT  : d_tmp[k] = ~d_tmp[k]; break;
               case OR_PUT   : d_tmp[k] = d_tmp[k] | color; break;
               case AND_PUT  : d_tmp[k] = d_tmp[k] & color; break;
            }

            d_tmp[k] = color;

         }
      }
      else
      {
         for (k = g_rect_left;k < length; ++k)
            dot(k + xx, y, color);
      }

      x += 0; y += 0; width += 0; color += 0;

      return 0;
   }
}


void  rect(int x0, int y0, int x1, int y1, int color)
{
   line(x0,y0,x0,y1,color);
   line(x0,y0,x1,y0,color);
   line(x0,y1,x1,y1,color);
   line(x1,y1,x1,y0,color);
}

void  tri(int xa, int ya, int xb, int yb, int xc, int yc, int col)
{
   line(xa, ya, xb, yb,col);
   line(xb, yb, xc, yc,col);
   line(xc, yc, xa, ya,col);
}

void rectfill(int x1, int y1, int x2, int y2, int color)
{
   int delta, temp;

   if (x1 > x2)
   {
      temp = x1; x1 = x2; x2 = temp;
   }
   if (y1 > y2)
   {
      temp = y1; y1 = y2; y2 = temp;
   }
   delta = x2 - x1;
   for (temp=y1; temp<=y2; ++temp)
   {
      hline(x1, temp, delta, color);
   }
}

/*画圆函数，以(c_x, c_y)为中心画一半径为r的圆*/
void circle(int c_x, int c_y, int r, unsigned char color)
{
   int x = 0, y = r, d0, d1, d2, direction;
   /*x = 0; y = r;*/
   d0 = (1-r)<<1;

   while (y >= 0)
   {
      dot(c_x + x, c_y + y, color);
      dot(c_x - x, c_y - y, color);
      dot(c_x + x, c_y - y, color);
      dot(c_x - x, c_y + y, color);
      if (d0 < 0)
      {
         d1 = (d0 + y)<<1 -1;
         if (d1 <= 0) direction = 1;
         else direction = 2;
      }
      else if (d0 > 0)
      {
         d2 = (d0-x)<<1 - 1;
         if (d2 <= 0) direction = 2;
         else direction = 3;
      }
      else direction = 2;

      switch(direction)
      {
        case 1 : ++x;
           d0 += (x<<1) + 1;
        break;

        case 2 : ++x;
           --y;
           d0+=(x-y+1)<<1;
        break;

        case 3 : --y;
           d0 += -(y<<1) + 1;
        break;
      }
   }
}

void circlefill(int x, int y, int r, int c)
{
   int i;

   for (i = 0; i < r; ++i)
   {
      circle(x, y, i, c);
   }
}

/*以(x0,y0)为中心、a和b分别为水平和垂直半轴画一椭圆*/
void ellipse(int x0,int y0,int a,int b,unsigned char color)
{
   float d1, d2;
   int x, y;

   x=0; y=b;

   d1 = b * b + a * a * (-b + 0.25);
   dot(x0 + x, y0 + y, color);
   dot(x0 - x, y0 - y, color);
   dot(x0 - x, y0 + y, color);
   dot(x0 + x, y0 - y, color);

   while ((x + 1f) * b * b < (y - 0.5f) * a * a)
   {
      if (d1 < 0)
      {
         d1 += (2f * x + 3) * b * b;
         ++x;
      }
      else
      {
         d1 += (2f * x + 3) * b * b + (-2f * y + 2) * a * a;
         ++x; --y;
      }

      dot(x0 + x, y0 + y, color);
      dot(x0 - x, y0 - y, color);
      dot(x0 - x, y0 + y, color);
      dot(x0 + x, y0 - y, color);
   }
   d2 = (x + 0.5f) * b + (y - 1f) * a - a * b;
   while (y > 0)
   {
      if (d2 < 0)
      {
         d2 += (2f * x + 2) * b * b + (-2f * y + 3) * a * a;
         ++x; --y;
      }
      else
      {
         d2 += (-2f * y + 3) * a * a;
         --y;
      }

      dot(x0 + x, y0 + y, color);
      dot(x0 - x, y0 - y, color);
      dot(x0 - x, y0 + y, color);
      dot(x0 + x, y0 - y, color);
   }
}


void clear()
{
   int far *videoptr = (int far *)0xa0000000;
   unsigned int i, j;


   if (g_routines & 2)
   {
      hide_mouse();
   }

   for (i = 0; i <= g_page_num; ++i)
   {
      set_vbe_page(i);

      for (j = 0; j < 32768; ++j)
      {
         videoptr[j] = _BLACK;
      }
   }

   if (g_routines & 2)
   {
      show_mouse();
   }

}

/*分辨率:640x480. 速度:8位模式=73fps. 16位模式=40fps.*/
void clear_to_color(int color)
{
   int far *videoptr = (int far *)0xa0000000;
   unsigned i, j;


   if (g_routines & 2)
   {
      hide_mouse();
   }

   if (g_color_depth == 8)
   {
      unsigned clscol = (clscol = (color<< 8)) + color;
      for (i = 0; i <= g_page_num; ++i)
      {
         set_vbe_page(i);
         for (j = 0; j < 32768; ++j)
         {
            videoptr[j] = clscol;
         }
      }
   }



   if (g_color_depth == 15 || g_color_depth == 16)
   {
      for (i = 0; i <= g_page_num; ++i)
      {
         set_vbe_page(i);

         for (j = 0; j < 32768; ++j)
         {
            videoptr[j] = color;
         }
      }
   }

   if (g_routines & 2)
   {
      show_mouse();
   }

}


void _dot(int x, int y, int color)
{
   /*union REGS r;*/
   long addr;
   int page;
   if (g_color_depth == 8)
   {
      
      page = (int)((addr = (long)y * g_screen_h + x) >> 16);

      if (g_cur_vbe_page != page)
      {
         _BX=0;
         _DX=g_cur_vbe_page = page;
         _AX=0x4f05;
         __int__(0x10);
      }
      *(g_videoptr+(addr& 0xffff)) = (unsigned char)color;
     
   }
   else /*if (g_v_mode == 1)*/
   {
     
      int far *videoptr = (int far *)0xa0000000;
      page = (int)((addr = (long)y * g_screen_h + x) >> 15);
      if (g_cur_vbe_page != page)
      {
         _BX=0;
         _DX=g_cur_vbe_page = page;
         _AX=0x4f05;
         __int__(0x10);
      }
      *(videoptr + (addr & 0xffff)) = color;
     
   }
}

/*       以下是时钟控制的结构，变量，函数的声明及定义    */

#define  FAST_DBLCLICK     0.15
#define  MID_DBLCLICK      0.35
#define  SLOW_DBLCLICK     0.55

#define  MOUSE_LEFT_DOWN    1
#define  MOUSE_RIGHT_DOWN   2

#define TIMER     0x1C
#define MAX_T     1193180


int g_time_counter = 0;


void interrupt (*g_old_1ch_int)();
void interrupt (*g_new_1ch_int)() = 0l;

/*        函数开始          */

void interrupt new_1ch_int()
{
   float time_differ;
   g_time_total += g_time_factor;


   if (g_routines & 2)
   {
      mouse_refresh();
   }


   if (g_new_1ch_int)
      {g_new_1ch_int();}
   else
      {g_new_1ch_int = g_old_1ch_int;}

   g_time_counter++;
   #define NEO_timer_install
}


void install_timer(void interrupt (*intfounc)())
{
   if (!(g_routines & 4))
   {
      g_time_counter = 0;
      g_time_total = 0.0;
      g_old_1ch_int = getvect(0x1c);
      disable();
      setvect(0x1c, intfounc);
      enable();
      g_routines |= 4;
   }
}


void change_timer(unsigned hz)
{
   unsigned cnt = MAX_T / hz;

   if (hz >= 18)
   {
      outportb(0x43, 0x3c);
      outportb(0x40, cnt & 0x00ff);
      outportb(0x40, (cnt >> 8) & 0x00ff);
      g_time_factor = 1.0 / (float)hz;
      g_time_total = 0.0;
   }
}


void remove_timer()
{
   outportb(0x43, 0x3c);
   outportb(0x40, 0xffff & 0x00ff);
   outportb(0x40, (0xffff >> 8) & 0x00ff);
   disable();
   setvect(TIMER, g_old_1ch_int);
   enable();
   g_routines &= 251;
   #undef NEO_timer_install
}

void LOOP_END_OF_TIMER()
{
   float time_differ;
   while (g_time_counter < 1);
   {

   }
   g_time_counter = 0;
}


/*       以下是鼠标控制的结构，变量，函数的声明及定义    */


#define CUR_SIDE  1024



typedef struct
{

   unsigned int cursor[32];

   char hotx;
   char hoty;
}Hardcur_T;

typedef struct Cursor_type
{

   PIC_RGB  palette[16];
   unsigned color64k[16];
   unsigned char fir_cur_col;
   unsigned char map[512];
   unsigned char mask[128];
   unsigned char buffer[CUR_SIDE];
}Cursor, *Cursor_ptr;




typedef struct Mouse_T
{
   int x;         /*当前鼠标光标x坐标*/
   int y;         /*当前鼠标光标y坐标*/

   char logic_x;  /*鼠标光标贴图的逻辑坐标(相对于以上的两个物理坐标,可以为负值)*/
   char logic_y;

   float dblclickdelay;   /*双击延时变量.当第二次按下鼠标键与第一次的时间间隔小于该变量时,被
                          认为是双击鼠标键*/

   char advclickinfo;                  /*当前鼠标的按键状态,
                                         clickinfo=0 : 没动作;
                                         clickinfo=1 : 左键被按下;
                                         clickinfo=2 : 右键被按下;
                                         clickinfo=3 : 两键同时按下;
                                         clickinfo=5 : 左键被双击; */
   int oldclickinfo;
   clock_t start;
   clock_t end;                  /*这几个变量是为实现记录左键双击而设的“私有”变量*/

   unsigned char status_flag;/*临时去掉鼠标光标标志,为1时暂时不显示光标,一般用在作画操作前隐藏鼠标,防止满屏留下鼠标拖动轨迹*/

   int overlay_buf[CUR_SIDE];/*覆盖缓冲区:保存被光标覆盖的屏幕,以在光标移开后恢复*/

   Cursor iconbuffer;          /*光标缓冲区:保存被光标(文件)的位图信息,用以显示光标*/
   Cursor_ptr iconbuffer_p;    /*指向光标缓冲区的指针，用作调用相关函数的参数*/
}Mouse_t;
Mouse_t *g_mouse_tp = NULL;


int init_mouse();     /*初始化鼠标器.*/
int get_mouse_x();     /*获取当前鼠标光标X坐标.*/
int get_mouse_y();     /*获取当前鼠标光标Y坐标.*/
char get_click();  /*获取当前鼠标按钮状态.*/
                     /*获取按钮按下状态.*/
unsigned get_press_info(int key, int *x, int *y, int *count);
                     /*获取按钮放开状态.*/
unsigned get_release_info(int key, int *x, int *y, int *count);
void locate_mouse(int x,int y);
                     /*显示鼠标光标.*/
void show_hard_cur();
                     /*隐藏鼠标光标.*/
void hide_hard_cur();
                     /*设置光标的有效活动范围.*/
void set_mouse_range(int xmin,int xmax,int ymin,int ymax);

void mouse_shape(Hardcur_T cur);
void set_mouse_speed(int vx,int vy);
                     /*设置光标速度加速下限.*/
void speed_limit(int ms);
int  mouse_act();       /*判断鼠标是否发生按键动作.*/
                       /*设置鼠标光标焦点*/
void set_mouse_focus(char f_x, char f_y);

char install_mouse();   /*鼠标器高级初始化.*/
                     /*设置光标坐标.*/
void position_mouse(int x,int y);

void cursor_refresh();   /*鼠标图形光标的更新显示.*/
void scare_mouse();
void unscare_mouse();
int  mouse_refresh();  /*鼠标图形光标的刷新.*/
                          /*鼠标双击判定延时设置.*/
void set_dbl_click_delay(int userdelay);
                          /*改变鼠标光标的形状.*/
int  set_mouse_icon(char *p_iconfile);
int  get_click_info();/*获得当前的鼠标高级按键状态.*/
void remove_mouse();     /*鼠标关闭函数.*/



/*======================================================*
 *            函数定义(Function definitions)            *
 *======================================================*/




 
/*---------------------------------------------------*
 *函数功能: 绘制(显示)已读入内存的光(图)标文件.      *
 *参数说明: Cursor_ptr cursor_p:指向                 *
 *          构体cursor_p                             *
 *          x,y:要显示的位置坐标                     *
 *返回说明: 无.              　　　　　　　　　　　  *
 *备    注: 用户程序可以直接调用.　　　    　　　    *
 *---------------------------------------------------*/
void blit_icon(Cursor_ptr cursor_p, int x, int y)
{
   int i, j;
   unsigned int color;

   if (g_color_depth == 8)
   {
      #ifndef NEO_color_depth_8_unused
      for(i=0; i<32; ++i)
      {
         for(j=0; j<32; j+=2)
         {
            (color=cursor_p->buffer[(i<<5)+j]) == (TPT8 + 16)? 0 : dot(x + j, y + i, color);
            (color=cursor_p->buffer[(i<<5)+j+1])==(TPT8 + 16)? 0 : dot(x + j + 1,y + i, color);
         }
      }
      #else
      x += 0;
      y += 0;
      cursor_p += 0;
      #endif
   }
   #ifndef NEO_color_depth_16_unused
   else if (g_color_depth == 15 || g_color_depth == 16)
   {
      for(i=0; i<32; ++i)
      {
         for(j=0; j<32; j+=1)
         {
            if ((cursor_p->buffer[(i<<5)+j]) != (TPT8 + 16))
            {
               dot(x + j, y + i, cursor_p->color64k[cursor_p->buffer[(i<<5)+j]]);
            }
         }
      }
   }
   #else
   x += 0;
   y += 0;
   cursor_p += 0;
   #endif
}

/*函数功能: 初始化鼠标器.                            *
 *参数说明: 无.                                      *
 *返回说明: 成功则返回鼠标器按键个数;否则返回0.      *
 *备    注: 底层鼠标控制函数.用户通过nadmouse.h中的高*
 *          鼠标控制函数间接调用                     */
int init_mouse()
{
    _AX=0x00;
    __int__(0x33);
   if (_AX)
   {
      return (_BX);
   }
   else
   {
      return (0);
   }
}


/*---------------------------------------------------*
 *函数功能: 获取当前鼠标光标X坐标.                   *
 *参数说明: 无.                                      *
 *返回说明: 返回光标X坐标.                           *
 *备    注: 底层鼠标控制函数.用户通过nadmouse.h中的高*
 *          鼠标控制函数间接调用                     *
 *---------------------------------------------------*/
int get_mouse_x()
{
   _AX=0x03;
   __int__(0x33);
   return _CX;
}


/*---------------------------------------------------*
 *函数功能: 获取当前鼠标光标Y坐标.                   *
 *参数说明: 无.                                      *
 *返回说明: 返回光标Y坐标.                           *
 *备    注: 底层鼠标控制函数.用户通过nadmouse.h中的高*
 *          鼠标控制函数间接调用                     *
 *---------------------------------------------------*/
int get_mouse_y()
{
   _AX=0x03;
   __int__(0x33);
   return _DX;
}


/*---------------------------------------------------*
 *函数功能: 获取当前鼠标按钮状态.                    *
 *参数说明: 无.                                      *
 *返回说明: 返回按钮状态标志                         *
 *          返回0: 表示左右按键都没按下;             *
 *          返回1: 表示左键按下;                     *
            返回2: 表示右键按下;                     *
            返回3: 表示左右键均被按下.               *
 *备    注: 底层鼠标控制函数.用户通过nadmouse.h中的高*
 *          鼠标控制函数间接调用                     *
 *---------------------------------------------------*/
char get_click()
{
   _AX = 0x03;
   __int__(0x33);
   return _BX;
}


/*---------------------------------------------------*
 *函数功能: 获取按钮按下状态.                        *
 *参数说明: 变量key指定检查哪个键:等于0(或LEFT_KEY)时*
 *          表示检查左键;等于1(或RIGHT_KEY)时检查右键*
 *          整型指针型变量*x,*y用来记录最后一次按下指*
 *          定键时的光标坐标;*count将记录调用该功能以*
 *          来指定按键压下的总次数,超过65535溢出即置0*
 *返回说明: 返回当前鼠标按钮状态(同get_click功能) *
 *备    注: 底层鼠标控制函数.用户通过nadmouse.h中的高*
 *          鼠标控制函数间接调用                     *
 *---------------------------------------------------*/
unsigned get_press_info(int key, int *p_x, int *p_y, int *p_count)
{
   _BX = key;
   _AX = 0x05;
   __int__(0x33);
   *p_x=_CX;       /*指定键最后一次按下时的x坐标*/
   *p_y=_DX;       /*指定键最后一次按下时的y坐标*/
   *p_count = _BX; /*返回调用该功能以来指定按键压下的总次数(超过65535溢出,即置0)*/
   return _AX;
}


/*---------------------------------------------------*
 *函数功能: 获取按钮放开状态.                        *
 *参数说明: 变量key指定检查哪个键:等于0(或LEFT_KEY)时*
 *          表示检查左键;等于1(或RIGHT_KEY)时检查右键*
 *          整型指针型变量*x,*y用来记录最后一次按下指*
 *          定键时的光标坐标;*count将记录调用该功能以*
 *          来指定按键放开的总次数,超过65535溢出即置0*
 *返回说明: 返回当前鼠标按钮状态(同get_click功能) *
 *备    注: 底层鼠标控制函数.用户通过nadmouse.h中的高*
 *          鼠标控制函数间接调用                     *
 *---------------------------------------------------*/
unsigned get_release_info(int key, int *p_x, int *p_y, int *p_count)
{
   _BX = key;
   _AX = 0x06;
   __int__(0x33);
   *p_x=_CX;       /*指定键最后一次松开时的x坐标*/
   *p_y=_DX;       /*指定键最后一次松开时的y坐标*/
   *p_count = _BX; /*返回调用该功能以来指定按键松开的总次数(超过65535溢出,即置0)*/
   return _AX;
}


void locate_mouse(int x,int y)
{
   _CX=x;
   _DX=y;
   _AX=0x04;
   __int__(0x33);
}


/*---------------------------------------------------*
 *函数功能: 显示鼠标光标.                            *
 *参数说明: 无.                                      *
 *返回说明: 无.                                      *
 *备    注: 底层鼠标控制函数.不推荐用户使用.原因是它 *
 *          在Win2000/WinXP下可能无法显示光标.       * 
 *---------------------------------------------------*/
void show_hard_cur()
{
   _AX = 0x01;
   __int__(0x33);
}


/*---------------------------------------------------*
 *函数功能: 隐藏鼠标光标.当鼠标光标改变了位置,要先调 *
 *          用它来隐藏原来的光标,再调用show_hard_cur()来显 *
            示新的光标,否则会破坏屏幕的显示内容.     *
 *参数说明: 无.                                      *
 *返回说明: 无.                                      *
 *备    注: 底层鼠标控制函数.由于与高版本的Windows兼 *
 *          容性不好而不推荐用户使用.                *
 *---------------------------------------------------*/
void hide_hard_cur()
{
   _AX = 0x02;
   __int__(0x33);
}


/*---------------------------------------------------*
 *函数功能: 设置光标的有效活动范围.                  *
 *参数说明: xmin:水平方向活动的最小坐标.             *
 *          xmax:水平方向活动的最大坐标.             *
 *          ymin:垂直方向活动的最小坐标.             *
 *          ymax:垂直方向活动的最小坐标.             *
 *返回说明: 无.                                      *
 *备    注: 底层鼠标控制函数.用户通过nadmouse.h中的高*
 *          鼠标控制函数间接调用                     *
 *---------------------------------------------------*/
void set_mouse_range(int xmin, int ymin, int xmax, int ymax)
{
   _AX = 7;
   _CX = xmin;
   _DX = xmax;
   __int__(0x33);

   _AX = 8;
   _CX = ymin;
   _DX = ymax;
   __int__(0x33);
}



/*改变鼠标光标形状
  g_arrow_t cur:为以上定义的形状 */

void mouse_shape(Hardcur_T cur)
{
   _BX=cur.hotx;
   _CX=cur.hoty;
   _ES=FP_SEG(&cur.cursor);
   _DX=FP_OFF(&cur.cursor);
   _AX=0x09;
   __int__(0x33);
}


/*---------------------------------------------------*
 *函数功能: 设置鼠标的移动速度.                      *
 *参数说明: vx,vy的缺省值:vx=8,vy=8.值越大速度越慢   *
 *返回说明: 无.                                      *
 *备    注: 底层鼠标控制函数.用户通过nadmouse.h中的高*
 *          鼠标控制函数间接调用                     *
 *---------------------------------------------------*/
void set_mouse_speed(int vx,int vy)
{
   _CX=vx;
   _DX=vy;
   _AX=0x0f;
   __int__(0x33);
}


/*---------------------------------------------------*
 *函数功能: 设置光标速度加速下限.当光标移动速度超过设*
            置的下限后,光标速度将加倍.               *
 *参数说明: ms为每秒移动的下限单位(1ms约为1/1200英寸)*
 *          ms默认值为64/S.                          *
 *返回说明: 无.                                      *
 *备    注: 底层鼠标控制函数.用户通过nadmouse.h中的高*
 *          鼠标控制函数间接调用                     *
 *---------------------------------------------------*/
void speed_limit(int ms)
{
   _DX = ms;
   _AX = 0x13;
   __int__(0x33);
}


int mouse_act()
{
   if (get_click() == 0)
   {   return 0;}
   else
   {   return 1;}
}


void set_mouse_focus(char f_x, char f_y)
{
   if (g_mouse_tp)
   {
      g_mouse_tp->logic_x = -f_x;
      g_mouse_tp->logic_y = -f_y;
   }
   else
   {
      /*to be continue...*/
   }
}



/*---------------------------------------------------*
 *函数功能: 基于NEO_SDK鼠标器高级初始化.             *
 *参数说明: 无.                                      *
 *返回说明: 无.                                      *
 *备    注: 高级鼠标控制函数.用户程序必须在使用其它高*
 *          级鼠标控制函数之前首先调用.              *
 *---------------------------------------------------*/

char install_mouse()
{
   char keys = init_mouse();
   /*底层鼠标控制初始化*/
   if (!keys)
   {

      return FALSE;

   }

   if (!g_color_depth)
   {

   }
   /*调用remove_mouse();防止在同一程序中多次调用本函数可能出现的内存泄漏情况*/
   remove_mouse();

   if ((g_mouse_tp = (Mouse_t *)malloc( sizeof (Mouse_t) ))==NULL)
   {

   }
   g_mouse_tp->iconbuffer_p = &g_mouse_tp->iconbuffer;


   g_mouse_tp->advclickinfo = g_mouse_tp->status_flag = g_mouse_tp->logic_x = g_mouse_tp->logic_y = 0;

   g_mouse_tp->x = (int)((g_rect_right-g_rect_left)>>1)-32;
   g_mouse_tp->y = (int)((g_rect_bottom-g_rect_top)>>1)-32;
   g_mouse_tp->dblclickdelay = MID_DBLCLICK;/*当两次按下左键间隔小于0.35秒即认为是双击*/
   g_mouse_tp->oldclickinfo = -1;

   set_mouse_range(0, 0, g_rect_right, g_rect_bottom);
   position_mouse((g_mouse_tp->x), g_mouse_tp->y);
   set_mouse_icon(NULL);
   g_routines |= 2;
        mouse_refresh();
   return keys;
}


/*---------------------------------------------------*
 *函数功能: 设置光标坐标.                            *
 *参数说明: 整型参数x,y为光标的新位置坐标.           *
 *返回说明: 无.                                      *
 *备    注: 底层鼠标控制函数.用户通过nadmouse.h中的高*
 *          鼠标控制函数间接调用                     *
 *---------------------------------------------------*/
void position_mouse(int x,int y)
{
   if (g_mouse_tp != NULL)
   {
      hide_mouse();
      locate_mouse(x, y);
      show_mouse();
   }
   else
   {

      hide_hard_cur();
      locate_mouse(x, y);
      show_hard_cur();

   }

}


/*---------------------------------------------------*
 *函数功能: 以鼠标结构中保留的坐标值在屏幕相应的位置 *
 *          绘制光标                                 *
 *参数说明: 无.                                      *
 *返回说明: 无.                                      *
 *备    注: 高级鼠标控制函数.用户通过mouse_refresh() *
            间接调用.                                *
 *---------------------------------------------------*/
void show_mouse()
{
   int h, v;


   int cur_x = (g_mouse_tp->x = get_mouse_x()) + g_mouse_tp->logic_x;
   int cur_y = (g_mouse_tp->y = get_mouse_y()) + g_mouse_tp->logic_y;


   for (v = 0; v<32; v+=2)
   {
      for (h = 0; h<32; ++h)
      {
         /*保存光标将要覆盖的屏幕*/
         g_mouse_tp->overlay_buf[v * 32 + h] = get_dot(cur_x + h, cur_y + v);
         g_mouse_tp->overlay_buf[(v+1)*32+h] = get_dot(cur_x + h, cur_y + v + 1);
      }
   }
   blit_icon(g_mouse_tp->iconbuffer_p, cur_x, cur_y);
}


/*---------------------------------------------------*
 *函数功能: 鼠标图形光标隐藏.　　　　　　　　        *
 *参数说明: 无.                                      *
 *返回说明: 无.                                      *
 *备    注: 高级鼠标控制函数.用户通过cursor_refresh()*
 *          间接调用.                                *
 *---------------------------------------------------*/
void hide_mouse()
{
   int h, v;

   int x = g_mouse_tp->x + g_mouse_tp->logic_x, y = g_mouse_tp->y + g_mouse_tp->logic_y;

   for (v = 0; v<32; ++v)
   {
      for (h = 0; h<32; ++h)
      {
         dot(x + h , y + v, g_mouse_tp->overlay_buf[v * 32 + h]);
      }
   }
}


/*---------------------------------------------------*
 *函数功能: 鼠标图形光标的更新显示.                  *
 *          当鼠标光标可能被覆盖时调用来重绘光标.    *
 *参数说明: 无.                                      *
 *返回说明: 无.                                      *
 *备    注: 高级鼠标控制函数.用户可直接调用.         *
 *---------------------------------------------------*/
void cursor_refresh()
{
   if (!(g_mouse_tp->status_flag & 1))
   {
      hide_mouse();   /*隐藏原来的光标*/
      show_mouse();   /*绘制新的光标.*/
   }
}


/*临时去掉鼠标光标*/
void scare_mouse()
{
   g_mouse_tp->status_flag |= 1;
   hide_mouse();
}


/*恢复临时去掉的鼠标光标*/
void unscare_mouse()
{
   g_mouse_tp->status_flag &= 0xfe;
   show_mouse();
}


/*---------------------------------------------------*
 *函数功能: 鼠标图形光标的刷新.放在用户程序的主循环中*
 *          用以刷新鼠标的各种主要状态.              *
 *参数说明: 无.                                      *
 *返回说明: 若鼠标移动返回0;否则返回1.               *
 *备    注: 高级鼠标控制函数.用户可直接调用.         *
 *---------------------------------------------------*/
int mouse_refresh()
{
   float timer;
   static fir_clk = 1, fir_call;

   if (!fir_call) /*加入首次运行检查，看高级鼠标例程是否已安装*/
   {
      if (g_mouse_tp == NULL)
      {

      }
      fir_call = 1;
   }

   if (fir_clk != 1)
   { 
      int current_x, current_y;
      _AX = 0x03;
      __int__(0x33);
      current_x = _CX;
      current_y = _DX;
      /*鼠标没移动*/
      if ((current_x == g_mouse_tp->x) && (current_y == g_mouse_tp->y))
      {

         char click;
         _AX = 0x03;
         __int__(0x33);
         click = _BX;
         /*检测左键是否双击*/
         if (click == 0 && (g_mouse_tp->oldclickinfo==1)&&(g_mouse_tp->advclickinfo==0))
         {
            g_mouse_tp->advclickinfo = 0;
            return 1;
         }
         else if (click == 0 && (g_mouse_tp->advclickinfo == 1))
         {
            g_mouse_tp->start = clock();
            g_mouse_tp->oldclickinfo = g_mouse_tp->advclickinfo;
            g_mouse_tp->advclickinfo = 0;
            return 1;
         }
         else if (click == 1 && (g_mouse_tp->oldclickinfo==1)&&(g_mouse_tp->advclickinfo==0))
         {
            g_mouse_tp->end = clock();
            timer = ((g_mouse_tp->end) - (g_mouse_tp->start))/CLK_TCK;

            /*当dblclickdelay为MIDDLE_DBLCLICK即0.35时双击延时=0.35秒*/
            timer <= g_mouse_tp->dblclickdelay?g_mouse_tp->advclickinfo = 5 : 0;
            g_mouse_tp->oldclickinfo = -1;
         }
         else
         {
            g_mouse_tp->advclickinfo  = get_click();
            g_mouse_tp->oldclickinfo != -1 ? g_mouse_tp->oldclickinfo = -1 : 0;
         }

         return 1;
      }
      /*鼠标移动了*/
      else
      {
         _AX = 0x03;
         __int__(0x33);
         g_mouse_tp->advclickinfo = _BX;

      /*更新过的鼠标光标坐标与原来的不同,以新坐标重绘光标(亦可直接用cusor_refresh())*/
            if (!(g_mouse_tp->status_flag & 1))
            {

               vsync();

               hide_mouse();   /*隐藏原来的光标*/
               show_mouse();   /*绘制新的光标.*/
            }

         return 0;
      }
   }
   else
   {
      show_mouse();
      fir_clk = 0;
   }
}


/*---------------------------------------------------*
 *函数功能: 鼠标双击判定延时设置.当两次相邻的单击时间*
 *          间隔小于双击判定延时即被认为是双击.　　　*
 *参数说明: userdelay可以是:                         *
 *          FAST_DBLCLICK,MIDDLE_DBLCLICK            *
 *          或SLOW_DBLCLICK(用户亦可自定一个小于1.5的*
 *          延时)                                    *
 *返回说明: 无.                                      *
 *备    注: 高级鼠标控制函数.用户可直接调用.         *
 *---------------------------------------------------*/
void set_dbl_click_delay(int userdelay)
{
   if (g_mouse_tp==NULL)
   {

   }
   (g_mouse_tp->dblclickdelay=userdelay);
}


/*---------------------------------------------------*
 *函数功能: 改变鼠标光标的形状.                      *
 *参数说明: p_iconfile:光标文件的文件名.             *
 *返回说明: 改变成功返回1;失败返回0,并改为默认的箭头 *
 *          形光标.                                  *
 *备    注: 高级鼠标控制函数.用户可直接调用.         *
 *---------------------------------------------------*/
int set_mouse_icon(char *p_iconfile)
{
   int offset = 0;
   unsigned char *deft = NULL;

   Cursor_ptr tempcur = NULL;

   offset += 0;   /*无实际作用，配合条件编译*/

   if (g_mouse_tp == NULL)
   {
        /* error*/
   }

   p_iconfile += 0; /*加上此句只是为在条件编译时不报警*/

    /*当指定的光标文件找不到时,执行以下代码*/
    /*以下代码段是在光标缓冲区填入默认的箭头形光标*/
    memset(g_mouse_tp->iconbuffer_p->buffer, TPT8 + 16, 1024);
    g_mouse_tp->iconbuffer_p->color64k[1] = 0x0000;
    g_mouse_tp->iconbuffer_p->color64k[_WHITE] = 0xffff;

    deft = g_mouse_tp->iconbuffer_p->buffer;
    *deft = 1;
    *(deft += 32) = *(deft + 1) = 1;
    *(deft += 32) = *(deft + 2) = 1;
    *(deft + 1) = _WHITE;
    *(deft += 32) = *(deft + 3) = 1;
    *(deft + 1) = *(deft + 2) = _WHITE;
    *(deft += 32) = *(deft + 4) = 1;
    *(deft + 1) = *(deft + 2) = *(deft + 3) = _WHITE;
    *(deft += 32) = *(deft + 5) = 1;
    *(deft + 1) = *(deft + 2) = *(deft + 3) = *(deft + 4) = _WHITE;
    *(deft += 32) = *(deft + 6) = 1;
    *(deft + 1) = *(deft + 2) =*(deft + 3)=*(deft + 4)=*(deft + 5)=_WHITE;
    *(deft += 32) = *(deft + 7) = 1;
    memset((deft + 1), _WHITE, 6);
    *(deft += 32) = *(deft + 8) = 1;
    memset((deft + 1), _WHITE, 7);
    *(deft += 32) = *(deft + 9) = 1;
    memset((deft + 1), _WHITE, 8);
    *(deft += 32) = 1;
    memset((deft + 1), _WHITE, 5); memset((deft + 6), 1, 5);
    *(deft += 32) = *(deft + 3) = *(deft + 6) = 1;
    *(deft + 1) = *(deft + 2) = *(deft + 4) = *(deft + 5) = _WHITE;
    *(deft += 32) = *(deft + 2) = *(deft + 4) = *(deft + 7) = 1;
    *(deft + 1) = *(deft + 5) = *(deft + 6) = _WHITE;
    *(deft += 32) = *(deft + 1) = *(deft + 4) = *(deft + 7) = 1;
    *(deft + 5) = *(deft + 6) = _WHITE;
    *(deft += 32) = *(deft + 5) = *(deft + 8) = 1;
    *(deft + 6) = *(deft + 7) = _WHITE;
    deft += 32;
    *(deft + 5) = *(deft + 8) = 1;
    *(deft + 6) = *(deft + 7) = _WHITE;
    deft += 32;
    *(deft + 6) = *(deft + 9) = 1;
    *(deft + 7) = *(deft + 8) = _WHITE;
    deft += 32;
    *(deft + 6) = *(deft + 9) = 1;
    *(deft + 7) = *(deft + 8) = _WHITE;
    deft += 32;
    *(deft + 7) = *(deft + 8) = 1;

   return 0;
}


/*---------------------------------------------------*
 *函数功能: 获得当前的鼠标高级按键状态.              *
 *参数说明: 无.                                      *
 *返回说明: 返回0 : 没有动作;                        *
 *          返回1 : 左键单击;                        *
 *          返回2 : 右键单击;                        *
 *          返回3 : 左右同时单击;                    *
 *          返回5 : 左键双击;                        *
 *备    注: 高级鼠标控制函数.用户可直接调用.         *
 *---------------------------------------------------*/
int get_click_info()
{
   return g_mouse_tp->advclickinfo;
}


/*---------------------------------------------------*
 *函数功能: 鼠标关闭函数,主要用于释放鼠标结构占用的内*
 *          存.                                      *
 *参数说明: 无.                                      *
 *返回说明: 无.                                      *
 *备    注: 由清理函数neo_exit();会自动调用所以用户一*
 *          般不用直接调用                           *
 *---------------------------------------------------*/
void remove_mouse()
{
   if (g_mouse_tp != NULL)
   {
      free(g_mouse_tp);
      g_mouse_tp = NULL;
   }
   g_routines &= 253;
}



char neo_init();
void neo_exit();


char neo_init()
{
   atexit(neo_exit);
   return 0;
}


void neo_exit()
{
     set_vbe_mode(3);
 
   if (g_routines & 2)
   {
      remove_mouse();
   }  
   if (g_routines & 4)
   {
      remove_timer();
   }  
  
   puts("\nExit... Please wait.");
   delay(5000);
   fcloseall();
   unlink("c:\\neo.vbs");
}

/*         字符输出          */


#define  S12X12   0   
#define  S16X16   1
#define  S24X24   2
#define  S32X32   3
#define  S48X48   4

char g_en_slant = 0;
char *hzk24font = "hzk24s";
char g_cn_size = S16X16;
int  g_str_color = 1;
int  g_text_bg = -1;

unsigned char far *get_asc_rom(unsigned int bx);
unsigned char far *cur_asc_rom(int *chose);
void en_slant(char slant);
void en_out(char c, int cx, int cy); /*显示速度:每秒约45000字*/
void textout(char *str, int sx, int sy);   /*显示速度:每秒约45000字*/
int cn_s16_out(char *str,int x,int y);
int cn_s24_out(char *cn_str, int x, int y);
void set_cn_size(char cn_size);
void set_str_color(int color);
void text_mode(int mode);
int string_out(char *str, int x, int y); /*显示速度:每秒约6000字*/

char textheight();

/*获得ROM字符集首地址*/
unsigned char far *get_asc_rom(unsigned int bx)
{
    struct REGPACK reg;
    reg.r_ax = 0x1130;
    reg.r_bx = bx;
    intr(0x10, &reg);
    return MK_FP(reg.r_es, reg.r_bp);
}


/*选择要使用的ASCII ROM字符集*/
unsigned char far *cur_asc_rom(int *chose)
{
   static char fault_ch = 8;
   static unsigned char far *romaddr = (unsigned char far *)0xf000fa6e;

   if (*chose>0)
   {
      switch (fault_ch = *chose)
      {
         case 8 : /*获得8*8  ASCII ROM字符集首地址*/
            return romaddr = get_asc_rom(0x0300);
         case 14: /*获得14*8  ASCII ROM字符集首地址*/
            return romaddr = get_asc_rom(0x0200);

         case 16: /*获得16*8  ASCII ROM字符集首地址*/
            return romaddr = get_asc_rom(0x0600);

         default:
            romaddr = get_asc_rom(0x0300);
            *chose = fault_ch = 8;
            return romaddr;
      }
   }
   *chose = fault_ch;
   return romaddr;
}



void en_slant(char slant)
{
   if (slant > 0)
   {
      g_en_slant = 1;
   }
   else if (slant < 0)
   {
      g_en_slant = -1;
   }
   else
   {
      g_en_slant = 0;
   }
}




/*显示单个English字符*/
void en_out(char c, int cx, int cy)
{
   int i, x, y, num = 0;
   unsigned char bit = 1;
   char slant = 0;
   int  ascrom[1] = {-1};
   char far *romchar_p = cur_asc_rom(ascrom);
   char far *temp_p;
   temp_p = romchar_p + c * (*ascrom);

   for (y = 0; y < *ascrom; ++y)
   {
      bit = 1;slant += g_en_slant;
      for (x = 0; x < 8; ++x)
      {
         num = bit & (*temp_p);
         num >>= x;
         if (num == 1)
         {
            dot(cx + 8 - x+slant, cy + y, g_str_color);
         }
         else if (g_text_bg >= 0)
         {
            dot(cx + 8 - x+slant, cy + y, g_text_bg);
         }
         bit <<= 1;
      }
      ++temp_p;
   }
}


/*显示English字符串*/
void textout(char *str, int sx, int sy)
{
   int index;
   for (index = 0; str[index] != 0; index++)
   {
      en_out(str[index], sx + (index << 3), sy);
   }
}

#ifndef NEO_cn16_out_unused
int cn_s16_out(char *str, int x, int y)
{
   int  i, j, k, m, n, xx;
   int  ascrom[1] = {-1};
   char bitdata[32];
   long fpos;
   unsigned vpos;
   unsigned char s0, s1;
   unsigned char bit[8]={128, 64, 32, 16, 8, 4, 2, 1};
   FILE *hzf_p;

   cur_asc_rom(ascrom);
   *ascrom = 16 - *ascrom;
   if((hzf_p = fopen("hzk16", "rb")) == NULL)
   {
     /*  error  */
      return -1;
   }
   xx = x;
   for(i = 0; i < strlen(str); ++i)
   {
      if((str[i] & 0x80) == 0)
      {
         en_out(str[i], xx, y+(*ascrom));
         xx += 8;
      }
      else
      {
         char slant = 0;

         fpos = 32L*(((unsigned char)str[i] - 161) * 94 + ((unsigned char)str[i+1] - 161));
         fseek(hzf_p, fpos, SEEK_SET);
         fread(bitdata, 32, 1, hzf_p);
         for (m = 0; m < 16; m++)
         {  slant += g_en_slant;
            for (n = 0; n < 8; n++)
            {
               if (bitdata[m<<1] & bit[n])
                  {dot(xx + n + slant, m + y, g_str_color);}
               else if (g_text_bg >= 0)
                  {dot(xx + n + slant, m + y, g_text_bg);}

               if (bitdata[(m<<1) + 1] & bit[n])
                  {dot(xx + 8 + n + slant, m + y, g_str_color);}
               else if (g_text_bg >= 0)
                  {dot(xx + 8 + n + slant, m + y, g_text_bg);}
            }
         }
      ++i;
      xx += 16;
      }
   }

   fclose(hzf_p);
   return (1);
}
#else
int cn_s16_out(char *str, int x, int y)
{
   str+=0;x+=0;y+=0;
   printf("The 16X16 HZK was unsupport!");
}
#endif

#ifndef NEO_cn24_out_unused
/*---------------------------------------------------*
 *整理作者：董凯.                                    *
 *修正改良：蔺会强(于2005-1-11).                     *
 *函数功能: 显示24点阵汉字的函数.                    *
 *参数说明: cn_str汉字字符串;x,y是显示的起点坐标.    *
 *返回说明: 失败(比如字库文件未找到)返回-1.成功返回1.*
 *备    注: 用户程序通过string_out()间接调用. 　     *
 *---------------------------------------------------*/
int cn_s24_out(char *cn_str, int x, int y)
{
   FILE *fp;
   int ascrom[1]= {16};
   int len;
   int yy;
   unsigned int i = 0, j = 0, l = 0, n = 0;
   unsigned long num=0;
   char wm[72];

   cur_asc_rom(ascrom);
   yy =  y + (16 - *ascrom) + 8;
   if ((fp=fopen(hzk24font,"rb+"))==NULL)/* 打开24点阵字库文件 */
   {/*error*/
      return -1;
   }
   len = strlen(cn_str); 
   while(n != len)
   {

      if((cn_str[n] & 0x80)==0)/* 判断是否是扩展ASCII */
      {
         en_out(cn_str[n], x, yy);
         x += 8; n++;
      }
      else
      {
         cn_str[n]=cn_str[n]-0xa0-15;
         cn_str[n+1]=cn_str[n+1]-0xa0;
         num=(cn_str[n]-1)*94+(cn_str[n+1]-1);
         fseek(fp,(72)*num,0);
         fread(wm,72,1,fp);

         for(i=0;i<24;i++)
         {
            for(j=0;j<3;j++)
            {
               for(l=1;l<=8;l++)
               {
                  char temp = wm[i*3+j] << (l-1);
                  if(temp&0x80)
                  {
                     dot(x+i, y+(j<<3)+l-1, g_str_color);
                  }
                  else if (g_text_bg >= 0)
                  {
                     dot(x+i, y+(j<<3)+l-1, g_text_bg);
                  }
               }
            }
         }
         n+=2;
         x += 24;
      }
   }
   fclose(fp);
   return 1;
}
#else
int cn_s24_out(char *cn_str, int x, int y)
{
   cn_str+=0;x+=0;y+=0;
   printf("The 24X24 HZK was unsupport!");
}
#endif


void set_cn_size(char cn_size)
{
   if (cn_size >= 0 && cn_size < 6)
   {
      g_cn_size = cn_size;
   }
   else
   {
      g_cn_size = 1;
   }
}


void set_str_color(int color)
{
   g_str_color = color;
}


void text_mode(int mode)
{
   g_text_bg = mode;
}

int string_out(char *str, int x, int y)
{
   static int (*out_proc[5])() = {cn_s16_out, cn_s16_out, cn_s24_out};

   return (*out_proc[g_cn_size])(str, x, y);
}


char textheight()
{
   int temp = -1;

   cur_asc_rom(&temp);
   return temp;
}


void clear_msg_win()
{
      rectfill(1, 435, 639, 479, HiColor(BK_COLOR));
}
void showMessage(char *text)
{
         clear_msg_win();
        string_out(text,5,435);
}

#endif
