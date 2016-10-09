/*
        �ļ�ժҪ����ɸ��ֻ���ͼ��ģʽ�º������ṹ�����������������塣
                  �й�ʱ�ӡ������Ƶĸ��ֺ������ṹ��ȫ�ֱ���
                  ������������



*/
#ifndef  GGG_H
#define  GGG_H



    /*            �����ǻ���ͼ�κ����Ľṹ������������������������ */
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

; ǿ����Ϣ

ModeAttributes dw ? ; ģʽ����

WinAAttributes db ? ; ����A����

WinBAttributes db ? ; ����B����

WinGranularity dw ? ; ���ڼ���ߴ�

WinSize dw ? ; ���ڴ�С

WinASegment dw ? ; ����A��ʼ�ε�ַ

WinBSegment dw ? ; ����B��ʼ�ε�ַ

WinFuncPtr dd ? ; ���ں���ָ��

BytesPerScanLine dw ? ; ÿ���ֽ���

; ��ȥ�Ŀ�ѡ��Ϣ��������ǿ����Ϣ��

XResolution dw ? ; ˮƽ�ֱ���

YResolution dw ? ; ��ֱ�ֱ���

XCharSize db ? ; �ַ���Ԫ���

YCharSize db ? ; �ַ���Ԫ�߶�

NumberOfPlanes db ? ; �ڴ�ƽ����

BitsPerPixel db ? ; ÿ���λ��

NumberOfBanks db ? ; �洢����

MemoryModel db ? ; �ڴ�ģʽ����

BankSize db ? ; �洢��K�ֽ���

NumberOfImagePages db ?; ͼ����

Reserved db 1 ; ������ҳ����

; �µ�ֱ��ɫ������

RedMaskSize db ? ; ��ɫ�ڸ�λ��

RedFieldPosition db ? ; ��ɫ�ڸ�λַ

GreenMaskSize db ? ; ��ɫ�ڸ�λ��

GreenFieldPosition db ? ; ��ɫ�ڸ�λַ

BlueMaskSize db ? ; ��ɫ�ڸ�λ��

BlueFieldPosition db ? ; ��ɫ�ڸ�λַ

RsvdMaskSize db ? ; ֱ��ɫ�ʱ����ڸ�λ��

RsvdFieldPosition db ? ; ֱ��ɫ�ʱ����ڸ�λַ

DirectColorModeInfo db ? ; ֱ��ɫ��ģʽ����

Reserved db 216 dup(?) ; ģʽ��Ϣ��ʣ��

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
/*     ȫ�ֱ���      */
char g_routines = 0;     /*���λΪ1:����ͼ��ģʽ;��2λΪ1:�߼�������̱�����;��3λΪ1:ʱ�����̱�����;��4λΪ1:����
�����������������������������̱�����;*/


float   g_time_factor = 0.055;
double  g_time_total  = 0.0;
float  g_time_cnt = 0;
unsigned g_block_num = 0; /*Ҫ�ּ��ζ�ȡ*/
int      g_block_cnt = -1; /*�Ѿ����˼���*/
float    g_block_time= 0.0; /*��ȡһ���ܲ��ŵ�ʱ��*/
unsigned char g_play_mode = 1;


char far *g_videoptr = (char far *)0xa0000000;
char g_page_num;
char g_green_mask = 0;
char g_green_bit  = 0;
char g_color_depth = 0;   /*��¼��ǰͼ��ģʽ��ɫ�Ϊ0��ʾ��ͼ��ģʽ*/
int  g_screen_h;          /*��ǰ�ֱ����µ���Ļ���*/
int  g_screen_v;          /*��ǰ�ֱ����µ���Ļ�߶�*/
long g_screen_size;       /*��¼��ǰͼ��ģʽ����Ļ���*/
unsigned g_blit_fix;      /*Ŀǰ����blit()��������ʱ����*/
int  g_cur_vbe_page = 0;  /*��ǰ��������ʾҳ*/
/*----------------------------------------------------------------------------------------------------*/
int  g_frt_color = 1;
int  g_tptcolor  = 0;     /*ָ��͸��ɫ(Transparent color)*/
char g_draw_mode = 0;     /*��ͼģʽ,��ΪCOPY_PUT,XOR_PUT,OR_PUT,AND_PUT,NOT_PUT,��TC��Graphics�Ļ�ͼģʽ������ͬ*/
/*����4����������֧�ֲü����,�ֱ����ü���������ϽǼ����½�����*/
int  g_rect_left;
int  g_rect_right;
int  g_rect_top;
int  g_rect_bottom;
char g_dac_size_fix = 2;    /*��¼DAC��ɫ��������ֵ����8-��ǰDAC��ȵ�����Ĭ��Ϊ2*/


