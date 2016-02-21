// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "宝阁");
  set ("long", @LONG

宝阁是一偏殿，殿的东墙下有一排木柜子，柜门上贴着红签条，
柜台上有一签筒，一木鱼一木棰。另有一个小香炉，插着未烧
完的香。宝阁的北面是大雄宝殿。

LONG);

  set("exits", ([
        "north"   : __DIR__"daxiong",
      ]));

  set("objects", ([
        __DIR__"npc/tong"   : 3,
    ]));

  setup();
}



