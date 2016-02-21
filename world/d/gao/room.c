// room.c
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "聚义厅");
  set ("long", @LONG

这里便是清风寨的大堂－－－聚义厅。厅中一十六张虎皮软椅分
列两旁，正面一张香台，供着关公大帝。山寨里的头领要开会的
话，多半会选在这里举行。另外也是分赃宴会的地方。
LONG);


set("exits", ([ /* sizeof() == 4 */
"southdown" : "/d/gao/shanlu",
"east" : "/d/gao/neishi",
]));

 set("objects", ([ /* sizeof() == 2 */
"/d/gao/npc/head" : 1,

]));
create_door("east", "石门", "west", DOOR_CLOSED);
        set("no_clean_up", 0);
        setup();
}



int valid_leave(object me, string dir)
{
    if ( dir == "east" ) {
        if(objectp(present("xia pengzhan", environment(me))))
            return
notify_fail("夏鹏展一个箭步闪到你前面，狞笑道：\n清风寨可是你想来便来，想走便溜的的地方！\n");
    }
    return ::valid_leave(me, dir);
}




