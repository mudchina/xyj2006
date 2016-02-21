// taohua.c
//tomcat修改  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count;
        int weapon_val = 0; 
      
        if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("「桃花飞舞」只能在战斗中使用。\n");

        if( me->query_skill("zixia-shengong",1) < 100)
            return notify_fail("你的紫霞神功等级不够, 不能使用「桃花飞舞」！\n");

        if( me->query_skill("mindsword",1) < 100)
            return notify_fail("你的桃花剑法等级不够, 不能使用「桃花飞舞」！\n");

        if( me->query("force") < 250 )
            return notify_fail("你的内力不够，无法运用「桃花飞舞」！\n");
	msg = HIY "$N使出桃花剑法绝技「桃花飞舞」，身法陡然加快。落英缤纷！" NOR;
	
         weapon = me->query_temp("weapon");
                 
	 COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR);
	 msg =  BLINK""+HIM"人面桃花！" NOR;
	 message_vision(msg,me,target);
	 COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR);
	 msg =  BLINK""+HIR"万花齐落！" NOR;
         message_vision(msg,me,target);
	 COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR);
	 msg =  BLINK""+HIC"漫天花雨！" NOR;
         message_vision(msg,me,target);
         COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR);
	 msg =  BLINK""+HIG"落花无意！" NOR;
	 message_vision(msg,me,target);
	 COMBAT_D->do_attack(me,target, weapon,TYPE_REGULAR);
	me->add("force", -50);
	me->start_busy(2);
	return 1;
}

