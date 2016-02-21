// gold.c,金砖
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 160;
        damage_adj = 150;
//        if(!me->query("m_success/金砖"))
//                return notify_fail("你又不会这法术。。。。\n");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要用金砖砸谁？\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 20 )
                return notify_fail("你无法集中精力，别砸中自己了！\n");

        if (me->query("betrayer") || me->query("betray/count"))
           return notify_fail("三心二意者很难领悟散仙的精髓所在。\n");
        
        
        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("好象没反应，再来一次吧！\n");
                return 1;
        }

        SPELL_D->attacking_cast(
                me, 
                        //attacker 
                target, 
                        //target
                success_adj,    
                        //success adjustment
                damage_adj,     
                        //damage adjustment
                "both",                 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIY "$N祭起一道金光，一块金砖呼！地一声向$n当头砸下！\n" NOR,
                        //initial message
                HIY "结果砸个正着，把$n砸得血肉模糊！\n" NOR, 
                        //success message
                HIY "但是$n在千钧一发之际跳了开来。\n" NOR, 
                        //fail message
                HIY "但是金砖被$n以法力一引，反而砸到了$N的顶门！\n" NOR, 
                        //backfire initial message
                HIY "结果砸个正着，把$n砸得血肉模糊！\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}


