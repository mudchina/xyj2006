// Jiz
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

        success_adj = 180;
        damage_adj = 170;

	if( !target ) target = offensive_target(me);

        if(me->query("family/family_name")!="火云洞")
return notify_fail("“三味真火”只有火云洞门人才可以用！\n");
        if( !target
        ||   !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
                return notify_fail("你要对谁喷三味真火？\n");

        if((int)me->query_skill("pingtian-dafa", 1) < 30 )
                return notify_fail("你的平天大法火候不够，哪里喷得出真火！\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够，喷出的真火恐怕没有什么用！\n");

        if((int)me->query("force") < 100 )
                return notify_fail("你的内力不够，无法将真火喷出。\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("你现在神智不清，别把自己烧伤了！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
		message_vision(HIM"$N口中念念有词。。。但什么也没有发生！\n"NOR,me);
		return 1;
	}
	
	me->receive_wound("kee", 10);

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
HIC "$N伸手在鼻子上砸了两，顿时鲜血直冒，突然红橙黄三道火焰呼！地一声向$n卷去！\n" NOR,
			//initial message
HIC "结果$n被烧得焦头烂额！\n" NOR,
			//success message
HIC"\n结果被$n躲开了。\n"NOR,
			//fail message
HIC "结果火焰被$n以法力一逼，反向$N回卷而去！\n" NOR,
			//backfire initial message
HIR"\n结果$n躲避不及，被烧得焦头烂额！\n" NOR,
			//backfire hit message. note here $N and $n!!!
	);

        me->start_busy(1+random(2));
	return 3+random(5);
}

