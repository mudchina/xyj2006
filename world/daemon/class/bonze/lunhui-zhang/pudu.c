// writted by jie
// 2/2001

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「慈光普渡」？\n");

        if(!me->is_fighting())
                return notify_fail("「慈光普渡」只能在战斗中使用！\n");
        
        if(me->query("family/family_name")!="南海普陀山")
                return notify_fail("不是佛门弟子不能用「慈光普渡」！\n");
        // 佛门杀气高？好象不符合现实，所以设定这杀气条件
        if( (int)me->query("bellicosity") > 300 )
        return notify_fail("你的杀气太重，无法施展佛门绝技。\n");
                
        if (me->query_skill_mapped("force")!="lotusforce")
                return notify_fail("「慈光普渡」必须以莲台心法为底子！\n");
                
        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("lotusforce", 1) < 80)
                return notify_fail("你的莲台心法修为还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("lunhui-zhang", 1) < 80)
                return notify_fail("你的轮回杖修为还不够，使用这一招会有困难！\n");
        message_vision(HIY"$N气沉丹田，犹如金刚浑身发金光，招转佛门正宗绝招「慈光普渡」，向$n连续发动进攻！\n"NOR,me,target);
        me->set("ciguangpudu", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->set("ciguangpudu", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->delete("ciguangpudu");
        me->start_busy(2+random(1));
        message_vision(HIW"$N低吟“阿弥陀佛！”「慈光普渡」用功完毕，身上淡淡的金光慢慢隐去.\n"NOR,me,target);
        message_vision(msg,me,target);
        me->add("kee", -100);
        me->add("force", -100);
        me->add("sen",-100);
        return 1;
}
