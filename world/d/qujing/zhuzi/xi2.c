// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "夕林街");
  set ("long", @LONG

夕林街为朱紫国食品街市，饭馆酒楼林立，香味扑鼻。一群群食客
们沿街进出各家。北面是一家写着酒字招牌的酒店，南面是一座经
常客满的饭楼。

LONG);

  set("exits", ([ 
    "north" : __DIR__"jiudian",
    "south" : __DIR__"fanlou",
    "west" : __DIR__"xi1",
    "east" : __DIR__"xi3",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
