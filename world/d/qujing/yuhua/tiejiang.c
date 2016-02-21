// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "铁匠铺");
  set ("long", @LONG

铁匠铺里颇为宽大，靠墙有一排大火炉，呼呼地喷着通红的火
焰。屋子后面更是一个大铁熔炉，用以制造专门的特大号铁器
和兵器。

LONG);

  set("exits", ([
        "east"   : __DIR__"xiaojie2",
      ]));
  set("objects", ([
        __DIR__"npc/tiejiang"  : 1,
      ]));

  setup();
}



