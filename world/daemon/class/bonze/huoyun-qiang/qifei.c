// 枪杖齐飞

#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

void check_fight(object me, object target, object victim, int amount);
int remove_effect(object me, object target, int amount);

int perform(object me, object target)
{
	int skill, skill1, skill2;
	object weapon, victim = offensive_target(me);
        
	if (!victim) return notify_fail("你想对谁进行「枪杖齐飞」？\n");

	if( !target )
		return notify_fail("你想与谁进行「枪杖齐飞」？\n");
	if( target->query("id") == me->query("id") )
		return notify_fail("你想与自己进行「枪杖齐飞」？\n");
	if( victim->query("id") == target->query("id") )
		return notify_fail("不能与你的对手进行「枪杖齐飞」。\n");
	if( target->query("id") != me->query("bonze/dadangid") 
	 && target->query("id") != me->query("couple/id") )
		return notify_fail("你只能与搭档进行「枪杖齐飞」。\n");

	if( !victim->is_character() || !me->is_fighting(victim) )
		return notify_fail("只能对你正在战斗中的对手使用「枪杖齐飞」。\n");
	if( !target->is_fighting(victim) )
		return notify_fail("你的搭档不在与对手战斗中。\n");
	if( !objectp(weapon=target->query_temp("weapon")) ||
		(weapon->query("apply/skill_type") != "staff" &&
		weapon->query("skill_type") != "staff" ) || 
		target->query_skill_mapped("staff") !="lunhui-zhang" )
		return notify_fail("你的搭档没有在使用轮回杖。\n");
	if( (int)target->query_temp("qifei") )
		return notify_fail("你的搭档已经在使用「枪杖齐飞」了。\n");
	if( (int)me->query_temp("qifei") )
		return notify_fail("你已经在使用「枪杖齐飞」了。\n");
	if((int)me->query("force") < 25+(int)me->query("force_factor") )
		return notify_fail("你的内力不够！\n");
	if((int)me->query("kee") < 100 )
		return notify_fail("你的气血不足，没法子施用外功！\n");
	if((int)target->query("force") < 25+(int)me->query("force_factor") )
		return notify_fail("你的搭档内力不够！\n");
	if((int)target->query("kee") < 100 )
		return notify_fail("你的搭档气血不足，没法子施用外功！\n");

	if( !(int)target->query_temp("qifei_request") ) {
		me->set_temp("qifei_request", 1);
		tell_object(target, me->query("name")+"向你发出「枪杖齐飞」请求。\n");
		return 1;
	}
	target->delete_temp("qifei_request");

	me->add("force", -25-(int)me->query("force_factor"));
	target->add("force", -25-(int)me->query("force_factor"));
	me->receive_damage("kee", 100);
	target->receive_damage("kee", 100);

	skill1 = target->query_skill("lunhui-zhang", 1);
	skill2 = me->query_skill("huoyun-qiang", 1);
	skill = (skill1 + skill2)/2;
	message_vision(HIY
		"$N与$n手中兵器相互一击，周围幻起一片枪林杖雨，压得"
		+ victim->query("name") + "喘不过气来，进攻防守全都失去了章法。\n"
		NOR, me, target);
	me->add_temp("apply/attack", skill);
	me->add_temp("apply/dodge",  skill);
	me->set_temp("qifei", 1);
	target->add_temp("apply/attack", skill);
	target->add_temp("apply/dodge",  skill);
	target->set_temp("qifei", 1);

//	me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, victim, skill :), 1);
	call_out("check_fight", 1, me, target, victim, skill);

	return 1;
}

void check_fight(object me, object target, object victim, int amount)
{
	object weapon;

	if( !living(victim) || !present(victim->query("id"), environment(me)) ) 
		remove_effect(me, target, amount);

	else if(   !present(victim->query("id"), environment(me)) 
		|| !target->is_fighting(victim)
		|| !present(target->query("id"), environment(me)) 
		|| !me->is_fighting(victim) ) 
		remove_effect(me, target, amount);

	else if( !objectp(weapon=me->query_temp("weapon")) ||
		(weapon->query("apply/skill_type") != "spear" &&
		weapon->query("skill_type") != "spear" ) || 
		me->query_skill_mapped("spear") != "huoyun-qiang" )
		remove_effect(me, target, amount);

	else if( !objectp(weapon=target->query_temp("weapon")) ||
		(weapon->query("apply/skill_type") != "staff" &&
		weapon->query("skill_type") != "staff" ) || 
		target->query_skill_mapped("staff") != "lunhui-zhang" )
		remove_effect(me, target, amount);

	else call_out("check_fight", 1, me, target, victim, amount);
}

int remove_effect(object me, object target, int amount)
{
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/dodge", -amount);
	target->add_temp("apply/attack", -amount);
	target->add_temp("apply/dodge", -amount);
	me->delete_temp("qifei");
	target->delete_temp("qifei");
	message_vision(GRN"$N和$n的「枪杖齐飞」招式一收，那一团团的杀气顿时消失，周围的人也都松了一口气。\n"NOR, me, target);
	return 0;
}

