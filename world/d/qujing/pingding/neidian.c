// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "内殿");
  set ("long", @LONG

石洞在这里宽敞起来，形成一个殿厅。殿里有半人高的石块，
上面搭着长木板，边上有石鼓和石桩子。殿的东边是卧室，东
北边通向石廊。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"shilang2",
        "east"   : __DIR__"wofang1",
        "southwest"   : __DIR__"wofang2",
      ]));
  set("objects", ([
        __DIR__"npc/yao2"   : 3,
      ]));

  setup();
}


