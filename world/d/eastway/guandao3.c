// create by snowcat.c 4/20/1997
// room: /d/eastway/guandao3.c

inherit ROOM;

void create ()
{
  set ("short", "官道");
  set ("long", @LONG

这是一条长长的官道，官道上马车并行，人来人往。官道一头伸向
西南，一头伸向东北，东边有一座丘陵。
LONG);

  set("exits", ([
        "southwest"  : __DIR__"guandao2",
        "southeast"  : __DIR__"huaqing",
        "east"       : __DIR__"shihuang",
      ]));
  set("outdoors", __DIR__);

  setup();
}






