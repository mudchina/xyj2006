// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "夕林街");
  set ("long", @LONG

夕林街为朱紫国食品街市，饭馆酒楼林立，香味扑鼻。一群群食客
们沿街进出各家。南边有一家专营杂货的小店，北边是挂出大招牌
的一家面馆。

LONG);

  set("exits", ([ 
    "north" : __DIR__"mianguan",
    "south" : __DIR__"zahuo",
    "west" : __DIR__"xi3",
    "east" : __DIR__"gulou",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
