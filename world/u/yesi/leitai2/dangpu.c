#include <room.h>

inherit HOCKSHOP;

void create ()
{
  set ("short", "当铺");
  set ("long", @LONG

开封城里有名的一家当铺。铺子的门口上方挂了一个大大的“当”字
招牌，里面有一高高的长柜台，徐老板在里面端坐。当铺的墙上有一
匾(bian)，西边是尧王大街。

LONG);

  set("exits", ([
    "west" : __DIR__"yao3",
  ]));
  set("item_desc", ([ /* sizeof() == 1 */
    "bian" : "
客官可以在本当铺：
  典当(pawn)         
  卖断(sell)       
  估价(value)         
  赎回(retrieve stamp) 
  购买(buy) 用list查看。

  "]));
  set("objects", ([
    __DIR__"npc/xu" : 1,
  ]));
  set("no_clean_up", 1);

  setup();
}

int clean_up()
{
      return 0;
}


