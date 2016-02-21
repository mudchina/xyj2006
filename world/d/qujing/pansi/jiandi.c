// created by snowcat.c 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "涧底");
  set ("long", @LONG

山涧低洼地带，四处是涧水潺潺，几乎无法落脚。两边是高山
峻岭，东边涧流水急很难涉过，西边有一陡坡向上。

LONG);

  set("exits", ([
        "westup"    : __DIR__"jiankou1",
        "down"    : __DIR__"jiandi2",
      ]));
  set("objects", ([
        __DIR__"npc/shuizhi" : 1,
      ]));
  set("outdoors",__DIR__"");
  setup();
}

