// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "林道");
  set ("long", @LONG

古树林立，藤蔓缠绕着树枝倒挂着下来。地上是枯枝残叶，走
上去吱吱作响。林道两边树林遮阴，散发着团团水雾气，林子
的上空白云飘散霞光彩练万道。

LONG);

  set("exits", ([
        "east"   : __DIR__"lindao2",
        "southwest"   : __DIR__"lindao8",
      ]));
  set("outdoors", __DIR__);

  setup();
}



