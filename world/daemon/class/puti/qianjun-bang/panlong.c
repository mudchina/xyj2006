#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
          int j,skill;
        string msg;

        if (me->query("fangcun/panlong_accept")!="done")
           return 0;


                 if((me->query("family/family_name") != "方寸山三星洞" ) && !wizardp(me))
                return notify_fail("你是哪儿偷学来的武功，也想用「盘龙八式」?\n");

		if( !target ) target = offensive_target(me);

        if( !target

        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「盘龙八式」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "stick")
                return notify_fail("「盘龙八式」必须用棍棒才能施展。\n");

             if( (int)me->query_skill("qianjun-bang", 1) < 120 )
                return notify_fail("你的「千钧棒」不够娴熟，不会使用「盘龙八打
」。\n");

        if( (int)me->query("force") < 2000  )
                return notify_fail("你的内力不够。\n");
        if(time()-me->query_temp("pl_end")<30) return notify_fail("你刚使出盘龙，突觉体力不够！\n");
   if (target->query_temp("jldl"))
         {
                    target->delete_temp("jldl");
                target->set_temp("jldl_end", time() );
 message_vision(HIR"$N运起盘龙八式，面对强大的气劲，$n的借力打力也失去了作用！\n\n\n"NOR,me,target);
           }
         skill=me->query_skill("qianjun-bang",1);
              target->start_busy(2);
            target->add_temp("apply/dodge",-skill*2);
            target->add_temp("apply/parry",-skill*2);
		msg = HIG "$N跳至空中，手中的$n"+HIG"好似"+HIY"盘龙出沧海"+HIG"顿时化作无数条影子。\n"NOR;
        message_vision(msg, me, weapon);
      me->add_temp("apply/attack",skill);
    me->add_temp("apply/damage",skill);
       for(j=1;j<=8;j++)
   {
   msg = HIR "满天棍影中，$N砸出第"+HIY+chinese_number(j)+HIR+"棍。\n"NOR;
   message_vision(msg, me, weapon);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
   }    
      if(me->query("id")!="take")
	{
		me->set_temp("pl_end",time());
        me->start_busy(7+random(3));
        me->add("force", -1500);
	}
    me->add_temp("apply/attack",-skill);
    me->add_temp("apply/damage",-skill);
            target->add_temp("apply/parry",skill*2);
            target->add_temp("apply/dodge",skill*2);
        return 1;
}
