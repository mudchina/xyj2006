//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/born.c

inherit ROOM;

void create ()
{
  set ("short", "谷仓");
  set ("long", @LONG

这里是这户人家的谷仓，你几乎根本没法在这呆下去，因为这里
的稻谷实在是太多了，你有觉得很奇怪，一个妇道人家，而且带
着三个女儿，怎么会有这么多的谷子呢。

LONG);
  set("exits", ([
        "west": __DIR__"house",
          ]));
  setup();
}
