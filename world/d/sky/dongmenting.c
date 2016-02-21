//dongmenting.c
//created 4-8-97 pickle
#include <room.h>
inherit ROOM;
 
void create()
{
        set("short", "东门厅");
        set("long", @LONG

进了东天门，已经可以看到一座座天宫放着七彩霞光，忽隐忽现
于云遮雾绕之中。一座白玉桥弯弯曲曲地向北延伸，东西两边各
有一座大殿，也不知是干什么用的，你可以隐约听到东边殿内嘶
嘶马鸣。
LONG
        );
 
        set("exits", ([
                "east" : __DIR__"dongtian",
		"north":__DIR__"yumajian",
        ]));
 
        create_door("east", "东天门", "west", DOOR_CLOSED);
 
        set("objects", ([
                __DIR__"npc/tong-nan" : 2,
        ]));
 
        setup();
}
