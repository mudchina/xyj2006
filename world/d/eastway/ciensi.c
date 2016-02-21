// create by snowcat.c 4/20/1997
// room: /d/eastway/ciensi.c

inherit ROOM;

void create ()
{
  set ("short", "慈恩寺");
  set ("long", @LONG

走进慈恩寺，进入眼帘的是雄伟的大雁塔，七层突兀于灵空，甚是壮
观。寺内古柏森森，绿阴成片，左右钟鼓楼遥遥相对。院内有两组石
碑群，为一些著名进士所题刻。
LONG);

  set("exits", ([
        "out"      : __DIR__"ciensiw",
        "east"     : __DIR__"dyt",
      ]));
  set("objects", ([
        __DIR__"npc/sengren"     : 3,
      ]));
  set("outdoors", __DIR__);

  setup();
}






