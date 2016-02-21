//zhenhuo.c 【太乙真火】weiqi...980305

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 100;
	damage_adj = 100;

	if( !target ) target = offensive_target(me);

	if( !target
	||   !target->is_character()
	||   target->is_corpse()
	||   target==me)
		return notify_fail("你要对谁喷太乙真火？\n");
         if(me->query("family/family_name") != "五庄观")
                return notify_fail("[太乙真火]是五庄观不传之密！\n");

	if((int)me->query_skill("taiyi", 1) < 50 )
		return notify_fail("你的太乙仙法火候不够，哪里喷得出真火！\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够，喷出的真火恐怕没有什么用！\n");

	if((int)me->query("force") < 100 )
		return notify_fail("你的内力不够，无法将真火喷出。\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你现在神智不清，别把自己烧伤了！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->add("force", -100);
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) 
	{
		write("这一次好像不灵。\n");
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
		HIC "$N几个指头迅速捻动，突然张嘴一喷！红橙黄三道火焰呼！地一声向$n卷去！\n" NOR,
			//initial message
		HIC "结果$n被烧得焦头烂额！\n" NOR, 
			//success message
		HIC "但是$n轻轻一跳就躲了开来。\n" NOR, 
			//fail message
		HIC "但是火焰被$n以法力一逼，反向$N回卷而去！\n" NOR, 
			//backfire initial message
		HIC "结果太乙真火反噬，$n被烧得焦头烂额！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

