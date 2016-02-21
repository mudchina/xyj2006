#include <ansi.h>

inherit SSERVER;
//inherit F_CLEAN_UP;

int perform(object me, object target)
{
        object weapon;
int i,j,k,damage;
weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要攻击谁？\n");

        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");
		   if(me->query("family/family_name")!="火云洞")
           return notify_fail("“不悔”只有火云洞门人才可以用！\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内功太差。\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

	if((int)me->query_skill("pingtian-dafa", 1) < 100)
        	return notify_fail("你的平天大法等级不够，不能使用这一招！\n");
	i=(int)me->query("combat_exp");
       j=(int)target->query_("combat_exp");
            k=(int)me->query_skill("spear");
                  if(k<100)        
                return notify_fail("你的 枪法级别还不够，使用这一招会有困难！\n");

        me->delete("env/brief_message");
	target->delete("env/brief_message");
message_vision(HIM"\n$N一挺手中"+weapon->name()+NOR+HIB"直刺$n！\n"NOR,me,target);
if (random(i)>random(j)) {
            damage=k+(int)me->query("str");
	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/5);
	 COMBAT_D->report_status(target);
}
else if (random(i)> random(j)) {
              message_vision(HIM"\n$N一枪刺空，又是一肘，仍击向$n！\n"NOR,me,target);
            damage=k+random(k)+(int)me->query("str");
	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/5);
	 COMBAT_D->report_status(target);
}
else if (random(i)> random(j)) {
              message_vision(HIM"\n$N一枪刺空，又是一肘，仍击向$n！\n"NOR,me,target);
              message_vision(HIM"\n$N一肘又空，但仍不收着，一头撞向$n！\n"NOR,me,target);
damage=k+random(k)*2+(int)me->query("str");
	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/5);
	 COMBAT_D->report_status(target);
}
else if (random(2)) {
              message_vision(HIM"\n$N一枪刺空，又是一肘，仍击向$n！\n"NOR,me,target);
              message_vision(HIM"\n$N一肘又空，但仍不收着，一头撞向$n！\n"NOR,me,target);
            message_vision(HIM"\n$N一头虽然撞空，但$n也被这拼命的举动吓了一跳！\n"NOR,me,target);
     	target->start_busy(5);
}
else {
              message_vision(HIM"\n$N一枪刺空，又是一肘，仍击向$n！\n"NOR,me,target);
              message_vision(HIM"\n$N一肘又空，但仍不收着，一头撞向$n！\n"NOR,me,target);
            message_vision(HIW"\n$n哈哈大笑，只逞匹夫只勇又有何用，轻松避开\n"NOR,me,target);
}

me->receive_damage("sen", 50);
        me->add("force", -100-(int)me->query("force_factor"));
	me->receive_damage("kee", 30); 
if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
}
me->start_busy(1+random(2));
        return 1;
}
