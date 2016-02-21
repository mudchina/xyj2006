// create by snowcat.c 4/8/1997
// room: /d/westway/dadao.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","大道");
  set ("long", @LONG

这是一条长长的大道，在远远的山脚下绕过。大地苍茫，西北
风呼呼地吹着，卷起路上扬起的风沙。这里的行人明显地少了，
都在匆匆忙忙地赶着路，往东是金城郡，往西面再赶一赶路就
可以到达永靖了。

LONG);

  set("exits", ([
        "east" : __DIR__"jincheng",
        "west" : __DIR__"yongjing",
      ]));
   set("objects",([
 //  "/d/qujing/kusong/npc/jiruhuo" : 1,
   "/d/shendian/babu/axiuluo" : 1,
   ]));
  set("outdoors", __DIR__);

  setup();
}



