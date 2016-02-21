// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{

	if ( !target
      ||      !userp(target)
      ||      target->is_corpse()
      ||      target==me)
		return notify_fail("你想替谁解除蚀月咒？\n");
        if(me->query("family/family_name") != "月宫")
                return notify_fail("这是月宫不传之密！\n");
	if (!target->query_condition("moon_poison"))
        return notify_fail("没中蚀月咒瞎搅和什么！\n");
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if( (int)me->query("force") - (int)me->query("max_force") <  600 )
		return notify_fail("你的真气不够。\n");

    if ((int)me->query_skill("moonforce",1)<80)
		return notify_fail("你的内功修为不足以替人解除蚀月咒。\n");
    if ((int)me->query("faith")<500)
                return notify_fail("你的门忠还没有学会蚀月咒。\n");
	
	message_vision(
		HIY "$N坐了下来默默的念起经来，$n听$N语音清脆，越念越是冲和安静，全身隐隐发出圣洁的光辉。\n\n"NOR,
		me, target );
    if (random(me->query_skill("moonforce", 1)-60)>10){
		target->apply_condition("moon_poison",0);
		message_vision(
		HIY "$N诵经的声音越来越柔和，$n心中既感激，又安慰，在那温柔虔诚的念经声中入了睡乡。\n"NOR,
		me, target );
		target->set_temp("force_sleep",1);
		target->command_function("sleep");

		target->delete_temp("force_sleep");	}
	else {
		message_vision(
		HIY "$N突然脸色苍白，似乎体力不支，竟呕出一口血来……\n"NOR,
		 me, target );
	}	
 
	target->receive_cuiring("kee", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -150);
	me->set("force_factor", 0);
	return 1;
}
