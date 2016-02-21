//Cracked by Roath
//bellicosity
//火魂

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int remove_ansi(object target,object me,int damage,int enhance);

int perform(object me, object target)
{       
        int damage,howlong,enhance;
        object weapon=me->query_temp("weapon");
        mapping action;        
        
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要攻击谁？\n");
      if (!target->is_fighting(me))
             return notify_fail("只有在战斗中才可以使用「火魂」！\n");
      if (me->query_skill("force")<100)
          return notify_fail("你的内功修为不够。\n");
      if (me->query_skill("huomoforce",1)<50)
         return notify_fail("你火魔心法火候不够。\n");
      if (damage=me->query_skill("spear")<80) 
          return notify_fail("你的抢法还欠火候。\n");
      if (me->query("force")<500)
           return notify_fail("你内力不继，难以出招。\n");
     
      if (me->query("sen")<500)
           return notify_fail("你气血不足，难以出招。\n");
      if (me->query_temp("pfm_huohun")) return notify_fail("你已经七窍生烟了。\n");
        me->add("force",-200);
        message_vision(HIR"$N突然用手在自家鼻子上锤了两拳，口中喷出火来，手中"NOR+weapon->name()+
        HIR"顿时间红光上涌，焚天炙地，神龙吐信般飞速向$n舞来。\n"NOR,me,target);
        me->add("sen",-100);
        
        howlong=me->query_skill("spear")/5;
        


        me->set_temp("pfm_huohun",1);
        

        enhance=me->query_skill("huomoforce",1)/2;
        me->add_temp("apply/attack", enhance);  
        damage=me->query_skill("huoyun-qiang",1)/2;
        if (damage>150) damage=100;
        action=copy(me->query("actions"));
        damage=action["damage"]*damage/20;
        me->add_temp("apply/damage",damage);
        me->set("actions",action);
        COMBAT_D->do_attack(me, target, weapon);
        me->reset_action();
        me->start_busy(1+random(2));
        call_out("remove_ansi",howlong,target,me,damage,enhance);
        return 1;
}


int remove_ansi(object target,object me,int damage,int enhance)
{       object here;
        string arg;
        if (!me) return 1;
        here=environment(me);
        me->delete_temp("pfm_huohun");
        me->add_temp("apply/attack",-enhance);
        me->add_temp("apply/damage",-damage);
        arg="$N的脸色渐渐的恢复了正常";
        if(me->is_fighting(target)) arg+="，攻势也缓和了许多";
        message_vision(arg+"！\n",me);
        return 1;       
}

