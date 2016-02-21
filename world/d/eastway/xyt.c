// create by snowcat.c 4/20/1997
// room: /d/eastway/xyt.c

inherit ROOM;

void create ()
{
  set ("short", "小雁塔");
  set ("long", @LONG

小雁塔是一座通高几十丈的砖塔，从底下向上看去，庄严而玲珑，
塔身檐角密布，一共有十五层之高，与东边的大雁塔遥遥相望。塔
底有门洞通向塔内，东边有路通向进士场。
LONG);

  set("exits", ([
        "enter"     : __DIR__"xyt1",
        "east" : __DIR__"jinshi",
      ]));
  set("outdoors", __DIR__);

  setup();
}






