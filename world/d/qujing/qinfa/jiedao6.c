// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

街道宽敞，两边或是商店门铺，或是住宅庭院，墙上爬满藤花
蔓草。街上各色行人人来来往往颇为热闹，西面是五鼓楼，东
面通向其它的街道。

LONG);

  set("exits", ([
        "north"    : __DIR__"jiedao3",
        "east"    : __DIR__"jiedao7",
        "west"    : __DIR__"wugu",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

