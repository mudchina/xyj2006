//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/road3.c

inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

让人奇怪的是一个妖精住的地方居然会如此的整洁，一切物品
都是错落有秩，更有些松儿，柏儿，真是弘誓无边垂侧隐。
LONG);

  set("exits", ([
        "south"  : __DIR__"in2",
        "out"  : __DIR__"dongkou",
      ]));
  set("objects",([
        __DIR__"npc/yaojing":2,
        ]));
  setup();
}
