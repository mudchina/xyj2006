//Jiz
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
        string msg;
        int success, ap, dp, howlong;

        if( !target ) target = offensive_target(me);
        if(me->query("family/family_name")!="东海龙宫")
                return notify_fail("非龙宫弟子不能用这招！\n");
        if((int)me->query_skill("spells") < 100)
                return notify_fail("你还没学会雪舞风灵。\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你想把谁定住？\n");

        if(target->query_temp("no_move"))
                return notify_fail(target->query("name")+"已经动弹不得了！\n");

        if((int)me->query("mana") < 500 )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("你无法集中精力！\n");

        me->add("mana", -500);
        me->receive_damage("sen", 10);

        msg = HIC
"$N在手中划了个咒，望天一指，只见顿时天上雪舞风刮，
大大小小的雪片冰雹向$n飘了过去。\n\n"NOR;

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("daoxing");
        dp = target->query("daoxing");
        if( random(ap + dp) < dp ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 0;
//here we compared max_mana.

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
//here we compare current mana. this is important. you need recover to try again.

        howlong = 0;        
        if(success == 1 ){
                msg +=  HIR "结果$n手足被冻的僵硬，动弹不得。\n" NOR;
                target->set_temp("no_move", 1);

                howlong = 20 + random(15);
// so this one weaker, about 30 seconds.
//a typical level is 100+100 ->enabled 150, so will "ding" about 1 minute in the best case.
        }           
        else {
                msg +=  HIR "$n回手一挥，漫天飞雪顿时淡去了。\n" NOR;
        } 

        message_vision(msg, me, target);

//he'll try kill you...
        if( living(target) ) target->kill_ob(me);

if (success == 0) {
//me->start_busy(1);
return 1+random(2);
}

//      me->start_busy(5);        
        if( howlong>0 ) call_out("free", howlong, target);
        
        return 3+random(5);
}

void free(object target)
{
        if(target) target->delete_temp("no_move");      
        return;
}

