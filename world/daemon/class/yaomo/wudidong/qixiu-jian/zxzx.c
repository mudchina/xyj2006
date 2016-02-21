// zxzx.c
//write by yesi
//yeahsi@21cn.com

#include <ansi.h>
inherit SSERVER;

void check(object me);
void zxzx_effect(object me, object victim);
void remove_effect(object me);

int perform(object me)
{
        int skill;
        int sword_skill,qixiu_skill;
        
        skill = me->query_skill("huntian-qigong",1);
        if( skill > 250 ) skill=250;
        sword_skill= me->query_skill("sword",1);
        qixiu_skill= me->query_skill("qixiu-jian",1);
                       
                               
        if( skill < 100 )  return notify_fail("你的混天气功修为不够。\n");
        if( sword_skill < 100 )  return notify_fail("你的基本剑法未够纯熟。\n");
        if( qixiu_skill < 160 )  return notify_fail("你的七修剑未够纯熟。\n");
        
        if( me->query_temp("zxzx") ) 
          {remove_effect(me);return 1;}
          
        if (me->query_skill_mapped("force")!="huntian-qigong")
            return notify_fail("「追腥逐血」必须配合混天气功才能使用。\n");
        
        if(me->query("family/family_name") != "陷空山无底洞")
               return notify_fail("[追腥逐血]是陷空山无底洞不传之密！\n");     
        
        if( time()-(int)me->query_temp("zxzx_end") < 10 )
                return notify_fail("你现在真气不纯！\n");       
               
        
        if( (int)me->query("force") < skill )     
                return notify_fail("你的内力不够。\n");
 
        me->add("force", -skill);
        message_vision(HIR "$N把混天气功在体内运行一周，只觉浑身杀气腾腾，看谁都不顺眼。\n" NOR, me);
        me->set_temp("zxzx", 1);
        me->set_temp("zxzx_time",skill);
                   
        call_out("check", 1, me);
        return 1;
}


void check(object me)
{       
        object weapon;
        
         if(!me) return;
                
         if (me->query_skill_mapped("force") != "huntian-qigong"
                 || !objectp(weapon=me->query_temp("weapon")) 
                 || (weapon->query("apply/skill_type") != "sword" 
                     && weapon->query("skill_type") != "sword" ) 
                 ||  me->query_skill_mapped("sword") != "qixiu-jian" )     
             remove_effect(me);
         else if(me->query_temp("zxzx_time")<1)
             remove_effect(me);                 
         else {  me->add_temp("zxzx_time",-1);
                call_out("check", 1, me);
              }
                     
}


void remove_effect(object me)
{
        if(!me) return;
        remove_call_out("check");
        me->delete_temp("zxzx");
        me->set_temp("zxzx_end",time());
        tell_object(me, GRN"你将混天气功收回丹田。\n"NOR);
}

void zxzx_effect(object me, object victim)
{   int damage,ini_damage_apply;
    string str;

   if ( random(2)>0 )
          { ini_damage_apply = me->query_temp("apply/damage");
            me->add_temp("zxzx",1);
            message_vision(HIR"\n$N一剑中敌，双目精光四谢，发狂般向$n又攻出一招！\n"NOR,me,victim);
            me->add_temp("apply/damage",15);
            damage = COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));         
         
               
   if( damage > 0 )
          {
           message_vision(HIR"\n$N看到敌人伤口上滴着的血，状近疯狂，居然在不可能的情况下又再攻出一招！\n"NOR,me);
           me->add_temp("apply/damage",15);
           COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));         
           me->add_temp("zxzx",-1);
           }             
    else me->add_temp("zxzx",-1);
    
    me->set_temp("apply/damage",ini_damage_apply);
          }
}
 
