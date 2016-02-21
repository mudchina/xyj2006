// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "朱紫街");
  set ("long", @LONG

朱紫国的中心大道，由附近山上运来的条石铺成，可通行来往马车。
往北是繁华的街口与北霞街相连，往南是朱紫国的城中心鼓楼，再
往南可见朱紫国皇宫。

LONG);

  set("exits", ([ 
    "north" : __DIR__"jiekou",
    "south" : __DIR__"gulou",
    "west" : __DIR__"mianguan",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
