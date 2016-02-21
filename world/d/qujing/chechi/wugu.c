// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/wugu.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "五谷轮回");
  set ("long", @LONG

屋子里光线阴暗，墙壁潮湿，里面似乎什么也看不清。门口有
几大柱粗香冒着浓烟，边上有一小凳，上面放有一叠一叠的粗
糙草纸。

LONG);

  set("item_desc", ([
        "west" : (: look_door, "west" :),
      ]));

  set("exits", ([
        "west"         : __DIR__"dianmen",
      ]));

  create_door("west", "小门", "east", DOOR_CLOSED);
  setup();
}

