// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "布道场");
  set ("long", @LONG

布道场是一个干净的大屋子，道场前排为草蒲团，后排放了一
一排一排的木凳子。布道场的台上放着一个乌铁鼎，足有大半
个人高。

LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao28",
      ]));

  setup();
}


