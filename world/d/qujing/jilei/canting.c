//Cracked by Roath
// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "餐厅");
  set ("long", @LONG

餐厅是一个石洞自然形成的偏厅，厅角支着一口大铁锅，底下
烧着大火。铁锅边有一铁架，上面的肉巴子烤得直冒油，散发
出诱人的香味。

LONG);

  set("exits", ([
        "east"   : __DIR__"dating",
        "southwest"   : __DIR__"cangku",
      ]));
  set("objects", ([
        __DIR__"npc/yao" : 5,
        __DIR__"obj/rou" : 3,
      ]));

  setup();
}



