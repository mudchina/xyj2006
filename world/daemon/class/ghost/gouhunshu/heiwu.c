
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg;
   int damage, ap, dp;

   if( !target ) target = offensive_target(me);
   if(me->query("family/family_name")!="阎罗地府")
                return notify_fail("你不是地府弟子，不能使用这项技能！\n");
   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail(HIR"你要对谁使用黑雾？\n"NOR);

    if((int)me->query_skill("gouhunshu", 1) < 30 )
     return notify_fail("你的勾魂术火候不够，哪里用得出这招！\n");
   
   if((int)me->query("mana") < 40+(int)me->query("mana_factor") )
     return notify_fail("你的法力不够！\n");

   if((int)me->query("force") < 200 )
     return notify_fail("你的内力不够，无法喷出黑雾。\n");

   if((int)me->query("sen") < 40 )
     return notify_fail("你现在神智不清，别把自己迷倒了！\n");

   me->add("mana", -50-(int)me->query("mana_factor"));
   me->add("force", -150);
   me->receive_damage("sen", 50);

   if( random(me->query("max_mana")) < 150 ) 
   {
     write("这一次好象不灵。\n");
     return 1;
   }

   msg = HIG "$N突然腾空而起，口中高呼念念有词，张口喷出黑雾将$n团团围住！\n" NOR;

   ap = me->query_skill("spells");
      ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
   ap += (int)me->query("combat_exp");
   dp = target->query("combat_exp");
   if( random(ap + dp) > dp ) 
   {
     damage = (int)me->query("max_mana") / 10 + random((int)me->query("eff_sen") / 10);
     damage -= (int)target->query("max_mana") / 10 + random((int)me->query("eff_sen") / 5);
     damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
     //here we can see if 2 players are at same status, the attacker has higher chance.
     if( damage > 0 ) 
     {
        //finally damage also depends on enabled spells level.
        damage +=damage+random((damage*(int)me->query_skill("spells"))/240);
        msg += HIM "结果$n分不清东西了！\n" NOR;
        target->receive_damage("sen", damage, me);
        target->receive_wound("sen", damage*2, me);
        target->receive_damage("kee", damage*2, me);
        target->receive_wound("kee", damage*3, me);
        target->start_busy(1);
        me->improve_skill("gouhunshu", 1, 1);
        me->start_busy(2);
     }
     else 
        {
        //here, cast failed and the target's mana_factor will be added to the previous 
        //damage to hurt yourself:(...note, damage<0.
        msg += HIC "结果黑雾$n以法力一逼，反向$N回卷而去！\n" NOR;
        damage -= (int)target->query("mana_factor");
        damage -= random((-damage*(int)target->query_skill("spells"))/100);
        me->receive_damage("sen", -damage, target);
        me->receive_wound("sen", -damage*2, target);
        me->receive_damage("kee", -damage, target);
        me->receive_wound("kee", -damage*3, target);
      //  me->improve_skill("taiyi", 1, 1);
     }
   } 
   else
     msg += "但是被$n躲开了。\n";

   message_vision(msg, me, target);
   if( damage > 0 ) COMBAT_D->report_status(target);
   else if( damage < 0 ) COMBAT_D->report_status(me);
   //damage=0 corresponding to "但是被$n躲开了。\n"--no report.   

   if( !target->is_fighting(me) ) 
   {
        if( living(target) ) 
     {
        if( userp(target) ) target->fight_ob(me);
        else target->kill_ob(me);
     }
     me->kill_ob(target);
   }

   me->start_busy(1+random(2));
   return 3+random(5);
}
