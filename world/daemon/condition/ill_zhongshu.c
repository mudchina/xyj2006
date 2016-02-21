// ill_zhongshu.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "头重脚轻，脑门发热，看来是中暑了。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "你觉得头重脚轻，脑门发热，看来是中暑了。\n" NOR );
      message("vision", me->name() + "只觉得胸臆之间一阵翻腾，头重脚轻，抬不起头来，脑门发热，看来是中暑了。\n",
            environment(me), me);
   }
   me->receive_wound("kee", 1);
   me->receive_damage("kee", 1);
   me->apply_condition("ill_zhongshu", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}

