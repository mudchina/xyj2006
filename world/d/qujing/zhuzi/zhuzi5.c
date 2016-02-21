// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "朱紫街");
  set ("long", @LONG

朱紫国的中心大道，由附近山上运来的条石铺成，可通行来往马车。
往北可以看见朱紫国的鼓楼，东边是一座兵营，南边就是朱紫国的皇
宫大门。

LONG);
  set("exits", ([ 
    "south" : __DIR__"gongmen",
    "north" : __DIR__"zhuzi4",
    "east" : __DIR__"bingying",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
