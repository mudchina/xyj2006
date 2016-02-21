// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "压龙山");
  set ("long", @LONG

山脊起伏，云雾缥缈一片，在此可见四处森林茂密，一些山岩
奇峰从树木中耸立出来，长着青苔地衣，色彩如斑如锈。小路
从山脊上蜿蜒地穿过。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"yalong1",
        "westup"   : __DIR__"yalong2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



