// create by snowcat.c 4/20/1997
// room: /d/eastway/guandao2.c

inherit ROOM;

void create ()
{
  set ("short", "官道");
  set ("long", @LONG

这是一条长长的官道，官道上马车并行，人来人往。官道的西边远
远通向进士场，西边和南边各有一座高塔，东北边通向更远处。
LONG);

  set("exits", ([
        "northwest"      : __DIR__"wangnan3",
        "northeast" : __DIR__"guandao3",
      ]));
  set("outdoors", __DIR__);

  setup();
}






