// Room: /d/jjf/son_cabinet.c

inherit ROOM;

void create ()
{
  set ("short", "东厢房");
  set ("long", @LONG
东厢是秦公子的住处。秦琼的家教极严，秦公子早上要练功，
下午要读书。屋里陈设绝没有富家的奢华，墙上挂着一柄金装锏，
桌上放着三两部书，连床帐都只是青布的。
LONG);

  set("outdoors", 0);
  set("if_bed", 1);
  set("sleep_room", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"son_shufang",
  "northwest" : __DIR__"se_garden",
]));

  setup();
}
