// Room: some place in 西牛贺洲
// gate1.c

inherit ROOM;
#include <room.h>
void create()
{
  set ("short", "小院");
  set ("long", @LONG

小院正中放了一口极大的香炉，象是黄铜打造，上面雕的是龙凤
呈祥。炉上的小口发出一股青烟，院中香气缭绕。左右是厢房，
向前走就到了正院。
LONG);
set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"inside1",
"south": __DIR__"gate",
"east": __DIR__"inside2",
"west": __DIR__"inside3",
]));
create_door("south", "石门", "north", DOOR_CLOSED);
set("outdoors", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


