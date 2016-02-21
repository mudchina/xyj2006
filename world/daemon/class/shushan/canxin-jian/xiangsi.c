//xiangxi.c  
//created by DHXY-EVIL 2000.7.7
//Modified by vikee for xlqy-zq station 2000-12-5 9:05 .The CopyRight was keeped by DHXY-evil.

#include <ansi.h>
#include <combat.h>
#include <condition.h>
inherit SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「相思三剑」？\n");

        if(!me->is_fighting())
                return notify_fail("「相思三剑」只能在战斗中使用！\n");
        
        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("非蜀山不能用「相思三剑」！\n");
        
        if((int)me->query("faith") < 500 )
                return notify_fail("你的门派忠诚度不够！\n");
//if(me->query("shushan/ask_zuidao_go") !=1 )
//return notify_fail("没有伤心的体会，用不了缠绵的「相思三剑」！\n");
        
        if (me->query_skill_mapped("force")!="zixia-shengong")
        	return notify_fail("「相思三剑」必须以紫霞神功做底子！\n");
        	
        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
if((int)me->query_skill("zixia-shengong", 1) < 100)
                return notify_fail("你的紫霞神功修为还不够，使用这一招会有困难！\n");
 if((int)me->query_skill("canxin-jian", 1) < 100)
                return notify_fail("你的残心剑修为还不够，使用这一招会有困难！\n");
        message_vision(MAG"$N集思凝神，猛地施出残心剑的绝招「相思三剑」，向$n连续发动进攻！\n"NOR,me,target);
        me->set("xiangsi", 8);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	switch (random(4))
        {
         case 0:
              {
               message_vision(HIG"$n被剑意中的相思之苦感染，身中情毒！\n"NOR,me,target);
               target->apply_condition("xiangsi",20);
               break;
               }
         case 1:
              {
               message_vision(HIG"一股酒气冲向$n，$n似乎有了点酒意！\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              } 
         case 2:
              {
               message_vision(HIG"问世间情为何物？\n"NOR,me,target);
               message_vision(HIG"梦无痕，随风逝，仙灵如月长伴君．\n"NOR,me,target);  
               target->apply_condition("xiang_air",20);
               break;
              }
         case 3:
              {
               break;
              }
        }
	me->set("xiangsi", 9);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	switch (random(4))
        {
         case 0:
              {
               message_vision(HIG"$n被剑意中的相思之苦感染，身中情毒！\n"NOR,me,target);
               target->apply_condition("xiangsi",20);
               break;
              }
         case 1:
              {
               message_vision(HIG"一股酒气冲向$n，$n似乎有了点酒意！\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              }
         case 2:
              {
               message_vision(HIG"问世间情为何物？\n"NOR,me,target);
               message_vision(HIG"梦无痕，随风逝，仙灵如月长伴君．\n"NOR,me,target);
               target->apply_condition("xiang_air",20);
               break;
              }
         case 3:
              {
         break;
              }
        }
	me->set("xiangsi", 10);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	switch (random(4))
        {
         case 0:
              {
               message_vision(HIG"$n被剑意中的相思之苦感染，身中情毒！\n"NOR,me,target);
               target->apply_condition("xiangsi",20);
               break;
              }
         case 1:
              {
               message_vision(HIG"一股酒气冲向$n，$n似乎有了点酒意！\n"NOR,me,target);
               target->apply_condition("drunk",20);
               break;
              }
         case 2:
              {
               message_vision(HIG"问世间情为何物？\n"NOR,me,target);
               message_vision(HIG"梦无痕，随风逝，仙灵如月长伴君．\n"NOR,me,target);  
               target->apply_condition("xiang_air",20);
               break;
              }
         case 3:
              {
               break;
               }
        }
	me->delete("xiangsi");
        me->start_busy(1+random(2));
        message_vision(HIG"$N的「相思三剑」用功完毕，气回丹田,缓缓收功.\n"NOR,me,target);
        message_vision(msg,me,target);
        me->add("kee", -50);
        me->add("force", -100);
        me->add("sen",-50);
        return 1;
}
