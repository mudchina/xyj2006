// Room: /d/death/walk.c
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIR"鬼门关"NOR);
  set ("long", @LONG

隐约北方现出一座黑色城楼，城楼上有一幅金匾，上面刻着“幽冥
界”三个大字。城楼下城门紧闭，黑漆漆地什么也看不清楚。路边
一个破木牌直直地指向北方，周围只有少许暗红色的火光若隐若现
地闪烁着。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"new-out5",
  "west" : __DIR__"new-out7",
  "south": __DIR__"gate",
]));
  set("hell", 1);

  setup();
}

void init()
{
        object me=this_player();
		remove_call_out("greeting");
                call_out("greeting", 60, me);
	add_action("do_pass", "north");


}
void greeting(object ob)
{
        if( !ob || environment(ob) != this_object() ) return;
	ob->set_temp("time_enough", 1);
	return;
}
int do_pass()
{
	object me=this_player();
	
	if( me->is_ghost() && !me->query_temp("time_enough") )
		return notify_fail("城楼上隐约传来喊声：阳气太盛，不得入城！\n");

	if( me->is_ghost() ) {
		me->reincarnate();
		me->set("gin", (int)me->query("max_gin"));
		me->delete_temp("time_enough");
	}

	tell_object(me, "你直直地向北对着城门走去，居然发现黑色的城门只是道气帘。。。\n");
	tell_room(environment(me), me->name()+"直直地向北对着城门走去，居然从紧闭的门中穿了过去！\n",
({me, me}));
	me->move("/d/death/new-zhaopo");
	tell_room(environment(me), me->name()+"走了过来。\n", ({me, me}));
	return 1;
}
