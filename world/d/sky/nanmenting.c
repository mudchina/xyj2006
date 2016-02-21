#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "南门厅");
  set ("long", @LONG

进了南天门，已经可以看到一座座天宫放着七彩霞光，忽隐忽现
于云遮雾绕之中。一座白玉桥弯弯曲曲地向北延伸，东西两边各
有一座大殿，也不知是干什么用的，你可以隐约听到东边殿中有
喧哗之声，似乎人不少。两个小男孩正在扫地。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"nantian.c",
  "east" : __DIR__"28xiu-dian.c",
]));

create_door("south", "南天门", "north", DOOR_CLOSED);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tong-nan" : 2,
]));

  setup();
}
