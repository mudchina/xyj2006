inherit ROOM;

#include <cf.h>
void create ()
{
  set ("short", "禅房");
  set ("long", @LONG
这里空荡荡的，只在靠近墙壁的地方整整齐齐地放着一些蒲团。
房里光线很暗，墙壁不知道是什么材料做的，会发出淡淡的黄
光。这里是坐禅(zuochan)参悟的好地方。你要是实在定不下心
也可以出去走走再回来(halt)。

LONG);

  set("exits", ([
          "west"   : __DIR__"baoge1",
      ]));
  
  set("no_fight", 1);
  set("no_magic", 1);
  setup();
}
