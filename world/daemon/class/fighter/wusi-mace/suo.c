//Cracked by Roath
// suo.c 锁字诀

#include <ansi.h>

inherit SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, skill1, skill2, ap, dp, damage;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lengquan-force",1);
        skill1 = me->query_skill("wusi-mace",1);
        skill2 = me->query_skill("dodge",1);
        
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "mace")
           return notify_fail("你没用锏，拿什么锁别人的兵器！\n");

        if( me->query("str") < 22 )
            return notify_fail("你的先天膂力孱弱, 不能使用「万刃归一」！\n");
            
        if(me->query("family/family_name") != "将军府" )
                return notify_fail("你是哪儿偷学来的武功，也想用「万刃归一」！\n");

        
        if( !(me->is_fighting() ))
            return notify_fail("「万刃归一」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("wusi-mace", 1) < 100 )
                return notify_fail("你的无私锏法不够娴熟，不能使用。\n");
                                
        if( (int)me->query_skill("lengquan-force", 1) < 80 )
                return notify_fail("你的冷泉心法还差些火候。\n");
        
        if (!objectp(weapon2 = target->query_temp("weapon")))
            return notify_fail("对方没有使用兵器，你用不了「万刃归一」。\n");

        if( me->query("force") < 500 )
                return notify_fail("你的内力不够，无法运用「万刃归一」！\n");


        msg = HIC "$N手中"+weapon->name()+""HIC"迎面一架，斜刺一拉，好一招「万刃归一」!\n$N手中"+weapon->name()+""HIC"正好锁在$n的"+weapon2->name()+"上。\n";
        message_vision(msg, me, target);
        
        damage = (int)me->query_skill("lengquan-force", 1);
        damage = damage +  (int)me->query_skill("wusi-mace", 1);
        damage = damage +  (int)me->query_skill("mace", 1);
                
        ap = me->query_skill("mace") / 4 + (skill1 / 3);
        dp = target->query_skill("dodge") / 2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > random(dp) )
        {
            if(userp(me))
                 me->add("force",-150);
            msg = HIW"$n顿时觉得一股强大的力量传向自己的手腕，手中";
            msg += weapon2->name();
            msg += "脱手飞出! \n"NOR;
            msg += HIR"同时逆血冲上心头，忍不住吐出一口鲜血.\n"NOR;
            me->start_busy(random(2));
            target->receive_damage("kee", damage);
            target->start_busy( (int)me->query_skill("wusi-mace") / 20 + 1);
            weapon2->move(environment(me));
        }
        else
        {
            if(userp(me))
                 me->add("force",-50);
            msg = RED"$n急运内力，将手中" + weapon2->name()+
"斜斜顺势一送一搭，抽了回来。\n"NOR;
            me->start_busy(6);
        }
        message_vision(msg, me, target);

        return 1;
}
