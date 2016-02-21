//Cracked by Roath
//  ÑýÉñÖ®Õù £±¡££°
//  by happ@YSZZ 2000.4.3
//  /d/qujing/yingjian/xiaolu1.c

inherit ROOM;
#include <jiandi.h>

void create ()
{
  set ("short", "[1m½§µ×[m");
  set ("long", @LONG

½§µ×µ½´¦¶¼ÊÇÐ©Ë®²Ý£¬»¹ÓÐÐ©Ð¡ÏºÃ×£¬Óã¶ù´©À´´©È¥£¬Å¼¶û»¹ÄÜ¿´µ½
Ò»Á½¾ßº¡¹Ç£¬¿´À´¶¼ÊÇ°×Áú³ÔÊ£µÄ¹ÇÍ·¡£

LONG);

  set("exits", ([
        "north" : __DIR__"jiandi4",
        "west"  : __DIR__"jiandi2",
      ]));
   set("objects", ([
        "/d/jz/obj/fish": 3,
        ]));
  setup();

}
