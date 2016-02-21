//Cracked by Roath
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/in2.c

inherit ROOM;

void create ()
{
  set ("short", "¶´ÖĞ");
  set ("long", @LONG

ÕâÊÇÕû¸ö¶´Ñ¨µÄÖĞ¼ä£¬ÁîÈËÆæ¹ÖµÄÊÇÂ·µÄÁ½ÅÔ¾ÓÈ»ÓĞÒ»·ù¶ÔÁª£º
[33m
                 ¾²  ¾²  Éî  É½  ÎŞ  Ë×  ÂÇ
                 ÓÄ  ¾Ó  ÏÉ  ¶´  ÀÖ  Ìì  Õæ
[m
LONG);

  set("exits", ([
        "southup"  : __DIR__"cave",
        "north"  : __DIR__"in1",
        "west"   : __DIR__"in5",
        ]));
   set("objects",([
        __DIR__"npc/yaojing":2,
        ]));
  setup();
}
