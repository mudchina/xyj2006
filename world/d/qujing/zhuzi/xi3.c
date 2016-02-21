// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "夕林街");
  set ("long", @LONG

夕林街为朱紫国食品街市，饭馆酒楼林立，香味扑鼻。一群群食客
们沿街进出各家。北面是熙熙攘攘的茶房，南边是朱紫国的一家大
米铺。

LONG);

  set("exits", ([ 
    "north" : __DIR__"chafang",
    "south" : __DIR__"mipu",
    "west" : __DIR__"xi2",
    "east" : __DIR__"xi4",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
