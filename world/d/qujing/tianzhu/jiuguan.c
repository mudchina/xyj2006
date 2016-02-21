// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "酒馆");
  set ("long", @LONG

几个大酒缸并排放在屋里靠里墙的地方，散发着浓烈的酒香，
正堂摆着六张红木酒桌，每个桌子上放着几碟小菜，给来喝酒
的酒客们下酒。

LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao21",
        "north"   : __DIR__"jiedao12",
      ]));
  set("objects", ([
        __DIR__"npc/huang"   : 1,
        "/d/obj/food/huasheng" : 2,
      ]));

  setup();
}


