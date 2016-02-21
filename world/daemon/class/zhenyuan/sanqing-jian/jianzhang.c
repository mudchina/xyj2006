//剑掌
// write by yesi
//yeahsi@21cn.com

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
      object weapon=me->query_temp("weapon");
      int enhance,damage;
      string str;

      if (!weapon) return 0;
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要攻击谁？\n");
      if (!me->is_fighting())
             return notify_fail("剑掌只能在战斗中使用！\n");
      
     if( time()-(int)me->query_temp("jianzhang_end") < 3 )
                return notify_fail("绝招用多就不灵了！\n");
     
     if (me->query_temp("jianmang"))
           return notify_fail("你正在施用剑芒，没有余力出剑掌！\n");
           
     if( time()-(int)me->query_temp("jianmang_end") < 5 )
                   return notify_fail("你现在真气不纯。\n");      
     //if(me->query("family/family_name") != "五庄观")
       //         return notify_fail("[剑掌]是五庄观不传之密！\n");
                
     if (me->query_skill("sanqing-jian",1)<100)
          return notify_fail("你的三清剑法太差，还不会出剑掌。\n");
      if (me->query_skill("wuxing-quan",1)<100) 
          return notify_fail("你的五行拳太差，还不会出剑掌。\n");
    if (me->query_skill("zhenyuan-force",1)<60)
        return notify_fail("你的镇元神功修为不够，还不会出剑掌。\n");
     if (me->query_skill_mapped("force")!="zhenyuan-force")
            return notify_fail("剑掌必须配合镇元神功才能使用。\n");
     if (me->query_skill_mapped("unarmed")!="wuxing-quan")
            return notify_fail("剑掌必须配合五行拳才能使用。\n");
      if (me->query("force")<100)
           return notify_fail("你内力不继，难以出招。\n");
     
    me->add("force", -100);
    seteuid(getuid());
    me->set("actions", (: call_other, SKILL_D("wuxing-quan"), "query_action" :) );
   
    message_vision(HIC"\n$N运起镇元神功，没等招式用老，脚踏八卦，身形一下转过一边，紧接着收剑出掌。\n"NOR,me);
    //weapon->unequip();
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","unarmed");
    enhance=me->query_skill("wuxing-quan",1);
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("zhenyuan-force",1);
    damage=damage/2;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    //weapon->wield();
    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+"被"+me->name()+"用五庄观绝招「剑掌」打死了，在满身剑痕中还浮现几个乌黑的掌印！";
	                 message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
	               }
    me->reset_action();
    me->set_temp("jianzhang_end",time());
    return 1;
}



