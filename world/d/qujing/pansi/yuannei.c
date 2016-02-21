// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "院内");
  set ("long", @LONG

院内整整齐齐，碎砖铺路绿草茵荫。东北角堆着一些干茅草，
有一石灶上架设一铜丹炉，青烟袅袅。砖路自门口往南铺设过
去，通向一个厅门。

LONG);

  set("exits", ([
        "west"    : __DIR__"menqian",
        "south"    : __DIR__"zheng",
      ]));
  set("objects", ([
        __DIR__"obj/danlu"    : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

