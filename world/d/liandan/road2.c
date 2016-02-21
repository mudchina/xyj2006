// By canoe 2001-06-21
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","Ğ¡  Â·");
	set("long",@LONG
ÕâÀïÊÇÒ»ÌõÓÄ¾²µÄĞ¡Â·£¬Â·ÅÔÈ«²¿ÊÇĞ©Ææ»¨Òì²İ£¬µ«ÊÇÇ°Ãæ
ÒşÒşÔ¼Ô¼ÓĞÆ¬²İµØ¡£Äã²»ÓÉµÄÏëÈ¥¿´¿´£¡ÇåÑÌºÍÔÆÎíçÔÈÆ×Å£¬ÃÀÀö
¼«ÁË¡£µØÉÏÊúÁË¿éÅÆ×Ó(paizi),Î÷±ßÊÇÉñÅ©ÊÏÁ¶µ¤Ò©µÄµØ·½¡£
LONG
);
	
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road1",
  "north":__DIR__"road3",
  "west": __DIR__"datang",
  "east":__DIR__"yejinpu",
        
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
  [1;31m
 	 £ª£ª£ª£ª£ª£ª
    	 £ª	    £ª
    	 £ª Éñ   ÉÃ £ª
   	 £ª Å©   Èë £ª
   	 £ª Ò©   Õß £ª
   	 £ª ÆÔ   ËÀ £ª
   	 £ª	    £ª
    	 £ª£ª£ª£ª£ª£ª
[m
"]));
 set("objects", ([
    "/d/liandan/obj/baicaoxian1" : random(2) ,
    "/d/liandan/obj/baicaoxian2" : random(2) ,
    "/d/liandan/obj/xianguan" : random(2) ,
         ]));
 
setup();
}
