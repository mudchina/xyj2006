// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "山石冈");
  set ("long", @LONG

山石冈四处是碎石块，石块的缝隙里长出一些杂草。路的两边
为赫色的山岩，尖锋利刃。石冈远远近近地长着一些古树，在
山风中摇曳。

LONG);

  set("exits", ([
        "north"   : __DIR__"jindou1",
        "southeast"   : __DIR__"shanshi2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



