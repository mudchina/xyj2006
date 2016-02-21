// wuzhishan.c,五指山
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 150;
	damage_adj = 140;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要用五指山震谁？\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 20 )
		return notify_fail("你无法集中精力，别砸中自己了！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("好象没反应，再来一次吧！\n");
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
		HIC "$N口中念了几句咒文，半空中出现一座五指山，呼！地一声向$n当头砸下！\n" NOR,
			//initial message
		HIC "结果砸个正着，差点没把$n压扁！\n" NOR, 
			//success message
		HIC "但是$n在千钧一发之际跳了开来。\n" NOR, 
			//fail message
		HIC "但是五指山被$n以法力一引，反而砸到了$N的顶门！\n" NOR, 
			//backfire initial message
		HIC "结果砸个正着，差点没把$n压扁！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}


