// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "天阳街");
  set ("long", @LONG

天阳街位于城东，有大小客栈药房会馆，行人来往纷杂。也有一些
远道而来的路客在街上寻找休息住所，偶然可见到马车停在路边。
在南边可以见到一家挂匾的会馆，北面是消遣去处－－斗蟋馆。

LONG);

  set("exits", ([ 
    "west" : __DIR__"tian1",
    "east" : __DIR__"tian3",
    "north" : __DIR__"douxi",
    "south" : __DIR__"huitong",
  ]));
  set("objects", ([
    __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
