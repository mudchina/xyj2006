// fu by yushu 2000.11
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 100;
        damage_adj = 100;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施天师符法？\n");
        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("你不是蜀山弟子，不能使用这项技能！\n");

        if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你无法集中精力！\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 50 ) {
                write("你一着急竟然忘了咒语。\n");
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
                "qi",           
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "\n$N一脸肃杀之气，抬手仍出一张天师符「呼」地一下飞到半空，射向$n！\n" NOR,
                        //initial message
                HIR "\n$n被光影罩住，波的喷出一口鲜血！\n" NOR, 
                        //success message
                YEL "结果$n灵机一动躲了过去。\n" NOR, 
                        //fail message
                HIC "但是$n伸指一弹，红光一暗，天师符反向$N贴去！\n" NOR, 
                        //backfire initial message
                HIR "结果扑！地一声天师符在$n凭空化去！\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}


