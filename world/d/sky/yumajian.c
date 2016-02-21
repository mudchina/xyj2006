//dongmenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "御马监");
        set("long", @LONG

御马监监内不大，摆设也是平常。有监丞典簿二人两边侍立，以
备有天将来征用马匹。东有木门一扇，门后便是御马监中马场，
隐见力士来回催办，骏马攒蹄不息，很是热闹。
LONG
        );
 
        set("exits", ([
                "south" : __DIR__"dongmenting",
        ]));
 	set("no_fight",1);
	set("no_magic",1);
 
        set("objects", ([
                __DIR__"npc/jiancheng" : 1,
		__DIR__"npc/dianbu": 1,
        ]));
 
        setup();
}
