//【蜀山派】mhxy-yushu 2001/2
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", HIR""+me->name() + "身中鹤顶红剧毒，看起来快要不行了。\n"NOR, environment(me), me);
   }
   else {
      tell_object(me, HIR "你身上的剧毒发作了。\n" NOR );
      message("vision", HIR""+me->name() + "身中鹤顶红剧毒，看起来快要不行了。\n"NOR,
            environment(me), me);
   }
   me->receive_wound("kee", 100);
   me->receive_damage("kee", 100);
   me->apply_condition("hedinghong_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
