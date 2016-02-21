// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "朱紫街");
  set ("long", @LONG

朱紫国的中心大道，由附近山上运来的条石铺成，可通行来往马车。
往北通向朱紫国的北门朱紫门，往南通向朱紫国的城中心，再往南
就是皇宫所在地。

LONG);

  set("exits", ([ 
    "north" : __DIR__"zhuzi1",
    "south" : __DIR__"jiekou",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
