// rulai jienan-zhi perform如来神掌
// lestat 2001

#include <ansi.h>
#include <combat.h>
#include "/daemon/skill/eff_msg.h";
inherit SSERVER;

int perform(object me, object target)
{
      string msg, dodge_skill;                                
      int damage, jiali, attack, defense, p;
      object armor;
      
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) || !living(target) )
           return notify_fail("「如来神掌」只能在战斗中对对手使用。\n");        
      if(me->query("family/family_name") != "南海普陀山" )
                return notify_fail("你是哪儿偷学来的武功！\n");
      if( (int)me->query_skill("jienan-zhi",1) < 100 )
           return notify_fail("你的劫难指不够娴熟，不会使用佛门神功「如来神掌」！\n");
      
      if( (int)me->query_skill("unarmed",1) < 100 )
           return notify_fail("你的基本手法不够娴熟，不会使用佛门神功「如来神掌」！\n");

      if( (int)me->query_skill("lotusforce",1) < 100 )
           return notify_fail("你的莲台心法等级不够，不能使用「如来神掌」！\n");  
      
      if( (int)me->query_str() < 24 )
           return notify_fail("你的先天臂力不够强，不能使用「如来神掌」！\n");
      
      if( (int)me->query("max_force") < 1200 )
           return notify_fail("你的内力太弱，不能使用「如来神掌」！\n");
      
      if( (int)me->query("force") < 800 )
           return notify_fail("你的内力太少了，无法使用出「如来神掌」！\n");   
       
      if( (int)target->query_condition("dashouyin"))
           return notify_fail("对方早已身中「如来神掌」绝技了！\n");   
                
      if( objectp(me->query_temp("weapon")) )
           return notify_fail("你必须空手使用「如来神掌」！\n");                                                                              
      
      jiali = me->query("force_factor")+1;
      attack = me->query("combat_exp")/1000;
      attack += me->query_skill("unarmed");
      attack += me->query("force")/5;
      defense = target->query("combat_exp")/1000;
      defense += target->query_skill("dodge");
      defense += target->query("force")/7;
//      attack = (attack+random(attack+1))/2;
      attack += random(defense+1);
      
      damage = me->query_skill("jienan-zhi", 1)/20 * jiali;
      if(damage > 800) damage = 800;
      
      message_vision(HIR"\n$N突然面色怪异，低声默念佛门真言，双臂骨节一阵爆响，猛然腾空而起，伸手向$n胸前按去，好一式"HIY"「如来神掌」"BLU"！\n"NOR,me,target);
 
//      if( attack > defense ) { 
      if( random( attack ) > defense/2 || !living(target) ) { 
      	 if( objectp(armor = target->query_temp("armor/cloth"))
      	    && armor->query("armor_prop/armor") < 600
      	    && damage > 100){
                	message_vision(HIY"只见这斗大的掌印正好印在$N的$n"HIY"上，越变越大，竟将它震得粉碎，裂成一块块掉在地上！\n"NOR, target, armor);
                        armor->unequip();
                        armor->move(environment(target));
                        armor->set("name", "破碎的" + armor->query("name"));    
                        armor->set("value", 0);
                        armor->set("armor_prop/armor", 0);
                        target->reset_action();
                        }
      	 tell_object(target, RED"你只觉得霍的胸口一阵剧痛，已经被拍中了前胸！\n"NOR);
      	 target->apply_condition("dashouyin", 1+(me->query_str()));
      	 target->receive_damage("kee", damage,  me); 
         target->receive_wound("kee", damage/2, me);
                 target->add("force",-damage);
         if ((int)target->query("force")<0)
             {
             	target->set("force",0);
		message_vision(HIR"$n一口鲜血狂喷而出！\n"NOR);
	     }
         p = (int)target->query("kee")*100/(int)target->query("max_kee");
         msg = damage_msg(damage, "内伤");
         msg += "( $n"+eff_status_msg(p)+" )\n";
         message_vision(msg, me, target);
         me->add("force", -jiali);
      	}
      else {
      	 dodge_skill = target->query_skill_mapped("dodge");
	 if( !dodge_skill ) dodge_skill = "dodge";
         message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);
         }
//      me->add("force", -200);
      me->start_busy(1+random(2));            
      return 1;
}

 

