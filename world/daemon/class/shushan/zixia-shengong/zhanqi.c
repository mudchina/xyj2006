//zhanqi by yushu 2001.2
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        skill = me->query_skill("zixia-shengong",1);
	 if( skill > 250 ) { skill=250;}
        if( target != me ) 
		return notify_fail("你只能对自己使用。\n");

 if(me->query("family/family_name")!="蜀山派")
return notify_fail("你不是蜀山弟子，不能使用这项技能！\n");
        if( (int)me->query("force") < skill*2 )     
		return notify_fail("你的内力不够。\n");

        if( (int)me->query_temp("zhanqi") ) 
		return notify_fail("你已经在运功中了。\n");

        me->add("force", -skill);
        me->receive_damage("kee", 50);

        message_vision(
HIM "$N微一凝神，运起紫霞神功，一股天罡战气从丹天直冲天顶。\n" NOR, me);

        me->add_temp("apply/attack", skill/5);
	 me->add_temp("apply/strength", skill/5);
        me->set_temp("zhanqi", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
    if(!me) return;
    me->add_temp("apply/attack", - amount);
    me->add_temp("apply/strength", - amount);
    me->delete_temp("zhanqi");
    tell_object(me, HIM"你的天罡战气循环一周天完毕，将内力收回丹田。\n"NOR);
}

