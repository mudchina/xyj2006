// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
 
//   File   :  /include/ansi.h
//   Creator   :  Gothic@TMI-2  
//
//   The standard set of ANSI codes for mudlib use.
 
#define ESC   ""
#define CSI   ESC + "["
 
                /*  Foreground Colors  */
 
#define BLK ESC+"[30m"          /* Black    */
#define RED ESC+"[31m"          /* Red      */
#define GRN ESC+"[32m"          /* Green    */
#define YEL ESC+"[33m"          /* Yellow   */
#define BLU ESC+"[34m"          /* Blue     */
#define MAG ESC+"[35m"          /* Magenta  */
#define CYN ESC+"[36m"          /* Cyan     */
#define WHT ESC+"[37m"          /* White    */
 
                /*   Hi Intensity Foreground Colors   */
 
#define HIR ESC+"[1;31m"        /* Red      */
#define HIG ESC+"[1;32m"        /* Green    */
#define HIY ESC+"[1;33m"        /* Yellow   */
#define HIB ESC+"[1;34m"        /* Blue     */
#define HIM ESC+"[1;35m"        /* Magenta  */
#define HIC ESC+"[1;36m"        /* Cyan     */
#define HIW ESC+"[1;37m"        /* White    */
#define FLA ESC+"[5m"

                /* High Intensity Background Colors  */

#define HBRED ESC+"[41;1m"       /* Red      */
#define HBGRN ESC+"[42;1m"       /* Green    */
#define HBYEL ESC+"[43;1m"       /* Yellow   */
#define HBBLU ESC+"[44;1m"       /* Blue     */
#define HBMAG ESC+"[45;1m"       /* Magenta  */
#define HBCYN ESC+"[46;1m"       /* Cyan     */
#define HBWHT ESC+"[47;1m"       /* White    */
 

#define REDGRN ESC+"[1;31;42m"        /* Magenta  */
#define REDYEL ESC+"[1;31;43m"
#define REDBLU ESC+"[1;31;44m"
#define REDMAG ESC+"[1;31;45m"
#define REDCYN ESC+"[1;31;46m"
#define REDWHI ESC+"[1;31;47m"
#define GRNRED ESC+"[1;32;41m"
#define GRNYEL ESC+"[1;32;43m"
#define GRNBLU ESC+"[1;32;44m"
#define GRNMAG ESC+"[1;32;45m"
#define GRNCYN ESC+"[1;32;46m"
#define GRNWHI ESC+"[1;32;47m"
#define YELRED ESC+"[1;33;41m"
#define YELGRN ESC+"[1;33;42m"
#define YELBLU ESC+"[1;33;43m"
#define YELMAG ESC+"[1;33;45m"
#define YELCYN ESC+"[1;33;46m"
#define YELWHI ESC+"[1;33;47m"
#define BLURED ESC+"[1;34;41m"
#define BLUGRN ESC+"[1;34;42m"
#define BLUYEL ESC+"[1;34;43m"
#define BLUMAG ESC+"[1;34;45m"
#define BLUCYN ESC+"[1;34;46m"
#define BLUWHI ESC+"[1;34;47m"
#define MAGRED ESC+"[1;35;41m"
#define MAGGRN ESC+"[1;35;42m"
#define MAGYEL ESC+"[1;35;43m"
#define MAGBLU ESC+"[1;35;44m"
#define MAGCYN ESC+"[1;35;46m"
#define MAGWHI ESC+"[1;35;47m"
#define CYNRED ESC+"[1;36;41m"
#define CYNGRN ESC+"[1;36;42m"
#define CYNYEL ESC+"[1;36;43m"
#define CYNBLU ESC+"[1;36;44m"
#define CYNMAG ESC+"[1;36;45m"
#define CYNWHI ESC+"[1;36;47m"
                /*  Background Colors  */
 
#define BBLK ESC+"[40m"          /* Black    */
#define BRED ESC+"[41m"          /* Red      */
#define BGRN ESC+"[42m"          /* Green    */
#define BYEL ESC+"[43m"          /* Yellow   */
#define BBLU ESC+"[44m"          /* Blue     */
#define BMAG ESC+"[45m"          /* Magenta  */
#define BCYN ESC+"[46m"          /* Cyan     */
// #define BWHT ESC+"[47m"          /* White    */

#define NOR ESC+"[2;37;0m"      /* Puts everything back to normal */
 
/*  Additional ansi Esc codes added to ansi.h by Gothic  april 23,1993 */
/* Note, these are Esc codes for VT100 terminals, and emmulators */
/*       and they may not all work within the mud               */
 
