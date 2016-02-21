// by snowcat 11/6/1997
inherit ROOM;

void create()
{
  set ("short", "护宫河");
  set ("long", @LONG

……你站在齐胸深的护宫河水里……

LONG);
  set("exits", ([ 
    "east" : __DIR__"gongmen",
  ]));
  set("outdoors", __DIR__"");
  setup();
}
