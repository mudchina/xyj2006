//Cracked by Roath
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return notify_fail("你只能用无相心法保护自己。\n");
        if(me->query("family/family_name") != "方寸山三星洞" )
                return notify_fail("你是哪儿偷学来的武功啊?\n");
        if( (int)me->query("force") < 250 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("wuxiangforce",1);

        me->add("force", -250);
        me->receive_damage("kee", 10);

        message_vision(
                HIR
"$N双目一睁，运起无相心法，浑身上下顿时被一片金光罩住，就如身穿天兵金甲，站在那里看起来威风凛凛。\n" NOR, me);

        me->add_temp("apply/armor", skill/2);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
       me->add_temp("apply/armor", - amount/2);
        me->delete_temp("powerup");
        tell_object(me, "你的无相心法运行一周天完毕，金光渐渐消去了。\n");
}

