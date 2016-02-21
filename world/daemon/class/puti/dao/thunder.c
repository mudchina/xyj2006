// thunder.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 120;
	damage_adj = 120;

        if(me->query("family/family_name")!="方寸山三星洞")
         {
            if(me->query("family/family_name")!="陷空山无底洞")
               return notify_fail("你不能用「五雷咒」！\n");
         }

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要对谁施展五雷咒？\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
		write("糟糕，雷公今天不当差！\n");
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
		"shen", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "\n$N口中念了句咒文，半空走出位尖头鹰鼻的雷公，左手执斧，右手提锥。斧锥相击，在$n的头顶炸起一片响雷！\n" NOR,
			//initial message
		HIR "\n结果$n被雷声震得眼冒金星，心神不定，差点跌倒在地！\n" NOR, 
			//success message
		HIC "\n谁知$n毫无反应，就象聋子似的。\n" NOR, 
			//fail message
		HIC "但是雷公被$n以法力一激，一个失神之下响雷都炸在了$N的头顶！\n" NOR, 
			//backfire initial message
		HIC "结果$n被雷声震得眼冒金星，心神不定，差点跌倒在地！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

