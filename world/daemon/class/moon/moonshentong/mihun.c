// mihun.c 迷魂术
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;

	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 100 || (int)me->query_skill("moonshentong",1) < 60)
		return notify_fail("你还没学会迷魂术。。。\n");
        if(me->query("family/family_name") != "月宫")
                return notify_fail("[迷魂术]是月宫不传之密！\n");
	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你想迷谁的魂？\n");  

	if(target->query_temp("no_move"))
	return notify_fail(target->query("name")+"已经魂不守舍，呆若木鸡了！\n");  

	if((int)me->query("mana") < 200 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -200);
	me->receive_damage("sen", 10);

	msg = HIC
"$N低头轻声念了句咒文，又抬起头来朝$n妩媚地一笑！\n" 
NOR;

	success = 1;
	ap = me->query_skill("spells");
	ap = ap * ap * ap /12 ;
	ap += (int)me->query("daoxing");
	dp = target->query("daoxing");
//	if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

	ap2 = (int)me->query_per();
	dp2 = (int)target->query_per();
//	if( random(4*ap) < ((int)target->query_cps()+dp)) success = 0;
//here we compare per and guy's ding li.


	ap3 = (int)me->query("mana");
	dp3 = (int)target->query("mana");
	if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;

//here we compare current mana. this is important. you need recover to try again.

	if(success == 1 ){
		msg +=  HIR "$n神不守舍地看着$N，怜香惜玉之心由然而起，竟然忘了自己在战斗之中。\n" NOR;
		target->set_temp("no_move", 1);
	
		howlong = random((me->query_skill("spells") -100))+1;
		if(howlong>60) howlong=60;
		call_out("free", howlong, target);
	}	    
	else {
		msg +=  HIR "$n鄙夷地看了$N一眼，毫不为所动！\n" NOR;	
		me->start_busy(1+random(2));        
        	if( living(target) ) target->kill_ob(me);
	} 

	message_vision(msg, me, target);

	return 1;
}

void free(object target)
{
	if (target)
	target->delete_temp("no_move");      
	return;
}

