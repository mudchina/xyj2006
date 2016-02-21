//by greenwc 2000.11
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

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
 HIR "$N定睛闭目，运起蜀山心法充分燃烧起自己的小宇宙，以提高自己的防御力。。。\n" NOR, me);

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
tell_object(me, "你的小宇宙已经燃烧尽了，还是赶快收功吧。\n");
        return;
}

