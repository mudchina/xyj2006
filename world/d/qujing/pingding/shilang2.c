// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "石廊");
  set ("long", @LONG

石廊在此有一点回转，两边的石壁上长着褐色的地衣，布满整
个壁面。地上坑坑洼洼，积着几汪泥水。石廊的西南通向莲花
洞的内殿。

LONG);

  set("exits", ([
        "north"   : __DIR__"shilang1",
        "southwest"   : __DIR__"neidian",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 4,
      ]));

  setup();
}



