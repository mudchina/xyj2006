//Cracked by Roath
//xiangsi.c
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", HIR""+me->name() + "身中情毒，痛苦的按着胸口．\n"NOR, environment(me), me);
   }
   else {
      tell_object(me, HIR "情毒发作了。\n" NOR );
      message("vision", HIR""+me->name() + "身中情毒，痛苦的按着胸口．\n"NOR,
            environment(me), me);
   }
   me->receive_wound("kee", 100);
   me->receive_damage("kee", 100);
   me->apply_condition("xiangsi", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
