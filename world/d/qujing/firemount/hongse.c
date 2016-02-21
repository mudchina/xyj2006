// rewritten by snowcat on 4/11/1997
// room: hongse

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "红色庄院");
  set ("long", @LONG

你一定睛，发现这里一片红色：红瓦盖的房舍，红砖砌的垣墙，红
油门扇，红漆板榻，都是红的。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/oldman" : 1,
]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luzhou2",
]));

  setup();
}
