//Cracked by Roath

//Ansi 99.12
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int ap,dp,damage,chance;
        string msg;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「断水无痕」？\n");

        if(!me->is_fighting())
                return notify_fail("「断水无痕」只能在战斗中使用！\n");
        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("不是蜀山的不能用「断水无痕」！\n");
//        if(me->query("shushan/duanshui_master")!=1)
//                return notify_fail("你还没领会「断水无痕」！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

   if((int)me->query("force") < 500 )
     return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("yujianshu", 1) < 100)
                return notify_fail("你的蜀山剑法修为还不够，使用这一招会有困难！\n");


        msg = CYN"\n$N手腕晃动如疾风，以砍断三千尺飞流的速度，直逼$n！\n"NOR;
        ap = me->query_skill("sword");
        ap = ap*ap*ap / 20;
        dp = target->query("combat_exp"); 
        chance = (int)(random( ap + dp ) / dp * 100);
        if (target->is_busy()) chance *= 3;
        if( chance > 40 ) {
                damage = me->query_skill("sword") * 2 + me->query("force_factor");
                if (damage > 800) damage = 750+random(75);
                target->receive_damage("kee",damage);
                target->receive_wound("kee",damage/3);
target->start_busy(random(1)+1);
                msg += CYN"结果$n被$N的「断水无痕」拦腰而过！\n"NOR;
        }
        
        else 
                msg += "但是被$n躲开了。\n"NOR;
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
   
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->add("force",-200-me->query("force_factor"));
        me->start_busy(3);
        return 1;
}
