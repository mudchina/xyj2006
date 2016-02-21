//sgzl

#include <room.h>
inherit ROOM;

void create()
{

	set("short", "水帘洞内");
	set("long", @LONG
这里便是花果山水帘洞的内堂，四周锅碗瓢盆样样
俱全。正中一张虎皮椅子，正是供水帘洞主休息的。
LONG );


	set("exits", ([
	    "west"   : __DIR__"shifang",
	]));


	set("objects", ([
	    __DIR__"npc/mowang" : 1,
	]));



	setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed" );
        add_action("do_bed", "bed");
}


int do_bed()
{       object me;
        me=this_player();
        message_vision("$N往石床上一躺，准备睡觉了。\n\n", me);
        me->move(__DIR__"shichuang");
            message_vision("\n$N从石床上站了起来。\n", me);
                return 1;
}


int valid_leave(object me, string dir)
{
 
        if (dir == "west") 
        {
                {
                        if(present("hunshi mowang", environment(me) ))
                                return notify_fail("混世魔王冲着你冷笑到：“想走？没那么容易吧！”\n");
                }



                return ::valid_leave(me,dir);
        }
        return ::valid_leave(me,dir);
}

