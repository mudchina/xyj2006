// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	message_vision(
"$N坐了下来运起九阴心经，呼吸吐纳，真气直透九重。脸上神色一会变"HIR"红"NOR"，\n"
"一会变"HIC"青"NOR"，一会又变成"HIY"黄"NOR"色，最后终于回复原来的脸色。\n" NOR, me );

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
	me->add("force", -50);
	me->set("force_factor", 0);

	return 1;
}

