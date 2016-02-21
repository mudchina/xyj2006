//Cracked by Roath

//Ansi 99.8
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg;
   int damage, ap;

   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail("你要对谁施「酒神」？\n");

   if((int)me->query_skill("taoism", 1) < 100 )
     return notify_fail("你的天师仙法火候不够，哪可能呼唤出「酒神」！\n");
   if(!me->query("shushan/jiushen_master"))
     return notify_fail("你还不会「酒神」这种法术！\n");

   if((int)me->query("mana") < 500 )
     return notify_fail("你的法力不够，呼唤出「酒神」恐怕也没有什么用！\n");

   if((int)me->query("sen") < 10 )
     return notify_fail("你现在神智不清！\n");

   me->set("mana", 0);

   msg = HIR "$N集中全身精气，突然爆发，呼唤出「酒神」，产生惊天动地的震动！\n" NOR;
   msg = HIR "\n        
                      《#
                      @  @_                  
                    《    @    
                     @     @    
                     _*****_   
                   《    蜀  @  
                   @         @   
                    @   山    @  
    _________________@_______@______         
  《____________________________iiiiii)***  
                              @《^^^^^  *****
                                           ***\n"NOR;

   ap = me->query_skill("spells") ;
   damage = (me->query("force")+ me->query("mana")) / 20;
   damage += (int)me->query("sen")/5 + ap + (int)me->query("mana_factor") - random((int)target->query("mana_factor"));
        damage = damage + random(damage);
        if (damage > 1200) damage = 1150+ random(75);
        msg += HIC "结果$n被「酒神」镇伤！\n" NOR;
        target->receive_wound("sen", damage, me);
        target->apply_condition("drunk",50);
   message_vision(msg, me, target);
   if( damage > 0 ) COMBAT_D->report_sen_status(target);

   if( !target->is_fighting(me) ) 
   {
     if( living(target) ) 
     {
        if( userp(target) ) target->fight_ob(me);
        else target->kill_ob(me);
     }
     me->kill_ob(target);
   }

   me->start_busy(2+random(2));
   return 10+random(20);
}
