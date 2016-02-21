// 回梦
// requirement: spells 180,moonshentong 120, mana 400, sen 20

inherit SSERVER;
#include <ansi.h>

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;

	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 180
	 || (int)me->query_skill("moonshentong",1) < 120)
		return notify_fail("你还没学会回梦咒。。。\n");
        if(me->query("family/family_name") != "月宫")
                return notify_fail("[回梦咒]是月宫不传之密！\n");
	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你想咒谁入梦？\n");  

	if((int)me->query("mana") < 400 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 20 )
		return notify_fail("你无法集中精力！\n");
  if (!living(target)) return notify_fail("有这个必要吗？\n");

	me->add("mana", -400);
	me->receive_damage("sen", 20);

	msg = HIM
		"$N凝视着$n的双眼，温柔地拍着$n的头，在$n耳边轻声唱着：“小宝宝，快睡觉。。。”\n"
		+"$n顿时觉得神倦眼困，全身无力。\n"NOR;

      success=1;
	ap = me->query_skill("spells");
	ap = ap * ap * ap /10 ;
	ap += (int)me->query("daoxing")/2;
	dp = target->query("daoxing");

      if (target->is_fighting(me)) dp=dp*2;
      if ( random(ap+dp)<dp ) success=0;
    
	ap = (int)me->query("mana");
	dp = (int)target->query("mana");
	if( random(ap + dp)<dp ) success = 0;

	if(success == 1 ){
		msg +=  HIM"$n不知不觉的哈欠连连，眼皮沉重，终于支持不住，合上了双眼。\n"NOR;
            message_vision(msg, me, target);

            target->set_temp("force_sleep",1);
   if(target->is_fighting()) target->command_function("surrender");
  if (!target->command("sleep")) message_vision(HIM"\n$N晃了晃脑袋，似乎清醒了不少，又把眼睛睁开了。\n"NOR,target);
            target->delete_temp("force_sleep");
		me->start_busy(1+random(2)); 
	}	    
	else {
		msg +=HIM"$n忽觉不妥，大喝一声，双目一张，精光四射！$N猝不及防，吓了一跳！\n" NOR;	
            message_vision(msg, me, target);
            if( living(target) ) target->kill_ob(me);
		me->start_busy(5+random(5));

	} 

	return 1;
}

