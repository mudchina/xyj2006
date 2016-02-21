//舞雪
//requirement:force,dodge,sword all over 100

#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void remove_effect(object me, object target, int amount);
 
int perform(object me, object target)
{
        int skill_sword, skill_dodge, dodge_amount,attack_amount;
        if(me->query("family/family_name") != "月宫")
                return notify_fail("[舞雪]是月宫不传之密！\n");

        if( me->query_skill_mapped("dodge") != "moondance" )
                return notify_fail("你还没有施展冷月凝香舞呢。\n");
        skill_dodge = me->query_skill("dodge");            
        if (skill_dodge<100) return notify_fail("你舞技还不够高明。\n");
        if (me->query_skill_mapped("force")!="moonforce")
                return notify_fail("舞雪必须配合圆月心法才能使用。\n");
        skill_sword=me->query_skill("force");        
        if (skill_sword<100) return notify_fail("你的圆月心法不够纯熟。\n");
        skill_sword=me->query_skill("sword");
        if (skill_sword<100) 
           return notify_fail("你的剑术太差劲了。\n"); 
        if( (int)me->query("force") < 50 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") )
                return notify_fail("你已经在运功中了。\n");
        
        me->add("force", -50);
        message_vision(
                HIW"$N略一提气，运起轻功，拔剑起舞。只见$N足不沾地，手中剑越舞越快，逐渐幻做一团白雾，满堂滚动。\n" NOR, me);
 
        attack_amount=skill_sword*random(6)/10;
        dodge_amount=skill_dodge*(5+random(6))/10; 
        me->add_temp("apply/attack", -attack_amount);  
        me->add_temp("apply/dodge",dodge_amount);  //trade offense for defense.  
        me->set_temp("powerup", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", 
           me, dodge_amount,attack_amount:), skill_sword/5);
 
         return 1;
}
 
void remove_effect(object me, int dodge_amount,int attack_amount)
{
        me->add_temp("apply/dodge", -dodge_amount);
        me->add_temp("apply/attack", attack_amount);
        me->delete_temp("powerup");
        message_vision(HIW"$N渐感气力不支，不得不放慢脚步，放缓剑招。\n"NOR,me);
}

