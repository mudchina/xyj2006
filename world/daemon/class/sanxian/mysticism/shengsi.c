// shengsi参生死   ziwuliuzhu子午流注
// /daemon/class/sanxian/mysticism/shengsi.c
// writted by mind 2001/2

#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        if (me->query("family/family_name")!="三界散仙")
                return notify_fail("你不是三界散仙，不会「参生死」！\n");
        if (!target)target=offensive_target(me);
        if (!target||!target->is_character() || !me->is_fighting(target))
                return notify_fail("「参生死」只能对战斗中的对手使用。\n");
        if ((int)me->query_skill("mysticism",1) <80)
                return notify_fail("你[玄玄神机]功夫还不到家，不会「参生死」。\n");
        if(target->query_temp("mark/ziwuliuzhu") == 1)
        return notify_fail(target->query("name")+"已经中了子午流注！\n");  
        if ((int)me->query("mana")<200)
                return notify_fail("你的法力不够。\n"); 
        if((int)me->query("sen") < 100 )
                return notify_fail("你无法集中精力！\n");
        if (me->query("betrayer") || me->query("betray/count"))
           return notify_fail("三心二意者很难领悟散仙的精髓所在。\n");
        
        me->add("mana", -200);
        me->receive_damage("sen", 100);
        message_vision(HIW"$N掐指一算，对着$n长叹一声：“汝命不久矣！”\n" NOR,me,target);
        
                     
        if (random(me->query("daoxing"))>(int)target->query("daoxing")/3*2 ) {                                   
                target->start_busy(1);                    
                me->start_busy(1+random(2));  
                message_vision(HIC"$n被$N一参生死，元神顿泄！\n"NOR,me,target);             
                target->apply_condition("ziwuliuzhu_poison",1+random(20));
                target->set_temp("mark/ziwuliuzhu", 1);
                tell_object(target,HIB"猛地里你感觉什么神奇的东西在内元一转，似乎多了什么，又似乎少了什么。\n"NOR); 
                if( living(target) ) target->kill_ob(me);
        } else {        
                message_vision(HIC"但是$n抱元守固，护住心神，但也被吓出一身冷汗。\n"NOR,me,target);
                me->start_busy(3);
        }
        return 1;
}


