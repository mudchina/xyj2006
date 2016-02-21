// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
me->receive_wound("kee", 20);
me->receive_wound("sen", 20);
	me->set_temp("death_msg","蛇毒发作死了。\n");
	me->apply_condition("snake_poison", duration - 1);
	tell_object(me, HIG "你中的蛇毒发作了！\n" NOR );
	if( duration < 1 ) return 0;
	return 1;
}
