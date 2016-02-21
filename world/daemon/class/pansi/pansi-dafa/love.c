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
     return notify_fail("你要对谁施「爱神」？\n");

   if((int)me->query_skill("pansi-dafa", 1) < 100 )
     return notify_fail("你的盘丝大法火候不够，哪可能呼唤出「爱神」！\n");
   if(!me->query("pansi/love_master"))
     return notify_fail("你还不会「爱神」这种法术！\n");

 if((int)me->query("mana") < (int)me->query("max_mana") )
return notify_fail("你的法力不够，呼唤出「爱神」恐怕也没有什么用！\n");

if((int)me->query("force") < (int)me->query("max_force") )
    return notify_fail("你的内力不够，呼唤出「爱神」恐怕也没有什么用！\n");

 if((int)me->query("sen") < 10 )
     return notify_fail("你现在神智不清！\n");

me->set("mana", 0);
me->set("force", 0);

   msg = HIR "$N口中念了几句咒文，随着一声“丘比特在此！半空中现出一位小天使！\n只见他张弓搭箭，“嗖”的一声，一只桃色小箭向$n激射而下！\n" NOR;
   message_vision(msg,me,target);
   msg = HIM "\n
	         ,@@@@@@,
　　　　    　 ,@@@@@""@@, ( 　   _  _
　　　  　　,　@@@@@ 6.6)@ [)　 ( @@ )
　　　  　 {{^L@@@C　_-_)@ [ )　 (　)
　  　　　 {{!L(@@@) (@@'　[　)   ()
　　　  　 {{!!K) /　 )---.[.__) 　　　 
　　　  　　`!!K( ,　 )---[---._)
　　　  　　 `~`~, L　)|_.->>>==I======> 　\n"NOR;

   ap = me->query_skill("spells") ;
   damage = (me->query("force")+ me->query("mana")) / 20;
   damage += (int)me->query("sen")/5 + ap + (int)me->query("mana_factor") - random((int)target->query("mana_factor"));
        damage = damage + random(damage);
        if (damage > 1200) damage = 1150+ random(75);
        msg += HIC "结果$n被「爱神」一箭射中！身中情毒！\n" NOR;		
        target->apply_condition("xiangsi",20);
        target->receive_wound("kee", damage, me);
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

