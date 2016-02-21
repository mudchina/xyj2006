//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/liusha/dadao1

inherit ROOM;
#include <hedi.h>

void create ()
{
  set ("short", "河底");
  set ("long", @LONG

四周无数个旋涡无声的扑击着，又形成了一个巨大的旋涡，滑
向了河的深处，声势骇然，却寂静无声，你再也站不住了，如
风吹荷花，摇摆不定，随时都有可能被旋涡卷走。

LONG);
  set("exits", ([
        "west":   __DIR__"hedi10",
        "northeast":   __DIR__"hedi6",
        ]));
  set("objects",([
        "/d/jz/obj/fish2" : 2,
        ]));
  setup();
}