char get_page_num();
char screen(unsigned left, unsigned top, unsigned right, unsigned bottom);
void show_mouse();     /*���ͼ�ι����ʾ.*/
void hide_mouse();     /*���ͼ�ι������.*/
void vsync();

/*            ������ʼ             */


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
01h-���س���VGAģʽ��Ϣ

�ú�������һ��ָ���ĳ���VGA��ʾģʽ�������Ϣ���ú������ݵ����߸����ĵ�ַ���һ��ģʽ��Ϣ�顣ģʽ��Ϣ�����Ϊ256K��

�˺������ص�һЩ��Ϣ����VESAģʽ�Ű��ж���ġ�����һЩ����VGA����֧����������ʾģʽ��������VESA������ġ�Ϊ���ṩ�Ը�ģʽ�ķ��ʣ�����Ҳ����һЩ���ָ����������Ϣ��

���룺AH = 4Fh ����VGA֧��

AL = 01h ���س���VGAģʽ��Ϣ

CX = ����VGAģʽ�ţ�ģʽ�ű���Ϊ����00h����ֵ֮һ��

ES:DI = 256�ֽڻ�����ָ��

�����AX = ״̬


      */
      r.x.cx = mode;
      r.x.di = FP_OFF(modeinfo);
      segs.es = FP_SEG(modeinfo);
      int86x(0x10, &r, &r, &segs);
      if (r.x.ax != 0x4F) return FALSE;
/*
 ״̬��Ϣ

������AX�Ĵ�������һ��״̬��Ϣ��״̬�ֵĸ�ʽ���£�

AL==4Fh ������֧��

AL!=4Fh ��������֧��

AH==00h �������óɹ�

AH==01h ��������ʧ��

��AH�Ĵ�����ֵΪ����ʱ�������Ӧ����Ϊ��ʧ�ܡ�
*/
   }

   switch (mode) /*��ʱʹ��*/
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
01h-���س���VGAģʽ��Ϣ

�ú�������һ��ָ���ĳ���VGA��ʾģʽ�������Ϣ���ú������ݵ����߸����ĵ�ַ���һ��ģʽ��Ϣ�顣ģʽ��Ϣ�����Ϊ256K��

�˺������ص�һЩ��Ϣ����VESAģʽ�Ű��ж���ġ�����һЩ����VGA����֧����������ʾģʽ��������VESA������ġ�Ϊ���ṩ�Ը�ģʽ�ķ��ʣ�����Ҳ����һЩ���ָ����������Ϣ��

���룺AH = 4Fh ����VGA֧��

AL = 01h ���س���VGAģʽ��Ϣ

CX = ����VGAģʽ�ţ�ģʽ�ű���Ϊ����00h����ֵ֮һ��

ES:DI = 256�ֽڻ�����ָ��

�����AX = ״̬


      */
      r.x.cx = mode;
      r.x.di = FP_OFF(modeinfo);
      segs.es = FP_SEG(modeinfo);
      int86x(0x10, &r, &r, &segs);
      if (r.x.ax != 0x4F) return FALSE;
/*
 ״̬��Ϣ

������AX�Ĵ�������һ��״̬��Ϣ��״̬�ֵĸ�ʽ���£�

AL==4Fh ������֧��

AL!=4Fh ��������֧��

AH==00h �������óɹ�

AH==01h ��������ʧ��

��AH�Ĵ�����ֵΪ����ʱ�������Ӧ����Ϊ��ʧ�ܡ�
*/
   }

   switch (mode) /*��ʱʹ��*/
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

