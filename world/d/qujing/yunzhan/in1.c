//Cracked by Roath

//  ÑýÉñÖ®Õù £±¡££°
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "¶´¿Ú");
  set ("long", @LONG

Ò»×ß½øÀ´£¬Äã·¢ÏÖ¼¸¸öÄ£ºý²»ÇåµÄ´ó×Ö£º
[32m
                    ¡Ð¡Ð¡Ð¡Ð¡Ð¡Ð¡Ð¡Ð¡Ð
                    ¡Ð  [1;37mÔÆ  Õ»  ¶´[0;32m  ¡Ð
                    ¡Ð¡Ð¡Ð¡Ð¡Ð¡Ð¡Ð¡Ð¡Ð 
LONG);

  set("exits", ([
        "north"  : __DIR__"in2",
        "up"  : __DIR__"shanlu3",
      ]));
  setup();
}
