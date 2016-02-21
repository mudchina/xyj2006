// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

街道宽敞，两边或是商店门铺，或是住宅庭院，墙上爬满藤花
蔓草。街上各色行人人来来往往颇为热闹，南北面各有路口，
东面飘来阵阵酒香。

LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao6",
        "north"    : __DIR__"jiedao1",
        "east"    : __DIR__"jiupu",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

