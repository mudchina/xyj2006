//created by vikee
//2000.10
//qingwang.c 
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
	object weapon;
	string msg;
	int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong,req;

	if( !target ) target = offensive_target(me);
	if (!weapon = me->query_temp("weapon"))
		return notify_fail("你没拿鞭子，拿什么织网啊？\n");
	 
      req=(int)me->query_skill("whip", 1)+(int)me->query_skill("juqingbian", 1)+(int)me->query_skill("moonforce", 1); 
	if((int)me->query_skill("spells") < 100 || (int)me->query_skill("jueqingbian",1) < 100)
		return notify_fail("你的功夫等级还不够，使不出情网！\n");

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你想对谁使情网？\n");  

	if(target->query_temp("in_qingwang"))
	return notify_fail(target->query("name")+"已经被你的情网所困了！\n");  

	if((int)me->query("mana") < 200 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -200);
	me->receive_damage("sen", 10);

	msg = HIB"$N催动法力，将手中"+weapon->query("name")+HIB"舞成一团，化做一张大网，向$n当头罩来。\n" 
NOR;

	success = 1;
	ap = (me->query_skill("spells")+me->query_skill("jueqingbian")) /2 ;
	ap = ap * ap * ap /12 ;
	ap += (int)me->query("daoxing");
	dp =target->query_skill("spells");
	dp =dp * dp * dp /12;
	dp += (int)target->query("daoxing");
	if( ap < dp ) success = 0;
		if(success == 1 ){
		msg +=  HIB "$n脑子里一片混乱，鬼使神差般突然发呆，甚至忘记了躲闪，被情网当头罩住。\n" NOR;
		target->set_temp("in_qingwang", 1);
        howlong = random((me->query_skill("spells") -100))+1;
		if(howlong>60) howlong=60;
		call_out("free", howlong, target);
	}	    
	else {
		msg +=  HIG "$n神智清醒，不为情所困，轻轻向旁一跃，躲过了情网的袭击。\n" NOR;	
		
        	if( living(target) ) target->kill_ob(me);
			me->start_busy(2);
		} 

	message_vision(msg, me, target);

	return 1;
}

void free(object target)
{
	if (target)
	target->delete_temp("in_qingwang");      
	return;
}


