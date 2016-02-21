// Room: /d/4world/room2.c
inherit ROOM;

void create ()
{
  set ("short", "民宅");
  set ("long", @LONG

一间小小的民宅，打扫的干干净净。家俱不是很好，最显眼的就只
有一长桌，桌上摆着大茶壶。墙边堆着许多竹杆，地下还有些编的
半成的竹筐，看来家里人是靠编竹器谋生。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"east2",
]));
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/zhu2" : 1,
  __DIR__"npc/zhu1" : 1,
]));

  setup();
}
