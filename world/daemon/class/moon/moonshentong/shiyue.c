// 蚀月咒?
inherit SSERVER;
#include <ansi.h>

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;
	int dayphase;

	dayphase =NATURE_D->query_current_day_phase();

	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 120
	 || (int)me->query_skill("moonshentong",1) < 80)
		return notify_fail("你还没学会蚀月咒。。。\n");
        if(me->query("family/family_name") != "月宫")
                return notify_fail("[蚀月咒]是月宫不传之密！\n");
	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你想对谁施展蚀月咒？\n");  

	if(target->query("mark/moon_poison") == 1)
	return notify_fail(target->query("name")+"已经中邪了！\n");  

	if((int)me->query("mana") < 300 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你无法集中精力！\n");
	//write(dayphase+"\n");
	if (dayphase < 6)
		 return notify_fail("蚀月咒只有夜晚才能施展！\n");

	me->add("mana", -300);
	me->receive_damage("sen", 10);

	msg = HIC
"$N低头默默念起咒文，手中渐渐聚起一团光球，雪白的脸庞似乎发射出柔和的光芒。\n" 
NOR;

	success = 1;
	ap = me->query_skill("spells");
	ap = ap * ap * ap /10 ;
	ap += (int)me->query("daoxing")/2;
	dp = target->query("daoxing")/2;
//	if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

	ap2 = (int)me->query_spi();
	dp2 = (int)target->query_spi();

	ap3 = (int)me->query("mana");
	dp3 = (int)target->query("mana");
//	if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;
	if( random((ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3))/1000+1) < (dp+2500*dp2+200*dp3)/1000 ) success = 0;

//here we compare current mana. this is important. you need recover to try again.

	if(success == 1 ){
		msg +=  HIR "$n见到$N祥宁之态，娇美不可方物，心中一荡，却不防那光球一闪，突然射向$n。\n" NOR;
		target->set("mark/moon_ice", 1);
		target->apply_condition("moon_poison", ((int)me->query_skill("moonshentong",1)/5));
		me->start_busy(1+random(2)); 
        	if( living(target) ) target->kill_ob(me);

	}	    
	else {
		msg +=  HIR "$N脸色苍白，似乎体力不支，光球在手中渐渐褪去。！\n" NOR;	
		if((int)me->query("mana") > 300 )
			me->add("mana", -300);
		me->apply_condition("moon_poison", ((int)me->query_skill("moonshentong")/10));
	} 

	message_vision(msg, me, target);
	return 1;
}

