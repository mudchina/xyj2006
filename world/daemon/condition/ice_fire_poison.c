//ice_fire_poison.c

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", me->name() + "半身紫青，半身血红，痛苦地哼了一声。\n", environment(me), me);
   }
   else {   
      switch (random(2))
        {
         case 0:
              {
         tell_object(me, HIB "忽然一阵奇寒从丹田升起，沁入四肢百骸，你中的玄冰寒毒发作了！\n" NOR );
         message("vision", me->name() + "的脸青得可以滴出水来，牙关格格地响了起来。\n",environment(me), me);
               break;
               }
         case 1:
              {
         tell_object(me, HIR "忽然一股无名业火从丹田冒起，噬咬你的奇经八脉，你中的烈焰火毒发作了！\n" NOR );
      message("vision", me->name() + "的脸血一样的红，使劲抓着自己的脖子。\n",environment(me), me);
               break;
              } 
         }
         }
       me->receive_wound("kee",20 + random(10));
        me->receive_wound("sen", 20 + random(10));
      me->apply_condition("ice_fire_poison", duration - 1);
      if ( (int)me->query_temp("powerup") ) 
         { me->add_temp("apply/attack", - (int)(me->query_skill("force")/3));
             me->add_temp("apply/dodge", - (int)(me->query_skill("force")/3));
             me->delete_temp("powerup");  }

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}


