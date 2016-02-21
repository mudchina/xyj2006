// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;

        if( target != me ) 
                return
notify_fail("你只能用显形诀保护自己。\n");

        if( (int)me->query("force") < 200 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        skill = me->query_skill("tonsillit",1);

       // me->add("bellicosity", -skill/2);
   if((int)me->query("bellicosity") <= 0){
     me->set("bellicosity", 1);
   }
        me->add("force", -100);

        message_vision(
                HIR
"$N将白骨措成一堆磷粉,向四周撒了开去,顿时显现出一些足迹!!\n"NOR, me);

        me->add_temp("apply/dodge", skill/5);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,
skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", -amount);
        me->delete_temp("powerup");
        tell_object(me,
"你的显形诀运行一周天完毕，将内力收回丹田。\n");
}

