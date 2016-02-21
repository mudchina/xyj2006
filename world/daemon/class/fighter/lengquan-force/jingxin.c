#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
        if(me->query("family/family_name")!="将军府")
                return notify_fail("你不是将军府弟子，不能使用这项技能！\n");
        if( target != me ) 
                return
notify_fail("你只能用静心诀提高自己的警觉。\n");

        if( (int)me->query("force") < 200 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("lengquan-force",1);

        me->add("bellicosity", -skill/2);
	if((int)me->query("bellicosity") <= 0){
		me->set("bellicosity", 1);
	}
        me->add("force", -100);

        message_vision(
                HIR
"$N微一凝神，运起静心诀，登时心平气稳，于周围一切警觉有加。\n"NOR, me);

        me->add_temp("apply/dodge", skill/5);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,
skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", -amount);
        me->delete_temp("powerup");
        tell_object(me,
"你的静心诀运行一周天完毕，将内力收回丹田。\n");
}