/*���SVGA����ʾģʽ*/
/*

*/
int get_vbe_mode(void)
{
   _AX = 0x4f03;
   /*
   03h-���ص�ǰ��ʾģʽ

�˺�������ǰ��ʾģʽ���ص�BX�Ĵ�����VESA��ʾģʽ���ڵڶ�������ϸ������

���룺AH = 4Fh ����VGA֧��

AL = 03h ���ص�ǰ��ʾģʽ

�����AX = ״̬

BX = ��ǰ��ʾģʽ

�������Ĵ������ֲ��䣩

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

  /*ָ�����������(��������)*/
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


/*�Դ滻ҳ����*/
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
 *��������: ����Ӳ����ɫ����ָ����ɫ�ŵ���ɫ����.    *
 *����˵��: indexΪ��ɫ��.                           *
 *          red,green,blueΪ����ɫ�Ŷ�Ӧ�ĺ�,��,���� *
 *          ԭɫ����,��ӦС��64)                     *
 *����˵��: �ɹ�����1;���򷵻�0.                     *
 *��    ע: ��ɫ���ú���.�û������ֱ�ӵ���.  ��     *
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

 /*ͨ�û��㺯��,�ٶ�:17FPS*/
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
   else /*if (g_color_depth == 16)*/ /*����ֻ֧��256��64Kɫ,������ʱע�����һ��*/
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

 /*ͨ�õĻ��ߺ�������color��ɫ��(x1,y1)����(x2,y2);�ٶ�:(16FPS)*/
