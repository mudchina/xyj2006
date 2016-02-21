// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "宝殿");
  set ("long", @LONG

殿上供着一尊大佛，佛象的周围有香案香炉，香炉里插着几柱
香袅袅地冒着烟。殿东地上铺着几块干净的蒲团，佛象后往西
有一道门开着，通向里面。

LONG);

  set("exits", ([
        "west"   : __DIR__"fang",
        "east"   : __DIR__"siyuan",
        "southeast"   : __DIR__"houyuan",
      ]));
  set("objects", ([
        __DIR__"npc/monk"   : 1,
      ]));

  setup();
}


