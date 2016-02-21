// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "北洞");
  set ("long", @LONG

北洞里面靠墙的地方垒着几块大石头，石头已被熏得漆黑，上
面吊着一口大铁锅，石头边放着山柴，干草等。西南方有一出
口通向洞门。

LONG);

  set("exits", ([
        "southwest"   : __DIR__"dongmen",
      ]));
  set("objects", ([
        __DIR__"npc/yao1"   : 3,
        __DIR__"npc/yinjiao"   : 1,
      ]));

  setup();
}


