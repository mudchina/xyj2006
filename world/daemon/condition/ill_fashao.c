// ill_fashao.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "的脸蛋烧得通红，看来是发高烧了。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "你的脸蛋烧得通红，看来是发高烧了。\n" NOR );
      message("vision", me->name() + "的脸蛋烧得通红，看来是发高烧了。\n",
            environment(me), me);
   }
   me->receive_wound("kee", 1);
   me->receive_damage("kee", 1);
   me->apply_condition("ill_fashao", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

