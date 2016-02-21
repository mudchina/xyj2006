// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "府门");
  set ("long", @LONG

府门高大雄伟，虹光闪烁。一边是金龙出水，另一边是银凤朝
阳，门檐上玉麒麟吞云吐雾。再往里看，楼阁宫殿紫气瑞瑞，祥
云缭绕。

LONG);

  set("exits", ([
        "north"   : __DIR__"xiaojie7",
        "south"   : __DIR__"dayuan",
        "west"   : __DIR__"jitan",
      ]));
  set("objects", ([
        __DIR__"npc/bing"  : 2,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave (object who, string dir)
{
  if (! interactive(who) &&
      dir == "south")
    return 0;

  return ::valid_leave(who,dir);
}

