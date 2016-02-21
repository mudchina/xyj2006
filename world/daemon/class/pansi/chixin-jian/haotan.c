//yudian 2000-11-14
// haotan.c  痴情八叹  
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
                return notify_fail("没人愿意听你诉苦。\n");
        if( !me->is_fighting(target) )
                return notify_fail("不在战斗中，还是弹琴聊以自慰吧。\n");
        if (!present("wuxian qin", me))
                return notify_fail("「痴情八叹」必须有七弦琴配合才能使用。\n");
		if(me->query("family/family_name")!="盘丝洞")
return notify_fail("“痴情八叹”只有盘丝洞门人才可以用！\n");
        if (me->query_skill_mapped("force")!="jiuyin-xinjing")
                return notify_fail("只有用九阴心经做功底。\n");
        if (me->query_skill("chixin-jian",1)<50)
                return notify_fail("你的痴心情长剑法还得再练练。\n");
        if (me->query_skill("qin",1)<50)
                return notify_fail("你琴艺的功夫还不够，再好好练练吧。\n");
        if (target->query_skill("literate",1)<50)
                return notify_fail("他是个粗人，不懂这些儿女心事。\n");
        if((int)me->query("force") < 100 )
                return notify_fail("你的内力还不到火候。\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("你的体力已经不够了！\n");
	if((int)me->query("sen") < 150 )
                return notify_fail("你连自己都控制不住自己的感情！\n");
        msg = HIC "\n$N凝住"+weapon->query("name")+HIC"，稳而不发，剑势不减，剑意不绝！\n" NOR,
        msg += RED "\n$N从琴囊里掏出"+HIB"七弦琴"NOR+RED"，居然就地盘膝而坐，以"+weapon->query("name")+RED"为指，连扣琴弦，对着$n纵声浩叹，\n" NOR,
        msg += HIM "\n“此恨绵绵无绝期”，似是叹息，又似哀怨，跟着琴声颤抖，如是更漏欲绝，明烛将熄。\n\n" NOR,
        me->add("sen", -150);
        me->add("kee", -150);
        me->add("force", -150);
        ap =(int)me->query_skill("chixin-jian", 1)+(int)me->query_skill("qin", 1);
        damage=ap*ap/300;
        ap = ap/10 * ap * ap;
        ap = ap + (int)me->query("combat_exp");
        dp =  (int)target->query_skill("parry")
             +(int)target->query_skill("dodge")
             +(int)target->query_skill("literate")
             +(int)target->query_skill("spells");
        dp = dp/10 * dp * dp;   
        dp = dp + (int)target->query("combat_exp");
        if( random(100*ap/dp) <  20 ) 
{
             msg += HIW "$n冲着你鄙意的冷笑道：别婆婆妈妈的，这种事情还好意思说？！"
                        +"$N顿时羞愧难当。\n"NOR;
             message_vision(msg, me, target);
             me->start_busy(1+random(2));
            } 
        else if( random(100*ap/dp) <  40 ) 
            {
             msg += HIW "可$n冲耳不闻，不为所动。\n"NOR;
             message_vision(msg, me, target);
             me->start_busy(1+random(2));
            } 
         else 
            {
             target->receive_damage("sen",damage,me);
             target->receive_wound("sen", damage,me);
             msg += HIM "$N前三叹未绝，又和琴浩叹：“黯然消魂未尽时！”\n如此痴情八叹，琴声斗转，犹如夜幕般弥散开来。\n\n"NOR;
             msg += HIW "$n为琴声感染，无限思绪纷至沓来，恍然不在人世！\n"NOR;
             message_vision(msg, me, target);
             COMBAT_D->report_status(target); 
             target->start_busy(5+random(5));
             me->start_busy(1+random(2));
            }
          return 1;
}

