// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "天阳街");
  set ("long", @LONG

天阳街位于城东，有大小客栈药房会馆，行人来往纷杂。也有一些
远道而来的路客在街上寻找休息住所，偶然可见到马车停在路边。
北面是一家老字号药铺。

LONG);

  set("exits", ([ 
    "west" : __DIR__"gulou",
    "east" : __DIR__"tian2",
    "north" : __DIR__"yaopu",
  ]));
  set("objects", ([
  __DIR__"npc/people" : 2,
  ]));
  set("outdoors", __DIR__"");
  setup();
}
