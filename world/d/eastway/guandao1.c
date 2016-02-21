// Room: /d/eastway/guandao1.c

inherit ROOM;

void create()
{
  set("short", "官道");
  set("long", @LONG

这是一条长长的官道，官道上马车并行，人流不断。多是去慈恩寺中
烧香拜佛的善男信女，其中更以大户人家中的太太小姐为多。南边可
看到寺院，隐约一个塔影闪在寺后。
LONG
  );
  set("exits", ([ /* sizeof() == 3 */
    "northwest" : __DIR__"wangnan5",
    "south" : __DIR__"ciensiw",
  ]));
  set("objects", ([
    __DIR__"npc/luren"     : 2,
  ]));
  set("no_clean_up", 0);
  set("outdoors", __DIR__"");

  setup();
  replace_program(ROOM);
}
