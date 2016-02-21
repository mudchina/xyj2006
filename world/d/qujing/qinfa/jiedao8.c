// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

街道宽敞，两边或是商店门铺，或是住宅庭院，墙上爬满藤花
蔓草。街上各色行人人来来往往颇为热闹，东面西面均有客店
供远途旅客歇脚，南边是一座城门。

LONG);

  set("exits", ([
        "north"    : __DIR__"nanshi",
        "south"    : __DIR__"nanmen",
        "west"    : __DIR__"guafu",
        "east"    : __DIR__"xiaoer",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

