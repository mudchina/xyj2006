// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

一条小路自花园里伸出来，小路上铺满了小碎石子。旁边的花
圃里飘来阵阵花香，东南边有一去处，搭着一座干净的石泥房
子。

LONG);

  set("exits", ([
        "west"   : __DIR__"huayuan3",
        "southeast"   : __DIR__"zhai",
      ]));
  set("outdoors", __DIR__);

  setup();
}



