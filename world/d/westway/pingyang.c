// create by snowcat.c 4/8/1997
// room: /d/westway/pingyang.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","平阳道");
  set ("long", @LONG

蜿蜒的平阳道细细长长，通进山里。这里安安静静，抬头向西
看去，大道的一端在山谷里消失。向东北看去，一队马车正急
急地向永靖方向赶去。大道边有一棵巨大的枯树(tree)。

LONG);

  set("item_desc",([
    "tree" : "树上刻着："+
    "近闻峪中有马盗出没杀人越货务请结队而行切记。\n",
  ]));

  set("exits", ([
        "northeast" : __DIR__"yongjing",
        "west"      : __DIR__"yinma",
      ]));
  set("outdoors", __DIR__);

  setup();
}





