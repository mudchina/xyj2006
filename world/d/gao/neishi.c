// neishi.c
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "内室");
  set ("long", @LONG

房间不大，却是石门石窗．窗上还有铁打的柱子．要是大门
不开，看来是没法出去的．
LONG);

set("exits", ([ /* sizeof() == 4 */
"west" : "/d/gao/room",
]));

 set("objects", ([ /* sizeof() == 2 */
"/d/gao/obj/xiaojie" : 1,

]));

	create_door("west", "石门", "east", DOOR_CLOSED);

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

