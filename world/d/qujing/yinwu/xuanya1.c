// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "悬崖");
  set ("long", @LONG

苍山峻岭，峰势崔巍，只见顶上白云飘飘，崖前树影寒寒，林
内松柏千千，峦头翠竹几干。四处怪石嶙嶙，使人心感不安，
难以擅自举步。

LONG);

  set("exits", ([
        "east"    : __DIR__"xuanya2",
        "southwest"    : __DIR__"xuanya6",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

