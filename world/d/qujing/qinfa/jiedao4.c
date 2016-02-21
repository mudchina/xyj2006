// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

街道宽敞，两边或是商店门铺，或是住宅庭院，墙上爬满藤花
蔓草。街上各色行人人来来往往颇为热闹，西面的店铺门口晒
着一些皮货。

LONG);

  set("exits", ([
        "east"    : __DIR__"jiedao5",
        "west"    : __DIR__"pihuopu",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

