//火魂
//requirement:huomoforce,huoyun-qiang all over 60

#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void remove_effect(object me, object target, int amount);
 
int perform(object me, object target)
{
        int skill_spear, skill_force, str_amount,attack_amount;
        if(me->query("family/family_name")!="火云洞")
return notify_fail("「火魂」只有火云洞门人才可以用！\n");

        if( !me->is_fighting() )
                return notify_fail("「火魂」只能在战斗中使用。\n");
               if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("「火魂」必须配合火魔心法才能使用。\n");
        skill_force=me->query_skill("huomoforce",1);        
        if (skill_force<60) return notify_fail("你的火魔心法不够纯熟。\n");
        skill_spear=me->query_skill("huoyun-qiang",1);
        if (skill_spear<60) 
           return notify_fail("你的枪法太差劲了。\n"); 
        if( (int)me->query("force") < 200 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("shenli") )
                return notify_fail("你已经在运功中了。\n");
        
        me->add("force", -100);
        message_vision(
                HIR"$N哞的一声吼，一提丹田气，运力于臂，枪上加力。只见$N四周烈火重重，\n火焰像一条巨龙一样蜿蜒在枪上,如此的气势吓的敌手心惊丹寒\n" NOR, me);
 
        attack_amount=skill_spear/5;
        str_amount=(skill_spear+random(skill_force))/5; 
        me->add_temp("apply/attack", attack_amount);  
        me->add_temp("apply/strength",str_amount);    
        me->set_temp("shenli", 1);
              me->start_busy(2);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", 
           me, str_amount,attack_amount:), skill_spear/5);
 
         return 1;
}
 
void remove_effect(object me, int str_amount,int attack_amount)
{
        me->add_temp("apply/strength", -str_amount);
        me->add_temp("apply/attack", -attack_amount);
        me->delete_temp("shenli");
        message_vision(HIR"$N收回力道，像火一样的巨龙消失了。\n"NOR,me);
}


