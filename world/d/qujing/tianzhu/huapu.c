// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "花铺");
  set ("long", @LONG

花铺里一阵清香扑鼻，沿街的门口种着一些鲜花，铺里面墙头
挂着五颜六色的干花草，柜台上则是许多漂亮的花瓶，瓶内插
着各式各样的鲜花。

LONG);

  set("exits", ([
        "south"   : __DIR__"jiedao13",
      ]));
  set("objects", ([
        __DIR__"npc/dai"   : 1,
      ]));

  setup();
}