#define BOLD ESC+"[1m"          /* Turn on bold mode */
#define CLR ESC+"[2J"           /* Clear the screen  */
#define HOME ESC+"[H"           /* Send cursor to home position */
#define REF CLR+HOME            /* Clear screen and home cursor */
#define BIGTOP ESC+"#3"         /* Dbl height characters, top half */
#define BIGBOT ESC+"#4"         /* Dbl height characters, bottem half */
#define SAVEC ESC+"[s"           /* Save cursor position */
#define REST ESC+"[u"            /* Restore cursor to saved position */
//#define REVINDEX ESC+"M"        /* Scroll screen in opposite direction */
#define SINGW ESC+"#5"          /* Normal, single-width characters */
#define DBL ESC+"#6"            /* Creates double-width characters */
#define FRTOP ESC+"[2;25r"      /* Freeze top line */
#define FRBOT ESC+"[1;24r"      /* Freeze bottom line */
#define UNFR ESC+"[r"           /* Unfreeze top and bottom lines */
#define BLINK ESC+"[5m"         /* Initialize blink mode */
#define U ESC+"[4m"             /* Initialize underscore mode */
#define REV ESC+"[7m"           /* Turns reverse video mode on */
#define HIREV ESC+"[1,7m"       /* Hi intensity reverse video  */

//ADD AKAI 2006

#define FLASH   ESC+"[5m"           // flash
                /*¹ØÓÚÐÐ¿ØÖÆ */
                /*1.ÒÆ¶¯ */
#define TOTOP(x)        (ESC+"["+x+"A")         /*ÏòÉÏÌø×ªxÐÐ*/
#define TOBOT(x)        (ESC+"["+x+"B")         /*ÏòÏÂÌø×ªxÐÐ*/
                                                /*µ± ÓÎ±êÒÑ¾­ÔÚÓ©Ä»µÄ×îÏÂÒ»ÁÐÊ±, ´ËÒ»ÃüÁîÃ»ÓÐ×÷ÓÃ*/
#define TORIGHT(x)      (ESC+"["+x+"C")         /*ÏòÓÒÒÆ¶¯xÐÐ*/
                                                /*µ±ÓÎ±êÒÑ¾­ÔÚÓ©Ä»µÄ×îÓÒÒ»À¸Ê±, ´ËÒ»ÃüÁîÃ»ÓÐ×÷ÓÃ¡£*/
#define TOLEFT(x)       (ESC+"["+x+"D")         /*Ïò×óÒÆ¶¯xÐÐ*/
                                                /*µ±ÓÎ±êÒÑ¾­ÔÚÓ©Ä»µÄ×î×óÒ»À¸Ê±, ´ËÒ»ÃüÁîÃ»ÓÐ×÷ÓÃ¡£*/
#define TOPOINT(x,y)    (ESC+"["+x+";"+y+"f")   /*ÒÆ¶¯µ½µã×ø±êÎª(x,y) x:ÐÐ£¬y:ÁÐ*/
#define TOPOINTA(x,y)   (ESC+"["+x+";"+y+"H")
                /*2.Çå³ýÆÁÄ»*/
#define CLR_LINE        ESC+"[K"                /*Çå³ýµ½ÐÐÎ²*/
#define SETDISPLAY(x,y) (ESC+"["+x+";"+y+"f")
// #define DELLINE      ESC+"[K"
                /*3.¶³½áÆÁÄ»Ö¸¶¨ÐÐ*/
/* ¶³½áÆÁÄ»Ö¸¶¨ÐÐ£¬x ÊÇÐÐºÅ£¬´ÓÉÏÍùÏÂÊý£¬·Ö±æÂÊÎª 800 x 600£¬y = 35£¬
 * ·Ö±æÂÊÎª 1024 x 768£¬y = 40¡£  */
#define FRELINE(x,y)    (ESC+"["+x+";"+y+"r")

#define CUP(n)		sprintf(ESC+"[%dA",n)	/* Cursor Up n lines */
#define CDOWN(n)	sprintf(ESC+"[%dB",n)	/* Cursor Down n lines */
#define CFW(n)		sprinff(ESC+"[%dC",n)	/* Cursor Forward n characters */
#define CBK(n)		sprintf(ESC+"[%dD",n)	/* Cursor Backward n characters */
#define DELLINE		sprintf(ESC+"[K\n"+CUP(1))
			                        /* Erase to end of line and move Cursor to home of the line */
#define CMOVE(y,x)	sprintf(ESC+"[%d;%dH",y,x)	
                                                /* Move Cursor to (y,x) position */
#define BEEP ""


