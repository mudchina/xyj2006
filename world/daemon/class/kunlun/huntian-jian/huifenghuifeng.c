// huifeng.c
//write by yesi
//yeahsi@21cn.com

#include <ansi.h>
inherit SSERVER;

void check(object me);
void huifeng_effect(object me, object victim);
void remove_effect(object me);

int perform(object me)
{
        int skill;
        int sword_skill,snowsword_skill;
        
        skill = me->query_skill("moonforce",1);
        if( skill > 250 ) skill=250;
        sword_skill= me->query_skill("sword",1);
        snowsword_skill= me->query_skill("snowsword",1);
                       
                               
        if( skill < 100 )  return notify_fail("你的圆月心法修为不够。\n");
        if( sword_skill < 80 )  return notify_fail("你的基本剑法未够纯熟。\n");
        if( snowsword_skill < 120 )  return notify_fail("你的风回雪舞剑法未够纯熟。\n");
        
        if( me->query_temp("huifeng") ) 
          {remove_effect(me);return 1;}
          
        if (me->query_skill_mapped("force")!="moonforce")
            return notify_fail("「回风」必须配合圆月心法才能使用。\n");
        
//        if(me->query("family/family_name") != "月宫")
//               return notify_fail("[回风]是月宫不传之密！\n");     
        
        if( time()-(int)me->query_temp("huifeng_end") < 10 )
                return notify_fail("你现在真气不纯！\n");       
               
        
        if( (int)me->query("force") < skill )     
                return notify_fail("你的内力不够。\n");
 
        me->add("force", -skill);
        message_vision(HIG "$N把圆月心法在体内运行一周，只觉得全身轻飘飘的，似乎可以随风飘起！\n" NOR, me);
        me->set_temp("huifeng", 1);
        me->set_temp("huifeng_time",skill);
        me->add_temp("apply/dodge",skill/6);
        me->set_temp("apply/sword",skill/6);
                   
        call_out("check", 1, me);
        return 1;
}


void check(object me)
{       
        object weapon;
        
         if(!me) return;
                
         if (me->query_skill_mapped("force") != "moonforce"
                 || !objectp(weapon=me->query_temp("weapon")) 
                 || (weapon->query("apply/skill_type") != "sword" 
                     && weapon->query("skill_type") != "sword" ) 
                 ||  me->query_skill_mapped("sword") != "snowsword" )     
             remove_effect(me);
         else if(me->query_temp("huifeng_time")<1)
             remove_effect(me);                 
         else {  me->add_temp("huifeng_time",-1);
                call_out("check", 1, me);
              }
                     
}


void remove_effect(object me)
{
        int skill = me->query_skill("moonforce",1);
        if(!me) return;
        remove_call_out("check");
        me->delete_temp("huifeng");
        me->set_temp("huifeng_end",time());
        me->add_temp("apply/dodge",-skill/6);
        me->add_temp("apply/dodge");
        me->delete_temp("apply/sword");
        tell_object(me, GRN"你将圆月心法收回丹田。\n"NOR);
}

void huifeng_effect(object me, object victim)
{   int damage,ini_damage_apply,skill,ini_attack_apply;
    string str;
    skill = me->query_skill("snowsword",1)/2; 
   
   if ( random(2)>0 )
          { ini_damage_apply = me->query_temp("apply/damage");
            ini_attack_apply = me->query_temp("apply/attack");
            me->add_temp("huifeng",1);
            message_vision(HIG"\n$N一剑落空，在半空中腰身一扭，向$n又攻出一招！\n"NOR,me,victim);
            me->add_temp("apply/damage",30);
            me->add_temp("apply/attack",skill);
            damage = COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));         
         
               
   if( damage <= 0 )
          {
           message_vision(HIG"\n$N的圆月真气在体内迅速流转，手腕一扭，身随剑飘,在几乎不可能的角度再度出招！\n"NOR,me);
           me->add_temp("apply/damage",30);
           me->add_temp("apply/attack",skill);
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));         
           me->add_temp("huifeng",-1);
           }             
    else me->add_temp("huifeng",-1);
    
    me->set_temp("apply/damage",ini_damage_apply);
    me->set_temp("apply/attack",ini_attack_apply);
          }
}
 
