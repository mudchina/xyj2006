#include <ansi.h>
inherit SSERVER;
void npc_attack(object invoker, object target, string npc, object where);
void check(object me,object target,string tname);
int perform(object me, object target)
{
   string msg;
   string npc_dir = "/obj/npc/long";
   object where;
   object soldier;
   int i,j;

   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
     return notify_fail("你对谁施展庐山升龙霸？\n");

   if(!wizardp(me)&&(string)me->query("family/family_name") != "东海龙宫" )
     return notify_fail("你又不是东海弟子，不会庐山升龙霸。\n");

   if((int)me->query_skill("dragonfight", 1) < 100)
         return notify_fail("你的龙形搏击修为不深，施展不出庐山升龙霸。\n");
   
   if((int)me->query("force") < 1000 )
     return notify_fail("你的内力不够。\n");

   if((int)me->query("sen") < 100 )
     return notify_fail("你现在神智不清！\n");

   me->add("force", -200);
   me->receive_damage("sen", 100);
   i=(int)me->query_skill("dragonfight", 1)-100; 
   i/=50;
   if (i>9) i=9;
   msg = HIC "$N大喊一声『庐山升龙霸』，"+chinese_number(i)+"条神龙自九天而起，直飞$n！\n\n" NOR;  
COMBAT_D->do_attack(me, target, weapon);
COMBAT_D->do_attack(me, target, weapon);
COMBAT_D->do_attack(me, target, weapon);
   message_vision(msg, me, target);
   where=environment(target);
   for(j=1;j<=i;j++)
   {
   call_out("npc_attack", 1, me, target, npc_dir+j, where);
   }
   call_out("check", 3, me, target,target->query("name"));
me->start_busy(1+random(3));
   return 1;
}

void npc_attack(object invoker, object target, string npc, object where)
{
   object attacker;
   string msg,str;
   if(!invoker || !target) return;
   if( environment(invoker) != environment(target) ) return;
   if( environment(target) != where) return;
   seteuid(getuid());
   attacker = new(npc);
   attacker->move(environment(invoker));
   COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"));
   if(target->query_temp("last_damage_from")==attacker)
       target->set_temp("last_damage_from", invoker);
   if(target->query_temp("last_fainted_from")==attacker)
       target->set_temp("last_fainted_from", invoker->query("id"));
   destruct(attacker);
}
void check(object me,object target,string tname)
{
 string msg;
if (!target||target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {
                       msg=HIM+tname+HIM+"被"+me->name()+"用东海秘传"NOR+HIC"「庐山升龙霸」"+HIM"打死了！尸体上龙影纵横。";
                       message("channel:rumor",HIM"【空穴来风】某人："+msg+"\n"NOR,users());
                       }
}
