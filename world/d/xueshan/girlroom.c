//standroom.c used by weiqi...others may hate this format:D
//girlroom.c

#include <ansi.h>

inherit ROOM;

void create ()
{
	set ("short", "女弟子卧房");
	set ("long", @LONG

雪山派的女弟子卧房。陈设相当素净。靠墙摆着几张床铺(bed)。
LONG);

	set("item_desc", (["bed" : "一张精致的床铺(gosleep, gobed, bed)。\n", ]));
	//for look something.

	set("exits", 
	([ //sizeof() == 4
		//"south" : __DIR__"binggu",
		"north" : __DIR__"restroom",
		//"west" : __DIR__"restroom",
		//"east" : __DIR__"chufang",
		//"up" : __DIR__"***",
		//"down" : __DIR__"***",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/xunshi" : 2,
		__DIR__"npc/huanhua" : 1,
	]));


	//set("outdoors", "xueshan");

	setup();
}

void init()
{
	add_action("do_bed", "gosleep");
	add_action("do_bed", "gobed", );
	add_action("do_bed", "bed");
}

int do_bed()
{       
	object me;
	me=this_player();

	message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
	me->move(__DIR__"girlbed");
	message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
	return 1;
}

