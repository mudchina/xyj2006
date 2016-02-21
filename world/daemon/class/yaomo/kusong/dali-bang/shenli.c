// modified by vikee for xlqy
// 2000-11-26 16:05


#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{	
        int strength,howlong,str;
	object weapon=me->query_temp("weapon");
      	mapping action;        
	
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("你要攻击谁？\n");
	  	if(me->query("family/family_name")!="火云洞")
return notify_fail("“天赐神力”只有火云洞门人才可以用！\n");
      if( (int)me->query_str() < 20 )
                return notify_fail("你臂力太差, 无法使用「天赐神力」。\n");   
      if (!target->is_fighting(me))
             return notify_fail("你们没有在打架！\n");
      if ((int)me->query_skill("force",1)<60)
          return notify_fail("你的内功太差。\n");
      if ((int)me->query_skill("dali-bang",1)<60)
         return notify_fail("你大力棍法火候不够。\n");
      if (me->query("force")<500)
           return notify_fail("你内力不继，难以出招。\n");
      if (me->query_temp("pfm_shenli")) return notify_fail("你已经被赐于神力了。\n");
	me->add("force",-100);
	message_vision(HIW"$N突然举起手中"NOR+weapon->name()+
	HIW"向天高喊一声「天赐神力」!\n"NOR,me,target);
	me->add("sen",-100);

        howlong=me->query_skill("dali-bang")/2;

	//  strength=me->query_temp("apply/strength");
	me->add_temp("apply/strength",me->query_skill("dali-bang",1)/2);
	call_out("remove_ansi",howlong,me,str);
	me->set_temp("pfm_shenli",1);
    	me->set("actions",action);
    	me->reset_action();
	return 1;
}


int remove_ansi(object me,int strength)
{	object here;
	me->add_temp("apply/strength",-me->query_skill("dali-bang",1)/2);
	me->delete_temp("pfm_shenli");
	message_vision(HIW"$N发觉神力正慢慢离开！\n"NOR,me);
	return 1;	
}
