
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "翠屏峡");
  set ("long", @LONG

峡有百长余长，两边石壁(wall)高耸。壁上苔痕斑驳，岭上生有藤
萝，攀缘而下，在石壁上组成不少奇怪的图案，似有玄机。
LONG);
  set("item_desc", ([ /* sizeof() == 1 */
  "wall" : "图案似乎是几个人在比武。\n",
]));


  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"feifeng",
  "southdown" : __DIR__"jixian",
]));

  setup();
}

void init()
{
        add_action("do_study", "read");
}

int do_study(string arg)
{	
	object me=this_player();
	int sen_cost, kee_cost, force_cost, gain;

	if( !arg || (arg != "wall"))
		return notify_fail("你要学什么？\n");
	if( me->is_busy() )
		return notify_fail("你忙的很，哪有功夫去看石壁！\n");
	if( me->is_fighting() )
		return notify_fail("现学现卖已来不及了！\n");
	if( (int)me->query_skill("literate", 1) < 100)
		return notify_fail("你看了半天也看不懂上面画的是什么！\n");
	if( (int)me->query_skill("unarmed", 1) < 100)
		return notify_fail("你看了半天好象看出了点门道，却一时领悟不了。\n");
	if( (int)me->query_skill("unarmed", 1) >= 140)
		return notify_fail("你定睛看了会，你已经全部领悟到了。\n");
	if( (int)me->query("max_force") < 1000)
		return notify_fail("你底气不足，练不了。\n");

	sen_cost = 80 - (int)me->query_int();
	if( (int)me->query("sen") < sen_cost )
		return notify_fail("你现在头晕脑胀，该休息休息了。\n");

	kee_cost = 80 - (int)me->query_con();
	if( (int)me->query("kee") < kee_cost )
		return notify_fail("你现在浑身无力，该休息休息了。\n");

	force_cost = 20;
	if( (int)me->query("force") < force_cost )
		return notify_fail("你现在已提不起气了，该休息休息了。\n");

	me->receive_damage("sen", sen_cost);
	me->receive_damage("kee", kee_cost);
	me->add("force", - force_cost);

	gain = (int)me->query("int")/2 + (int)me->query("con")/2 + 1 + random(10);

	me->improve_skill("unarmed", gain);

	write("你照着石壁上的图案比划，对『扑击格斗之技』又有所了解。\n");

	tell_room( environment(me), me->name() + "双手挥来挥去，不知在比划什么。\n", ({me}));

	return 1;
}
