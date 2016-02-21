//restroom.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", "山坡后");
	set ("long", @LONG

大雪山轻功冠绝天下。各代师傅为了让弟子刻苦练习
轻功，将冰谷四周的门尽数关闭，弟子须凭非凡轻功
才可飞跃出谷，却不知哪个爱偷懒的徒弟在这拴了条
绳子(rope)，嘿嘿，看来有捷径了。
LONG);

	set("item_desc", (["rope" : 
"一条长长的绳子不知通向哪里，不妨爬爬(climb)试试。\n", 
                         ]));

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"shanpo",
		"north" : __DIR__"xuejie-3",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));


	set("outdoors", "xueshan");

	setup();

}


void init()
{
        add_action("do_climb", "climb");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
        me->move("/d/gao/bed_yashi");
            message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}

int do_climb(string arg)
{
   object me=this_player();
   if(!arg || arg != "rope") return notify_fail("爬什么？\n");

   message_vision(HIY "$N趁周围没人注意，顺着绳子爬了下去。\n\n" NOR, me);
   me->move(__DIR__"xueshan2");
   message_vision(HIY "\n只见$N不知从哪滑了下来。\n" NOR, me);

   return 1;

}