void line(int x1, int y1, int x2, int y2, unsigned color)
{
   int  dt_x = x2 - x1, dt_y = y2 - y1, step_x, step_y, change;

   if (dt_x < 0)
   {
      dt_x = -dt_x;    /*����������*/
      step_x = -1;
   }
   else {step_x = 1;}  /*�������һ���*/

   if (dt_y < 0)
   {
      dt_y = -dt_y;    /*�������ϻ���*/
      step_y = -1;
   }
   else {step_y = 1;}
                       /*�������»���*/
   if (dt_x > dt_y)    /*x�ı�ñ�y��*/
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
   else                 /*y�ı�ñ�x��*/
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


/*�Ż���Ļ�ˮƽ�ߺ�������color��ɫ��(x,y)���һ���Ϊwidth��ˮƽ��;�ٶ�: 8λ65FPS; 16λ32FPS*/
char hline(int x, int y, int width, unsigned color)
{
   long addr;
   int  k = 0;
   int  xx = x;
   int  rect_scr_h = g_rect_right + 1;
   int  len = 0, length/*ֱ����Ч����*/ = 0;
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
         if (rect_scr_h - x >= width) /*ֱ����ȫ��ʾ*/
         {
            len = length = width + 1;
         }
         else                         /*ֱ���ұ����*/
         {
            len = length = rect_scr_h - x + 1;
         }
      }
      else if (x < 0 && x > (-width))
      {
         if (width + x >= rect_scr_h)  /*ֱ���������*/
         {
            len = length = rect_scr_h + 1;
            xx = x = 0;
         }
         else                          /*ֱ��������*/
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
         if (rect_scr_h - x >= width) /*ֱ����ȫ��ʾ*/
         {
            len = length = width + 1;
         }
         else                         /*ֱ���ұ����*/
         {
            len = length = rect_scr_h - x + 1;
         }
      }
      else if (x < 0 && x > (-width))
      {
         if (width + x >= rect_scr_h)  /*ֱ���������*/
         {
            len = length = rect_scr_h + 1;
            xx = x = 0;
         }
         else                          /*ֱ��������*/
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

/*��Բ��������(c_x, c_y)Ϊ���Ļ�һ�뾶Ϊr��Բ*/
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

/*��(x0,y0)Ϊ���ġ�a��b�ֱ�Ϊˮƽ�ʹ�ֱ���ửһ��Բ*/
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

/*�ֱ���:640x480. �ٶ�:8λģʽ=73fps. 16λģʽ=40fps.*/
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

/*       ������ʱ�ӿ��ƵĽṹ������������������������    */

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

/*        ������ʼ          */

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


/*       �����������ƵĽṹ������������������������    */


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
   int x;         /*��ǰ�����x����*/
   int y;         /*��ǰ�����y����*/

   char logic_x;  /*�������ͼ���߼�����(��������ϵ�������������,����Ϊ��ֵ)*/
   char logic_y;

   float dblclickdelay;   /*˫����ʱ����.���ڶ��ΰ����������һ�ε�ʱ����С�ڸñ���ʱ,��
                          ��Ϊ��˫������*/

   char advclickinfo;                  /*��ǰ���İ���״̬,
                                         clickinfo=0 : û����;
                                         clickinfo=1 : ���������;
                                         clickinfo=2 : �Ҽ�������;
                                         clickinfo=3 : ����ͬʱ����;
                                         clickinfo=5 : �����˫��; */
   int oldclickinfo;
   clock_t start;
   clock_t end;                  /*�⼸��������Ϊʵ�ּ�¼���˫������ġ�˽�С�����*/

   unsigned char status_flag;/*��ʱȥ��������־,Ϊ1ʱ��ʱ����ʾ���,һ��������������ǰ�������,��ֹ������������϶��켣*/

   int overlay_buf[CUR_SIDE];/*���ǻ�����:���汻��긲�ǵ���Ļ,���ڹ���ƿ���ָ�*/

   Cursor iconbuffer;          /*��껺����:���汻���(�ļ�)��λͼ��Ϣ,������ʾ���*/
   Cursor_ptr iconbuffer_p;    /*ָ���껺������ָ�룬����������غ����Ĳ���*/
}Mouse_t;
Mouse_t *g_mouse_tp = NULL;


int init_mouse();     /*��ʼ�������.*/
int get_mouse_x();     /*��ȡ��ǰ�����X����.*/
int get_mouse_y();     /*��ȡ��ǰ�����Y����.*/
char get_click();  /*��ȡ��ǰ��갴ť״̬.*/
                     /*��ȡ��ť����״̬.*/
unsigned get_press_info(int key, int *x, int *y, int *count);
                     /*��ȡ��ť�ſ�״̬.*/
unsigned get_release_info(int key, int *x, int *y, int *count);
void locate_mouse(int x,int y);
                     /*��ʾ�����.*/
void show_hard_cur();
                     /*���������.*/
void hide_hard_cur();
                     /*���ù�����Ч���Χ.*/
void set_mouse_range(int xmin,int xmax,int ymin,int ymax);

void mouse_shape(Hardcur_T cur);
void set_mouse_speed(int vx,int vy);
                     /*���ù���ٶȼ�������.*/
void speed_limit(int ms);
int  mouse_act();       /*�ж�����Ƿ�����������.*/
                       /*��������꽹��*/
void set_mouse_focus(char f_x, char f_y);

char install_mouse();   /*������߼���ʼ��.*/
                     /*���ù������.*/
void position_mouse(int x,int y);

void cursor_refresh();   /*���ͼ�ι��ĸ�����ʾ.*/
void scare_mouse();
void unscare_mouse();
int  mouse_refresh();  /*���ͼ�ι���ˢ��.*/
                          /*���˫���ж���ʱ����.*/
void set_dbl_click_delay(int userdelay);
                          /*�ı���������״.*/
int  set_mouse_icon(char *p_iconfile);
int  get_click_info();/*��õ�ǰ�����߼�����״̬.*/
void remove_mouse();     /*���رպ���.*/



/*======================================================*
 *            ��������(Function definitions)            *
 *======================================================*/




 
/*---------------------------------------------------*
 *��������: ����(��ʾ)�Ѷ����ڴ�Ĺ�(ͼ)���ļ�.      *
 *����˵��: Cursor_ptr cursor_p:ָ��                 *
 *          ����cursor_p                             *
 *          x,y:Ҫ��ʾ��λ������                     *
 *����˵��: ��.              ����������������������  *
 *��    ע: �û��������ֱ�ӵ���.������    ������    *
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

/*��������: ��ʼ�������.                            *
 *����˵��: ��.                                      *
 *����˵��: �ɹ��򷵻��������������;���򷵻�0.      *
 *��    ע: �ײ������ƺ���.�û�ͨ��nadmouse.h�еĸ�*
 *          �����ƺ�����ӵ���                     */
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
 *��������: ��ȡ��ǰ�����X����.                   *
 *����˵��: ��.                                      *
 *����˵��: ���ع��X����.                           *
 *��    ע: �ײ������ƺ���.�û�ͨ��nadmouse.h�еĸ�*
 *          �����ƺ�����ӵ���                     *
 *---------------------------------------------------*/
int get_mouse_x()
{
   _AX=0x03;
   __int__(0x33);
   return _CX;
}


/*---------------------------------------------------*
 *��������: ��ȡ��ǰ�����Y����.                   *
 *����˵��: ��.                                      *
 *����˵��: ���ع��Y����.                           *
 *��    ע: �ײ������ƺ���.�û�ͨ��nadmouse.h�еĸ�*
 *          �����ƺ�����ӵ���                     *
 *---------------------------------------------------*/
int get_mouse_y()
{
   _AX=0x03;
   __int__(0x33);
   return _DX;
}


/*---------------------------------------------------*
 *��������: ��ȡ��ǰ��갴ť״̬.                    *
 *����˵��: ��.                                      *
 *����˵��: ���ذ�ť״̬��־                         *
 *          ����0: ��ʾ���Ұ�����û����;             *
 *          ����1: ��ʾ�������;                     *
            ����2: ��ʾ�Ҽ�����;                     *
            ����3: ��ʾ���Ҽ���������.               *
 *��    ע: �ײ������ƺ���.�û�ͨ��nadmouse.h�еĸ�*
 *          �����ƺ�����ӵ���                     *
 *---------------------------------------------------*/
char get_click()
{
   _AX = 0x03;
   __int__(0x33);
   return _BX;
}


/*---------------------------------------------------*
 *��������: ��ȡ��ť����״̬.                        *
 *����˵��: ����keyָ������ĸ���:����0(��LEFT_KEY)ʱ*
 *          ��ʾ������;����1(��RIGHT_KEY)ʱ����Ҽ�*
 *          ����ָ���ͱ���*x,*y������¼���һ�ΰ���ָ*
 *          ����ʱ�Ĺ������;*count����¼���øù�����*
 *          ��ָ������ѹ�µ��ܴ���,����65535�������0*
 *����˵��: ���ص�ǰ��갴ť״̬(ͬget_click����) *
 *��    ע: �ײ������ƺ���.�û�ͨ��nadmouse.h�еĸ�*
 *          �����ƺ�����ӵ���                     *
 *---------------------------------------------------*/
unsigned get_press_info(int key, int *p_x, int *p_y, int *p_count)
{
   _BX = key;
   _AX = 0x05;
   __int__(0x33);
   *p_x=_CX;       /*ָ�������һ�ΰ���ʱ��x����*/
   *p_y=_DX;       /*ָ�������һ�ΰ���ʱ��y����*/
   *p_count = _BX; /*���ص��øù�������ָ������ѹ�µ��ܴ���(����65535���,����0)*/
   return _AX;
}


/*---------------------------------------------------*
 *��������: ��ȡ��ť�ſ�״̬.                        *
 *����˵��: ����keyָ������ĸ���:����0(��LEFT_KEY)ʱ*
 *          ��ʾ������;����1(��RIGHT_KEY)ʱ����Ҽ�*
 *          ����ָ���ͱ���*x,*y������¼���һ�ΰ���ָ*
 *          ����ʱ�Ĺ������;*count����¼���øù�����*
 *          ��ָ�������ſ����ܴ���,����65535�������0*
 *����˵��: ���ص�ǰ��갴ť״̬(ͬget_click����) *
 *��    ע: �ײ������ƺ���.�û�ͨ��nadmouse.h�еĸ�*
 *          �����ƺ�����ӵ���                     *
 *---------------------------------------------------*/
unsigned get_release_info(int key, int *p_x, int *p_y, int *p_count)
{
   _BX = key;
   _AX = 0x06;
   __int__(0x33);
   *p_x=_CX;       /*ָ�������һ���ɿ�ʱ��x����*/
   *p_y=_DX;       /*ָ�������һ���ɿ�ʱ��y����*/
   *p_count = _BX; /*���ص��øù�������ָ�������ɿ����ܴ���(����65535���,����0)*/
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
 *��������: ��ʾ�����.                            *
 *����˵��: ��.                                      *
 *����˵��: ��.                                      *
 *��    ע: �ײ������ƺ���.���Ƽ��û�ʹ��.ԭ������ *
 *          ��Win2000/WinXP�¿����޷���ʾ���.       * 
 *---------------------------------------------------*/
void show_hard_cur()
{
   _AX = 0x01;
   __int__(0x33);
}


/*---------------------------------------------------*
 *��������: ���������.�������ı���λ��,Ҫ�ȵ� *
 *          ����������ԭ���Ĺ��,�ٵ���show_hard_cur()���� *
            ʾ�µĹ��,������ƻ���Ļ����ʾ����.     *
 *����˵��: ��.                                      *
 *����˵��: ��.                                      *
 *��    ע: �ײ������ƺ���.������߰汾��Windows�� *
 *          ���Բ��ö����Ƽ��û�ʹ��.                *
 *---------------------------------------------------*/
void hide_hard_cur()
{
   _AX = 0x02;
   __int__(0x33);
}


/*---------------------------------------------------*
 *��������: ���ù�����Ч���Χ.                  *
 *����˵��: xmin:ˮƽ��������С����.             *
 *          xmax:ˮƽ�������������.             *
 *          ymin:��ֱ��������С����.             *
 *          ymax:��ֱ��������С����.             *
 *����˵��: ��.                                      *
 *��    ע: �ײ������ƺ���.�û�ͨ��nadmouse.h�еĸ�*
 *          �����ƺ�����ӵ���                     *
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



/*�ı��������״
  g_arrow_t cur:Ϊ���϶������״ */

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
 *��������: ���������ƶ��ٶ�.                      *
 *����˵��: vx,vy��ȱʡֵ:vx=8,vy=8.ֵԽ���ٶ�Խ��   *
 *����˵��: ��.                                      *
 *��    ע: �ײ������ƺ���.�û�ͨ��nadmouse.h�еĸ�*
 *          �����ƺ�����ӵ���                     *
 *---------------------------------------------------*/
void set_mouse_speed(int vx,int vy)
{
   _CX=vx;
   _DX=vy;
   _AX=0x0f;
   __int__(0x33);
}


/*---------------------------------------------------*
 *��������: ���ù���ٶȼ�������.������ƶ��ٶȳ�����*
            �õ����޺�,����ٶȽ��ӱ�.               *
 *����˵��: msΪÿ���ƶ������޵�λ(1msԼΪ1/1200Ӣ��)*
 *          msĬ��ֵΪ64/S.                          *
 *����˵��: ��.                                      *
 *��    ע: �ײ������ƺ���.�û�ͨ��nadmouse.h�еĸ�*
 *          �����ƺ�����ӵ���                     *
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
 *��������: ����NEO_SDK������߼���ʼ��.             *
 *����˵��: ��.                                      *
 *����˵��: ��.                                      *
 *��    ע: �߼������ƺ���.�û����������ʹ��������*
 *          �������ƺ���֮ǰ���ȵ���.              *
 *---------------------------------------------------*/

char install_mouse()
{
   char keys = init_mouse();
   /*�ײ������Ƴ�ʼ��*/
   if (!keys)
   {

      return FALSE;

   }

   if (!g_color_depth)
   {

   }
   /*����remove_mouse();��ֹ��ͬһ�����ж�ε��ñ��������ܳ��ֵ��ڴ�й©���*/
   remove_mouse();

   if ((g_mouse_tp = (Mouse_t *)malloc( sizeof (Mouse_t) ))==NULL)
   {

   }
   g_mouse_tp->iconbuffer_p = &g_mouse_tp->iconbuffer;


   g_mouse_tp->advclickinfo = g_mouse_tp->status_flag = g_mouse_tp->logic_x = g_mouse_tp->logic_y = 0;

   g_mouse_tp->x = (int)((g_rect_right-g_rect_left)>>1)-32;
   g_mouse_tp->y = (int)((g_rect_bottom-g_rect_top)>>1)-32;
   g_mouse_tp->dblclickdelay = MID_DBLCLICK;/*�����ΰ���������С��0.35�뼴��Ϊ��˫��*/
   g_mouse_tp->oldclickinfo = -1;

   set_mouse_range(0, 0, g_rect_right, g_rect_bottom);
   position_mouse((g_mouse_tp->x), g_mouse_tp->y);
   set_mouse_icon(NULL);
   g_routines |= 2;
        mouse_refresh();
   return keys;
}


/*---------------------------------------------------*
 *��������: ���ù������.                            *
 *����˵��: ���Ͳ���x,yΪ������λ������.           *
 *����˵��: ��.                                      *
 *��    ע: �ײ������ƺ���.�û�ͨ��nadmouse.h�еĸ�*
 *          �����ƺ�����ӵ���                     *
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
 *��������: �����ṹ�б���������ֵ����Ļ��Ӧ��λ�� *
 *          ���ƹ��                                 *
 *����˵��: ��.                                      *
 *����˵��: ��.                                      *
 *��    ע: �߼������ƺ���.�û�ͨ��mouse_refresh() *
            ��ӵ���.                                *
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
         /*�����꽫Ҫ���ǵ���Ļ*/
         g_mouse_tp->overlay_buf[v * 32 + h] = get_dot(cur_x + h, cur_y + v);
         g_mouse_tp->overlay_buf[(v+1)*32+h] = get_dot(cur_x + h, cur_y + v + 1);
      }
   }
   blit_icon(g_mouse_tp->iconbuffer_p, cur_x, cur_y);
}


