// moon_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("sen", duration);
	me->receive_damage("sen", duration);
	me->receive_damage("kee", duration);
	me->receive_wound("kee", duration);
	me->set_temp("death_msg","精力耗尽而死。\n");
	me->apply_condition("moon_poison", duration);
	if (duration >0 )
	tell_object(me, HIG "你感觉身体一点点虚弱下去！\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
