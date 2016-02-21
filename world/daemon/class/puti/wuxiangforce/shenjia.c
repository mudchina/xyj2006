//jiz
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        if(me->query("family/family_name") != "方寸山三星洞" )
                return notify_fail("你是哪儿偷学来的武功啊?\n");
        if( target != me ) 
                return notify_fail("你只能用小无相功保护自己。\n");

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
                HIR"$N微一凝神，运起小无相功,顿时身上像穿了神甲一般!\n" NOR, me);

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
        tell_object(me, "你的小无相功运行一周天完毕，神甲渐渐消去了。\n");
	return;
}

