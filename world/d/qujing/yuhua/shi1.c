// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "石墙");
  set ("long", @LONG

墙的南面，高高的石墙下，有一狭窄的通道如小路一般，被人
踩得结结实实。

LONG);

  set("exits", ([
        "east"   : __DIR__"shi2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



