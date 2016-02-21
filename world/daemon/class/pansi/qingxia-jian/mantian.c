// mantian.c 青霞漫天
// 功力浅sword 有效等级180下时，可以震碎自己手中宝剑，以碎剑袭人
// 功力深厚sword 有效等级180上时，就可以施展剑铓（不碎剑）
// 考虑了手中剑碎后，无武器，就call_out("perform_qiao", 10, me)
// 用剑鞘杀人，连续发三招。剑鞘文件/d/pansi/obj/qiao
// daemon/class/pansi/qingxia-jian/mantian 青霞剑法
// jie 2001-2-4
 
#include <ansi.h>
 
inherit SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        object ob;
        int skill, skill2, ap, dp,kee_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("sword");
        skill2 = me->query_skill("force");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("笨蛋，不使剑怎么能使「青霞漫天」？\n");

                if(me->query("family/family_name")!="盘丝洞")
return notify_fail("从哪里偷来的功夫?你始终记不起该如何出手！\n");
        if((string)weapon->query("name") == "剑鞘")
                return notify_fail("傻瓜，剑鞘怎么逼的碎？\n");

        if( !me->is_fighting()|| !living(me) )
                return notify_fail("「青霞漫天」只能在战斗中使用。\n");

        if( (int)me->query("max_force") < 600 )
                return notify_fail("你的内力修为还不够高！\n");

        if( (int)me->query("force") < 300 )
                return notify_fail("你现在的内力不足！\n");

        if( skill < 100)
                return notify_fail("你青霞剑法的修为不够，不能使用「青霞漫天」! \n");

        if( skill2 < 90)
                return notify_fail("你九阴心经的修为不够，不能使用「青霞漫天」! \n");

        if( me->query_skill_mapped("sword") != "qingxia-jian") 
                return notify_fail("你没有激发青霞剑法，无法使用「青霞漫天」！\n");
 
        if (skill<180 && me->query_str()>100)
        {
                msg = HIY "$N忽然向后疾退两步，气沉丹田，力贯剑身，霎时剑身碎裂，犹如－－
                \n"HIC"『青霞漫天』
                \n"HIY"－－无数剑片铺天盖地向$n飞射而去。\n\n"NOR;
                message_vision(msg, me, target);
                ob = me->query_temp("weapon");
// 如果手中装备的不是紫青宝剑，那么手中的剑就没了
// 注意可以在紫青宝剑d/pansi/obj/ziqing.c文件中插入
// set("no_break", 1);                
        if( (string)weapon->query("id")!="ziqing sword")
                destruct(ob);
 
                ap = ((me->query("combat_exp"))*(me->query_spi()));
                dp = ((target->query("combat_exp"))*(target->query_spi()))/2;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        msg = HIR "$n面前仿佛涌起万丈青色霞光，惊愕之下，无数剑片已然嵌在了$n的身上，\n\n$n惨叫一声，脸上露出极为痛苦的表情。\n\n"NOR;
                        message_vision(msg, me, target);
                        kee_wound = 100 + skill + random(skill*2);

                        if(kee_wound > target->query("kee")) kee_wound = (target->query("kee") + 1);
                        target->add("kee", -kee_wound);
                        target->add("eff_kee", -(kee_wound/4));
                        COMBAT_D->report_status(target, 0);
                        me->start_busy(1+random(2));
                        me->add("force",-250);
                }
                else
                {
                        msg = HIG "只见$n不敢怠慢，脚一点地疾飞冲天，堪堪躲过了这满天的剑片。\n\n"NOR;
                        message_vision(msg, me, target);
                        me->start_busy(3);
                        me->add("force",-100);
                }

                call_out("perform_qiao", 10, me);
                return 1;
        }
        else if(skill<180 && me->query_str()<100 )
        {
                msg = HIW "$N忽然向后疾退两步，手腕一振就要施展青霞剑法无上绝技之一的“青霞漫天”，
                \n却不料功力不足，居然没有震碎手中"+weapon->query("name")+HIW"。\n" NOR;
                msg += HIR "$n刚要躲闪，突然发现机会难得，立时又扑了上来。\n\n";
                message_vision(msg, me, target);
                me->add("force",-50);
                me->start_busy(1+random(2));
        }
        else
        {
                msg = HIW "$N突然向后疾退两步，力惯"+weapon->query("name")+HIW"，三寸剑芒吞吐，手腕一振，\n竟然使出了青霞剑法密传绝技
\n"HIC"★★★★★青霞剑芒★★★★★
\n\n"HIW"万点剑芒云起风涌，如清风拂铃，如靡音过耳罩向$n。\n\n" NOR;
                message_vision(msg, me, target);

                ap = ((me->query("combat_exp"))*(me->query_spi()));
                dp = ((target->query("combat_exp"))*(target->query_spi()))/2;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        msg = HIR "$n对付这招显然束手无策，万道剑芒恰如无数剑片打在了$n的身上，\n\n$n惨叫一声，脸上露出极为痛苦的表情。\n\n"NOR;
                        message_vision(msg, me, target);
                        kee_wound = 100 + skill + random(skill*2);

                        if(kee_wound > target->query("kee")) kee_wound = (target->query("kee") + 1);
                        target->add("kee", -kee_wound);
                        target->add("eff_kee", -(kee_wound/4));
                        COMBAT_D->report_status(target, 0);
                        me->start_busy(1 + random(2));
                        me->add("force",-200);
                }
                else
                {
                        msg = HIG "$n显然老练至极，脚一点地疾飞冲天，堪堪躲过了这满天的剑芒。\n\n"NOR;
                        message_vision(msg, me, target);
                        me->start_busy(2);
                        me->add("force",-100);
                }

                return 1;
        }

        return 1;
}
int perform_qiao(object me)
{
        object weapon, target;
        target = me->select_opponent();
        if(me->is_fighting() && living(target) && living(me) && (!objectp(weapon = me->query_temp("weapon"))))
        {
                object qiao;
                string msg;
                int count;
                qiao = new("/d/pansi/obj/qiao");
                qiao->move(me);
                qiao->wield();
                count = me->query_spi();
                me->add_temp("apply/dodge", count * 3); 
                count = me->query_str();
                me->add_temp("str", count * 2); 
                msg = HIY "\n$N突然从腰畔将剑鞘拿到手中，招式突然加速，闪电般攻出三招，这突然的变化令$n目瞪口呆！\n\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                me->delete_temp("apply/dodge", count * 3);
                me->delete_temp("str", count * 2);
        }
        return 1;
}

