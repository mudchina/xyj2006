#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
  object env;
   object target;

  if( me->is_ghost() )
    return notify_fail("做了鬼了，就老实点吧！\n");

  if( me->is_fighting() )
    return notify_fail("战斗中不能应战。\n");

  if (!me->query_temp("ask_yingzhan"))
    return notify_fail("你没有应战的任务。\n");

    message_vision("$N消失在一团烟雾之中。\n",me);
  me->move(me->query_temp("yingzhan_place"));
  message_vision("$N出现在大家的面前。\n",me);
  target=me->query_temp("yingzhan_man");
  message_vision("$N对$n大喝一声："+RANK_D->query_rude(target)+"敢到我们的地头上来捣乱！\n",me,target);
  me->kill_ob(target);
  target->kill_ob(me);
  me->delete_temp("yingzhan_man");
  me->delete_temp("no_move");
me->delete_temp("ask_yingzhan");
  me->delete_temp("yingzhan_place");
  me->set_temp("in_tiaozhan",1);
  return 1;
}

int help(object me)
{
write(@HELP
指令格式 : yingzhan

这个指令让你到指定的地点应战。

HELP
    );
    return 1;
}


