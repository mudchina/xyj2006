//改为xue.c
//天下有雪
//write by yesi
//yeahsi@21cn.com

#include <ansi.h>
inherit SSERVER;

void check(object me);
void pfmxue_effect(object me, object victim);
void remove_effect(object me);

int perform(object me)
{
        int skill;
        int sword_skill,snowsword_skill;
        
        skill = me->query_skill("xuanzong-force",1);
        if( skill > 250 ) skill=250;
        sword_skill= me->query_skill("sword",1);
        snowsword_skill= me->query_skill("huntian-jian",1);
                       
                               
        if( skill < 100 )  return notify_fail("你的玄宗心法修为不够。\n");
        if( sword_skill < 80 )  return notify_fail("你的基本剑法未够纯熟。\n");
        if( snowsword_skill < 120 )  return notify_fail("你的混天一剑未够纯熟。\n");
        
        if( me->query_temp("pfmxue") ) 
          {remove_effect(me);return 1;}
          
        if (me->query_skill_mapped("force")!="xuanzong-force")
            return notify_fail("「天下有雪」必须配合玄宗心法才能使用。\n");
        
        if(me->query("family/family_name") != "昆仑山玉虚洞")
               return notify_fail("[天下有雪]是玉虚不传之密！\n");     
        
        if( time()-(int)me->query_temp("pfmxue_end") < 10 )
                return notify_fail("你现在真气不纯！\n");       
               
        
        if( (int)me->query("force") < skill )     
                return notify_fail("你的内力不够。\n");
 
        me->add("force", -skill);
        message_vision(HIG "$N把玄宗心法在体内运行一周，只觉得全身轻飘飘的，似乎可以随风飘起！\n" NOR, me);
        me->set_temp("pfmxue", 1);
        me->set_temp("pfmxue_time",skill);
        me->add_temp("apply/dodge",skill/6);
        me->set_temp("apply/sword",skill/6);
                   
        call_out("check", 1, me);
        return 1;
}


void check(object me)
{       
        object weapon;
        
         if(!me) return;
                
         if (me->query_skill_mapped("force") != "xuanzong-force"
                 || !objectp(weapon=me->query_temp("weapon")) 
                 || (weapon->query("apply/skill_type") != "sword" 
                     && weapon->query("skill_type") != "sword" ) 
                 ||  me->query_skill_mapped("sword") != "huntian-jian" )     
             remove_effect(me);
         else if(me->query_temp("pfmxue_time")<1)
             remove_effect(me);                 
         else {  me->add_temp("pfmxue_time",-1);
                call_out("check", 1, me);
              }
                     
}


void remove_effect(object me)
{
        int skill = me->query_skill("xuanzong-force",1);
        if(!me) return;
        remove_call_out("check");
        me->delete_temp("pfmxue");
        me->set_temp("pfmxue_end",time());
        me->add_temp("apply/dodge",-skill/6);
        me->add_temp("apply/dodge");
        me->delete_temp("apply/sword");
        tell_object(me, GRN"你将玄宗心法收回丹田。\n"NOR);
}

void pfmxue_effect(object me, object victim)
{   int damage,ini_damage_apply,skill,ini_attack_apply;
    string str;
    skill = me->query_skill("huntian-jian",1)/2; 
   
   if ( random(2)>0 )
          { ini_damage_apply = me->query_temp("apply/damage");
            ini_attack_apply = me->query_temp("apply/attack");
            me->add_temp("pfmxue",1);
            message_vision(HIG"\n$N一剑落空，在半空中腰身一扭，向$n又攻出一招！\n"NOR,me,victim);
            me->add_temp("apply/damage",30);
            me->add_temp("apply/attack",skill);
            damage = COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));         
         
               
   if( damage <= 0 )
          {
          message_vision(HIG"\n$N的玄宗真气在体内迅速流转，手腕一扭，身随剑飘,在几乎不可能的角度再度出招！\n"NOR,me);
           me->add_temp("apply/damage",30);
           me->add_temp("apply/attack",skill);
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));         
           me->add_temp("pfmxue",-1);
           }             
    else me->add_temp("pfmxue",-1);
    
    me->set_temp("apply/damage",ini_damage_apply);
    me->set_temp("apply/attack",ini_attack_apply);
          }
}
 

