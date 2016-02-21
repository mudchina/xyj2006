// rewritten by snowcat on 4/11/1997
// room: xiaodian

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "小店");
  set ("long", @LONG

这是绿洲上的一家小店，卖的物品和大唐东土不大一样。店主是一少
年男子，常推着小车四处叫卖。

LONG);

  set("exits", ([
        "south" : __DIR__"luzhou2",
      ]));
  set("objects", ([
        __DIR__"npc/vendor" : 1,
      ]));

  set("valid_startroom", 1);
  setup();
}
