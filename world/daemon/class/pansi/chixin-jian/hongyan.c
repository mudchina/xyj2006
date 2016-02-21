// jie 2001-2-3
// chixin-jian 红颜白发

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,lvl;
	int i;
	object weapon,ob;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("红颜白发只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("红颜白发只能和痴心情长剑法配和！\n");
	if(me->query("family/family_name")!="盘丝洞")
return notify_fail("“红颜白发”只有盘丝洞门人才可以用！\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("红颜白发只能和痴心情长剑法配和！\n");
	if ( (string) me->query_skill_mapped("sword") != "chixin-jian")
	return notify_fail("红颜白发只能和痴心情长剑法配和！\n");
	if (me->query_skill_mapped("force")!="jiuyin-xinjing")
                return notify_fail("只有用九阴心经才能运用红颜白发。\n");
        if((int)me->query("force") < 100 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
	extra = me->query_skill("chixin-jian",1) / 15;
	extra += me->query_skill("yueying-wubu",1) / 15;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	me->receive_damage("kee", 100);
	msg = HIM  "$N脚踏［月影舞步］，曼歌轻舞，使出［痴心情长剑法］的精髓－－
	\n"HIR"             『红颜"HIW"白发』
	\n"MAG"－－只见$N长发飘飘，裙裾袂袂，清丽哀怨不可方物！\n\n使到动情尽意处，索性抛了手中的"+ weapon->name() +MAG"，双指轮弹，无边气韵氤氲般卷向$n！\n\n" NOR;
	message_vision(msg, me, target);
	msg =  HIW ""+ weapon->name() +HIW"犹如长虹浸空，仿佛消失．．．．\n\n" NOR;
        message_vision(msg, me, target);
        me->clean_up_enemy();
        ob = me->select_opponent();
		lvl=extra;
    if(lvl>5) lvl =5;
	for(i=0;i<lvl;i++)
	{
	msg = HIY "$N吟哦长啸“问世间－－－－
				      情为何物？”，频思遗恨喷薄而发！\n" NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(1+random(2));
	return 1;
}

