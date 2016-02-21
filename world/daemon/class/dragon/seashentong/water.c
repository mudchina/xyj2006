// Jiz
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 110;
        damage_adj = 160;

	if( !target ) target = offensive_target(me);
        if(me->query("family/family_name")!="东海龙宫")
                return notify_fail("非龙宫弟子不能用这招！\n");
	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要引龙神袭击谁？\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
		message_vision(HIM"$N口中念念有词。。。但什么也没有发生！\n"NOR,me);
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
		"qi", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
HIM"\n$N后退几步，口中念了几句咒文，大叫一声：“神龙何在？“
半空中呼地现出两条气势威猛的银角背苍龙，纵身一吐，两股奇寒无比的水柱喷向$n\n"NOR,
			//initial message
HIR"\n结果$n躲避不及，被水柱激个正着！\n"NOR,
			//success message
HIC"\n结果被$n躲开了。\n"NOR,
			//fail message
HIR"但水势被$n以法力反激，反向$N射去！\n" NOR,
			//backfire initial message
HIR"\n结果$n躲避不及，被水柱激个正着！\n"NOR,
			//backfire hit message. note here $N and $n!!!
	);

        me->start_busy(1+random(2));
	return 3+random(5);
}

