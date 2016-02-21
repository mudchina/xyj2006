// created by snowcat.c 4/4/1997
// room: /d/nuerguo/towna2.c

inherit ROOM;

void create ()
{
  set ("short", "安乐巷中");
  set ("long", @LONG

这里是西梁镇的安乐巷中。北面有一高高的大门，是西梁王
宫的主要入口。街上女人们三三两两围在一起，谈论着西梁
公主最新的招驸一事。

LONG);

  set("exits", ([
        "northup" : __DIR__"entry",
        "north" : __DIR__"jitan",
        "west"    : __DIR__"towna1",
        "east"    : __DIR__"towna3",
        "south"   : __DIR__"townb2",
    ]));
  set("outdoors", __DIR__"");

  setup();
}






