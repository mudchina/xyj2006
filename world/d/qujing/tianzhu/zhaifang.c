// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "斋房");
  set ("long", @LONG

斋房靠窗是两口大锅，灶里烧着柴火冒着青烟，锅里热水滚滚。
房子的南端有一大木桌，桌上放着一些粗瓷碗盆。北边是门，
通向寺院的菜园。

LONG);

  set("exits", ([
        "north"   : __DIR__"houyuan",
      ]));

  setup();
}


