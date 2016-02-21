// ill_shanghan.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "冷不丁打了个冷战，头昏沉沉的，好象是得伤寒病了。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "打了个冷战，头昏沉沉的，好象是得伤寒病了！\n" NOR );
      message("vision", me->name() + "冷不丁打了个冷战，头昏沉沉的，好象是得伤寒病了。\n",
          environment(me), me);
   }
   me->receive_wound("kee", 1);
   me->receive_damage("kee", 1);
   me->apply_condition("ill_shanghan", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

