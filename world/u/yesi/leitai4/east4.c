// create by snowcat jan 21 1998


inherit ROOM;

void create ()
{
  set ("short", "大官道");
  set ("long", @LONG

一条宽阔笔直的大官道自平原上由东西向远远地伸延开来，官
道平整可容得下十马并驰。大官道的东西通向远方。

LONG);

  set("exits", ([
        "west" : __DIR__"east3",
        "east" : __DIR__"east5",
      ]));
  set("outdoors", __DIR__);

  set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
  setup();
}


