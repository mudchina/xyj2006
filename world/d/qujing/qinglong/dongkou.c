// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "洞口");
  set ("long", @LONG

只见山中恍然一个飘着雾气的洞口，洞口向南大开，上有无数
青藤自崖顶挂下来，两边的怪石狰狞如兽牙。洞上写着几个大
字：青龙山玄英洞。

LONG);

  set("exits", ([
        "southwest"   : __DIR__"shanding",
        "north"   : __DIR__"tongdao1",
      ]));
  set("objects", ([
        __DIR__"npc/yao"  : 1,
      ]));

  setup();
}



