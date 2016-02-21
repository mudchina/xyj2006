//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIG"后殿"NOR);
        set("long", @LONG
        这里是后殿，和南面的大殿连成一体，北面是祭祀厅，化妖炉就在里面。
西面是休息室，东北面有一条小路通往后山禁地。
LONG
        );

        set("exits", ([
                "north" : __DIR__"jisiting",
                "south" : __DIR__"dadian",
                "west" : __DIR__"restroom",
                "northeast" : __DIR__"houshan",
        ]));
        set("objects", ([
                __DIR__"npc/zuidao" : 1,
                __DIR__"npc/qingfeng" : 1,
        ]));
        setup();
        //replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

   if (dir == "north" ) {
        if (me->query("family/family_name") != "蜀山剑派")
        return notify_fail("蜀山祭祀的地方，不是你去的地方。\n");
        }   
        return ::valid_leave(me, dir);
}
