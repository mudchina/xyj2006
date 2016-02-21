// heal.c

#include <ansi.h>

int cast(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");
	if(me->query("family/family_name")!="南海普陀山")
                return notify_fail("不是佛门弟子,不懂这佛门奥义！\n");

	if( (int)me->query("mana") < 50 )
		return notify_fail("你的法气不够。\n");

	if( (int)me->query("eff_sen") < (int)me->query("max_sen") / 2 )
		return notify_fail("你精神实在不济，只怕一运法力便有生命危险！\n");

	write( HIW "你全身放松，盘腿而座，开始神游物外。\n" NOR);
	message("vision",
		HIW + me->name() + "盘腿而座，开始神游物外。不久吐出一口浊气，精神看起来好多了。\n"NOR,
		environment(me), me);

	me->receive_curing("sen", 10 + (int)me->query_skill("spells")/5 );
	me->add("mana", -50);
	me->set("mana_factor", 0);

	return 1;
}
