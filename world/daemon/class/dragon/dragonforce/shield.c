//jiz
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        if(me->query("family/family_name")!="东海龙宫")
                return notify_fail("非龙宫弟子不能用「龙神心法」！\n");
        if( target != me ) 
                return notify_fail("你只能用龙神心法保护自己。\n");

        if( (int)me->query("force") < 100 )     
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee") < 50 )
		return notify_fail("你的气血不足。\n");
	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神不足。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("force");

        me->add("force", -100);
        me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);

        message_vision(
                HIC"$N微一凝神，运起龙神心法，浑身上下顿时结出了青色的龙鳞。\n" NOR, me);

        me->add_temp("apply/armor", skill/3);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/armor", - amount);
        me->delete_temp("powerup");
        tell_object(me, "你的龙神心法运行一周天完毕，龙鳞渐渐消去了。\n");
	return;
}