/*---------------------------------------------------*
 *��������: ���ͼ�ι������.����������������        *
 *����˵��: ��.                                      *
 *����˵��: ��.                                      *
 *��    ע: �߼������ƺ���.�û�ͨ��cursor_refresh()*
 *          ��ӵ���.                                *
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
 *��������: ���ͼ�ι��ĸ�����ʾ.                  *
 *          ���������ܱ�����ʱ�������ػ���.    *
 *����˵��: ��.                                      *
 *����˵��: ��.                                      *
 *��    ע: �߼������ƺ���.�û���ֱ�ӵ���.         *
 *---------------------------------------------------*/
void cursor_refresh()
{
   if (!(g_mouse_tp->status_flag & 1))
   {
      hide_mouse();   /*����ԭ���Ĺ��*/
      show_mouse();   /*�����µĹ��.*/
   }
}


/*��ʱȥ�������*/
void scare_mouse()
{
   g_mouse_tp->status_flag |= 1;
   hide_mouse();
}


/*�ָ���ʱȥ���������*/
void unscare_mouse()
{
   g_mouse_tp->status_flag &= 0xfe;
   show_mouse();
}


/*---------------------------------------------------*
 *��������: ���ͼ�ι���ˢ��.�����û��������ѭ����*
 *          ����ˢ�����ĸ�����Ҫ״̬.              *
 *����˵��: ��.                                      *
 *����˵��: ������ƶ�����0;���򷵻�1.               *
 *��    ע: �߼������ƺ���.�û���ֱ�ӵ���.         *
 *---------------------------------------------------*/
