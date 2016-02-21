// gate.c

inherit ROOM;

void create ()
{
  set ("short", "土路");
  set ("long", @LONG

路上人不是很多，偶尔有几个过客．前方是一个小镇，镇上有
一户高姓人家，却是这方圆百里土地的主人．附近的农民大多
是靠租高家的田度日．
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lu2",
  "east" : "/d/changan/wroad3",
]));
  set("outdoors", 1);

  setup();
}
