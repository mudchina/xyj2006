//yudian 2000-11-14
// zouxiao.c  碧箫传情  
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int damage, ap, dp,qixue,eff_qi,max_qi,qi_pcg;
        object weapon;
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁奏箫？\n");
         if(me->query("family/family_name") != "五庄观" )
                return notify_fail("你是哪儿偷学来的武功，也想用「奏箫」?\n");
        if( !me->is_fighting(target) )
                return notify_fail("大家都很忙，没人有时间听你吹吹打打。\n");
        if (!weapon || weapon->query("music/type") != "xiao")
                return notify_fail("你手里的家伙吹不出调子。\n");
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("只有用镇元神功才能运力吹箫。\n");
        if (me->query_skill("xiaofeng-sword",1)<50)
                return notify_fail("你的晓风残月剑还得再练练。\n");
        if (me->query_skill("zouxiao",1)<60)
                return notify_fail("你奏箫的功夫还不够，再好好练练吧。\n");
        if (target->query_skill("literate",1)<50)
                return notify_fail("对他吹箫？还不如对牛弹琴呢。\n");
        if((int)me->query("force") < 200 )
                return notify_fail("你的内力还不到火候。\n");
        if((int)me->query("kee") < 200 )
                return notify_fail("你的体力已经不够了！\n");
if((int)me->query("sen") < 200 )
                return notify_fail("你无法集中精力！\n");
        msg = HIC "\n$N举起"+weapon->query("name")+HIW"，对着$n奏起了一曲，箫声凄凉，"
                  +"似是叹息，又似哭泣，跟着箫声颤抖，发出瑟瑟瑟断续之音，如是一滴滴小雨落上树叶。\n" NOR,
        me->add("sen", -150);
        me->add("kee", -150);
        me->add("force", -150);
        ap =(int)me->query_skill("xiaofeng-sword", 1)+(int)me->query_skill("zouxiao", 1);
        damage=ap*ap/300;
        ap = ap * ap * ap /10;
        ap = ap + (int)me->query("combat_exp");
        dp =  (int)target->query_skill("parry")
             +(int)target->query_skill("literate")
             +(int)target->query_skill("zouxiao")
             +(int)target->query_skill("fuqin")
             +(int)target->query_skill("spells");
        dp = dp * dp * dp /10;   
        dp = dp + (int)target->query("combat_exp");
        if( random(100*ap/dp) <  20 ) 
{
             msg += HIW "$n冲着你鄙意的冷笑道：就这点本事，也来贻笑大方？"
                        +"$N顿时羞愧难当。\n"NOR;
             message_vision(msg, me, target);
             me->start_busy(3+random(5));
            } 
        else if( random(100*ap/dp) <  40 ) 
            {
             msg += HIW "可$n冲耳不闻，不为所动。\n"NOR;
             message_vision(msg, me, target);
             me->start_busy(random(3));
            } 
         else 
            {
             target->receive_damage("sen",damage,me);
             msg += HIW "$n听了箫声，心中莫名其妙的感到一阵酸楚，悲从中来，泪水正涔涔落下。\n"NOR;
             message_vision(msg, me, target);
             COMBAT_D->report_status(target); 
             target->start_busy(5+random(5));
             me->start_busy(random(3));
            }
          return 1;
}