int mouse_refresh()
{
   float timer;
   static fir_clk = 1, fir_call;

   if (!fir_call) /*�����״����м�飬���߼���������Ƿ��Ѱ�װ*/
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
      /*���û�ƶ�*/
      if ((current_x == g_mouse_tp->x) && (current_y == g_mouse_tp->y))
      {

         char click;
         _AX = 0x03;
         __int__(0x33);
         click = _BX;
         /*�������Ƿ�˫��*/
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

            /*��dblclickdelayΪMIDDLE_DBLCLICK��0.35ʱ˫����ʱ=0.35��*/
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
      /*����ƶ���*/
      else
      {
         _AX = 0x03;
         __int__(0x33);
         g_mouse_tp->advclickinfo = _BX;

      /*���¹��������������ԭ���Ĳ�ͬ,���������ػ���(���ֱ����cusor_refresh())*/
            if (!(g_mouse_tp->status_flag & 1))
            {

               vsync();

               hide_mouse();   /*����ԭ���Ĺ��*/
               show_mouse();   /*�����µĹ��.*/
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
 *��������: ���˫���ж���ʱ����.���������ڵĵ���ʱ��*
 *          ���С��˫���ж���ʱ������Ϊ��˫��.������*
 *����˵��: userdelay������:                         *
 *          FAST_DBLCLICK,MIDDLE_DBLCLICK            *
 *          ��SLOW_DBLCLICK(�û�����Զ�һ��С��1.5��*
 *          ��ʱ)                                    *
 *����˵��: ��.                                      *
 *��    ע: �߼������ƺ���.�û���ֱ�ӵ���.         *
 *---------------------------------------------------*/
void set_dbl_click_delay(int userdelay)
{
   if (g_mouse_tp==NULL)
   {

   }
   (g_mouse_tp->dblclickdelay=userdelay);
}


/*---------------------------------------------------*
 *��������: �ı���������״.                      *
 *����˵��: p_iconfile:����ļ����ļ���.             *
 *����˵��: �ı�ɹ�����1;ʧ�ܷ���0,����ΪĬ�ϵļ�ͷ *
 *          �ι��.                                  *
 *��    ע: �߼������ƺ���.�û���ֱ�ӵ���.         *
 *---------------------------------------------------*/
int set_mouse_icon(char *p_iconfile)
{
   int offset = 0;
   unsigned char *deft = NULL;

   Cursor_ptr tempcur = NULL;

   offset += 0;   /*��ʵ�����ã������������*/

   if (g_mouse_tp == NULL)
   {
        /* error*/
   }

   p_iconfile += 0; /*���ϴ˾�ֻ��Ϊ����������ʱ������*/

    /*��ָ���Ĺ���ļ��Ҳ���ʱ,ִ�����´���*/
    /*���´�������ڹ�껺��������Ĭ�ϵļ�ͷ�ι��*/
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
 *��������: ��õ�ǰ�����߼�����״̬.              *
 *����˵��: ��.                                      *
 *����˵��: ����0 : û�ж���;                        *
 *          ����1 : �������;                        *
 *          ����2 : �Ҽ�����;                        *
 *          ����3 : ����ͬʱ����;                    *
 *          ����5 : ���˫��;                        *
 *��    ע: �߼������ƺ���.�û���ֱ�ӵ���.         *
 *---------------------------------------------------*/
int get_click_info()
{
   return g_mouse_tp->advclickinfo;
}


/*---------------------------------------------------*
 *��������: ���رպ���,��Ҫ�����ͷ����ṹռ�õ���*
 *          ��.                                      *
 *����˵��: ��.                                      *
 *����˵��: ��.                                      *
 *��    ע: ��������neo_exit();���Զ����������û�һ*
 *          �㲻��ֱ�ӵ���                           *
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

/*         �ַ����          */


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
void en_out(char c, int cx, int cy); /*��ʾ�ٶ�:ÿ��Լ45000��*/
void textout(char *str, int sx, int sy);   /*��ʾ�ٶ�:ÿ��Լ45000��*/
int cn_s16_out(char *str,int x,int y);
int cn_s24_out(char *cn_str, int x, int y);
void set_cn_size(char cn_size);
void set_str_color(int color);
void text_mode(int mode);
int string_out(char *str, int x, int y); /*��ʾ�ٶ�:ÿ��Լ6000��*/

char textheight();

/*���ROM�ַ����׵�ַ*/
unsigned char far *get_asc_rom(unsigned int bx)
{
    struct REGPACK reg;
    reg.r_ax = 0x1130;
    reg.r_bx = bx;
    intr(0x10, &reg);
    return MK_FP(reg.r_es, reg.r_bp);
}


/*ѡ��Ҫʹ�õ�ASCII ROM�ַ���*/
unsigned char far *cur_asc_rom(int *chose)
{
   static char fault_ch = 8;
   static unsigned char far *romaddr = (unsigned char far *)0xf000fa6e;

   if (*chose>0)
   {
      switch (fault_ch = *chose)
      {
         case 8 : /*���8*8  ASCII ROM�ַ����׵�ַ*/
            return romaddr = get_asc_rom(0x0300);
         case 14: /*���14*8  ASCII ROM�ַ����׵�ַ*/
            return romaddr = get_asc_rom(0x0200);

         case 16: /*���16*8  ASCII ROM�ַ����׵�ַ*/
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




/*��ʾ����English�ַ�*/
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


/*��ʾEnglish�ַ���*/
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
 *�������ߣ�����.                                    *
 *��������������ǿ(��2005-1-11).                     *
 *��������: ��ʾ24�����ֵĺ���.                    *
 *����˵��: cn_str�����ַ���;x,y����ʾ���������.    *
 *����˵��: ʧ��(�����ֿ��ļ�δ�ҵ�)����-1.�ɹ�����1.*
 *��    ע: �û�����ͨ��string_out()��ӵ���. ��     *
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
   if ((fp=fopen(hzk24font,"rb+"))==NULL)/* ��24�����ֿ��ļ� */
   {/*error*/
      return -1;
   }
   len = strlen(cn_str); 
   while(n != len)
   {

      if((cn_str[n] & 0x80)==0)/* �ж��Ƿ�����չASCII */
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
