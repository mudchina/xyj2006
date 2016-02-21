// Room: /city/erlou.c

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG

紫云公主的一间睡房，房间干干净净。
LONG
        );

        set("sleep_room",1);
        set("if_bed",1);
        set("exits", ([
                "south" : "/d/sea/girl2",
        ]));
//      
        set("water", 1);
//  
        setup();
}

