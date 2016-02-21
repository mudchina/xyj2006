// ill_kesou.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "嘶哑着嗓子咳了两声，看来是病了。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "你嘶哑着嗓子咳了两声，然后又连续咳了好一阵，看来是病了不轻！\n" NOR );
      message("vision", me->name() + "的身子弓着身子晃了两晃，嘶哑着嗓子咳了两声，看来是病了。\n",
            environment(me), me);
   }
   me->receive_wound("kee", 1);
   me->receive_damage("kee", 1);
   me->apply_condition("ill_kesou", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

