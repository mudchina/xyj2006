//Cracked by Roath

//  ÑıÉñÖ®Õù £±¡££°
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "É½Â·");
  set ("long", @LONG

Ö»¼ûÇ°·½µÄÉ½¶¥Ö±²åÔÆÏö£¬ÕæÊÇ¸öÏÕ°¡£¬¾ÍÁ¬ÖÜÎ§µÄÊ÷Ò²ÊÇÆæ
¸ßÎŞ±È£¬Ò»¿Ã¿Ã·Â·ğÓëÌìÏà½Ó£¬Ç°·½ÓĞÒ»¿éÊ¯±®£¬ÉÏÊé£º
[33m
                      ¸£   Áê   É½[m

LONG);

  set("exits", ([
        "eastdown"  : __DIR__"road5",
        "westup"  : __DIR__"shanlu2",
      ]));
  set("outdoors","yz");
  setup();
}
