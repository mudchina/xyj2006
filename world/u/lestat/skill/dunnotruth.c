// 『道可道 非常道』dunnotruth
// created by mind 2001/2
// /daemon/class/sanxian/spysword/dunnotruth.c

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        int damage,k;
        string msg;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        
//if(!me->query("m_success/剑道遗篇"))
//                return notify_fail("你不会剑道密传绝技。\n");
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("你不在战斗中。\n");
                
        if( (int)me->query_skill("spysword",1)< 150)
        return notify_fail("你的刺客剑法不够娴熟。\n");
        if(me->query("family/family_name")!="三界散仙")
        return notify_fail("你从哪里偷来的绝招？\n");
                        
        if( (int)me->query("force")<200)
        return notify_fail("你现在内力太弱，不能使用『道可道 非常道』。\n");
        if(me->query_temp("have_pfm"))
        return notify_fail("你刚展施完特殊招式，内息还没调整过来。\n");
        if (me->query("betrayer") || me->query("betray/count"))
           return notify_fail("三心二意者很难领悟散仙的精髓所在。\n");
        
        me->set_temp("have_pfm",1);

        msg = HIB "$N突然剑招一变，手中的"+ weapon->query("name")+ HIB"无影无踪，浑身喷薄出凌厉的剑气。\n"NOR;
        k=me->query("old_flag/jiandao");
        if(!k||k==0)    k=3;
        if(random(me->query("combat_exp"))>target->query("combat_exp")/k)
        {

        target->start_busy(1+random(2));
        me->start_busy(3);
        damage=(me->query_str()-target->query_con())*random(me->query_cor());
        if(damage<0)    damage=10;
        if( damage>500) damage=500;
                
        target->receive_damage("kee",damage,me);
        target->receive_wound("kee",damage/3,me);
        me->add("force",-damage/5);
        if( (int)me->query("force")<0)  me->set("force",0);
        
        if( damage < 40 ) msg += HIY"结果$n胸口一痛，闷哼一声。\n"NOR;
        else if( damage < 60 ) msg += HIY"结果$n被$N连中几剑，『嘿』地一声退了两步。\n"NOR;
        else if( damage < 120 ) msg += RED"结果$n被$N重重的剑气袭中，有如受到数记重锤，连退了五六步！\n"NOR;
        else msg += HIR"结果$n被$N的『道可道 非常道』剑气穿心，眼前一黑，身子向后飞出丈许！！\n"NOR;
        if(random(me->query("combat_exp"))>target->query("combat_exp")/k && k>8 && random(me->query_kar())>30) {
                        
                        msg += HIG "\n$N闲步微移，"+ weapon->query("name")+ HIG"灵动异常，";
                        msg += HIG"在剑意已尽，劲势已灭之际，又生新力，又续杀机！\n" NOR;
                        me->start_busy(4+random(2));
                        me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), random(2)+4);
        }               
        } else 
        {
        me->start_busy(1);
        me->add("force",-10);
                msg += CYN"可是$n看破了$N的企图，并没有上当。\n"NOR;
        }
        message_vision(msg, me, target);
        call_out("do_reset",3,me);
        return 1;
}

void do_reset(object me)
{
        if( !objectp(me))       return;
        if( (int)me->query_temp("have_pfm"))
                me->delete_temp("have_pfm");
}

void kill_him(object me, object target)
{
        string msg,str;
if(!living(target)) 
      return;
        
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
                msg =HIR"\n$n只觉得剑气袭体，眼睛顿时死鱼般的突了出来．．\n" NOR;
                target->receive_damage("sen",target->query("max_sen")+1,me);
                target->receive_wound("sen", (int)target->query("max_sen")+1, me);
                target->receive_damage("kee",target->query("max_kee")+1,me);
                target->receive_wound("kee", (int)target->query("max_kee")+1, me);
                msg+=HIR"\n$N看着$n的尸体，缓缓叹了口气．．．．\n" NOR;
                COMBAT_D->report_status(target);
                str=target->name()+"莫名其妙地死了，全身上下没有丝毫痕迹。\n难道"+target->name()+"死在．．．．看来世间又出现了剑道秘传弟子。";
        message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());   
                message_vision(msg, me, target);
                target->heart_beat();
        }
        return ;
}
