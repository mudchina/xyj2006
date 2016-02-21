// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "遏恶场");
  set ("long", @LONG

遏恶场里金壁辉煌，无数灯烛将场地照得十分明亮。场前的台上吊着
一口镀金大铜钟，两边挂着几面巨锣。场的西北边是出口，西边有一
门通往其它的场。

LONG);

  set("exits", ([
        "northwest" : __DIR__"shuilu",
        "west" : __DIR__"jixian",
      ]));
  set("objects", ([
        __DIR__"npc/people" :  3,
        __DIR__"npc/hu" :  1,
      ]));

  setup();
}


