// Room: some place in 西牛贺洲
// gate.c
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "山门");
  set ("long", @LONG

门口立一石碑，约有三丈馀高，八尺馀阔，上有一行十个大字，
乃是“灵台方寸山，斜月三星洞”。山门旁立一仙童，真个丰姿
英伟，像貌清奇，比寻常俗子不同。
LONG);
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"gate1",
"southdown": __DIR__"uphill6",
]));

set("objects", ([
                __DIR__"npc/yingke": 1 ]) );
        create_door("north", "石门", "south", DOOR_CLOSED);
         set("outdoors", 1);
        set("no_clean_up", 0);

        setup();
        "obj/board/shibei_b"->foo();
}


