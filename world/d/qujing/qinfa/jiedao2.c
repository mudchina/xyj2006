// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "街道");
  set ("long", @LONG

街道宽敞，两边或是商店门铺，或是住宅庭院，墙上爬满藤花
蔓草。街上各色行人人来来往往颇为热闹，东面是乾坤场，北
面有一布铺的招牌。

LONG);

  set("exits", ([
        "north"    : __DIR__"bupu",
        "west"    : __DIR__"jiedao1",
        "east"    : __DIR__"qiankun",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

