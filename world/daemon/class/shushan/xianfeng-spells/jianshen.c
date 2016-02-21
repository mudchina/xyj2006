//Cracked by Roath

//Ansi 99.8
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg;
   int damage, ap, dp, s_num, chance;

   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail("你要对谁施「剑神」？\n");

   if((int)me->query_skill("xianfeng-spells", 1) < 50 )
     return notify_fail("你的天师仙法火候不够，哪可能呼唤出「剑神」！\n");

   if((int)me->query("mana") < 125+(int)me->query("mana_factor") )
     return notify_fail("你的法力不够，呼唤出「剑神」恐怕也没有什么用！\n");

   if((int)me->query("force") < 100 )
     return notify_fail("你的内力不够，无法将「剑神」呼唤出来。\n");

   if((int)me->query("sen") < 10 )
     return notify_fail("你现在神智不清！\n");

   me->add("mana", -125-(int)me->query("mana_factor"));
   me->add("force", -100);
   me->receive_damage("sen", 10);

   if( random(me->query("max_mana")) < 50 ) 
   {
     write("这一次好象不灵。\n");
     return 1;
   }
        s_num = (int)(random(me->query_skill("spells")/20)) + (int)(me->query_skill("spells")/20)+ 1;
   msg = HIC "$N口中念念有辞，突然天空中出现「剑神」的身影！成千上万把灵剑向$n飞去！\n" NOR;

   ap = me->query_skill("spells");
   ap =  ap * ap * ap / 100;
   dp = target->query("combat_exp")* 4 /5;
   chance = (int)(random(ap + dp) * 100 / dp);
   if( chance > 66 ) 
   {
        damage = s_num * 30 ;
        damage +=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
        msg += HIC "结果$n身中"+chinese_number(s_num)+"剑！\n" NOR;
        target->receive_wound("kee", damage, me);
        me->improve_skill("taoism", s_num, 1);
     }
     else if ( chance > 33 ) 
     {
        damage = s_num * 15 ;        
        msg += HIC "结果$n被"+chinese_number(s_num)+"剑擦伤！\n" NOR;
        target->receive_wound("kee", damage, target);
        me->improve_skill("taoism", s_num, 1);
     } 
   else
     msg += "但是被$n全躲开了。\n";

   message_vision(msg, me, target);
   if( damage > 0 ) COMBAT_D->report_status(target);
   else if( damage < 0 ) COMBAT_D->report_status(me);

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
   return 10+random(5);
}

