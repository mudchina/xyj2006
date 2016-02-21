// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "杂货店");
  set ("long", @LONG

杂货店门面不大，靠墙放有一排长长的货架，上面摆着各式各样的
朱紫国杂货。店家是一位大胖子，旁边坐着的，是他的瘦婆娘。两
人正倚窗晒着太阳。

LONG);

  set("exits", ([ 
    "north" : __DIR__"xi4",
  ]));
  set("objects", ([ 
    __DIR__"npc/pang" : 1,
    __DIR__"npc/shou" : 1,
  ]));
  setup();
}
