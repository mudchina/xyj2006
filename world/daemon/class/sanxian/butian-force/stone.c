// stone.c 匿石神通
// written by mind 2001/2
// /daemon/class/sanxian/butian-force/stone.c
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        if (!present("butian stone", me))
                return notify_fail("没有女娲补天石怎么施展匿石神通？\n");
        if( (string)me->query("family/family_name")!="三界散仙")
                return notify_fail("你非散仙，怎么施展匿石神通？\n");
        if( target != me ) 
                return notify_fail("你只能用匿石神通保护自己。\n");

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
                HIW"$N摩挲五彩补天石，运起匿石神通，浑身上下顿时散发出璀璨耀眼的光芒。\n" NOR, me);

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
        tell_object(me, "你收起五彩补天石，全身的流光溢彩渐渐消去了。\n");
        return;
}


