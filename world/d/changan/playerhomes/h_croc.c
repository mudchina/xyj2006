// /d/changan/playerhomes/stdhome.c
// this room is a standard home for married couples.
// wiz should modify /d/changan/phomes.c to set a exit
// and copy this room for them then let the players tell you 
// the descriptions of the room.  

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "鳄鱼和黑瘦妹的家");
        set("long", @LONG

一切都设置好了，只等一些室内装修。墙上(wall)还挂着几张字画．
LONG
        );
set("item_desc",(["wall": 
"伶俐鬼到此一游．．．．．．\n"]));
            set("valid_startroom",1);
        
        set("exits", ([
                "out": "/d/changan/phomes",
            ]));

	set("objects", ([
	__DIR__"npc/babyslimia":1,
	__DIR__"npc/babycroc":1,
	]));
        
        setup();
}

void init()
{
        object me = this_player();
        string id;

        id=(me->parse_command_id_list())[0];

        if (!(id=="croc" || id=="slimia" || (id=="baby" ))) {
                tell_object(me, "啊哈！ 闯进来了！\n");
                tell_object(me, "鳄鱼飞起一脚，正好踢中你的屁股 。
\n");
                tell_object(me, "黑瘦妹飞起一脚，正好踢中你的屁股 。
\n");
                me->move("/d/changan/phomes");
                message_vision("$N似乎被人一脚踢了出来，神色有点狼狈。\n",
me);
        }
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed" );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
        me->move("/d/changan/playerhomes/bed_croc");
            message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}

