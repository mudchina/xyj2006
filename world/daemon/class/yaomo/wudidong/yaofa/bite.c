// bite.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 120;
	damage_adj = 120;


	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("闲的没事变什么老鼠？\n");

if(me->query("family/family_name")!="陷空山无底洞")
                         return notify_fail("无底洞弟子才可以用！\n");
	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("mana")) < 50 ) {
		write("你变的这么小,怎么咬人！\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "\n$N口中喃喃自语，化作一只白毛玉鼠，扑向$n！\n" NOR,
			//initial message
		HIR "\n结果$n被咬了个正着！\n" NOR, 
			//success message
		HIC "\n$n连忙一侧身闪在一旁。\n" NOR, 
			//fail message
                HIC "只见$n一声大喝，$N被吓得浑身瘫软！\n" NOR, 
			//backfire initial message
		HIC "$N感觉有些神思倦怠！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(1));
	return 3+random(2);
}

