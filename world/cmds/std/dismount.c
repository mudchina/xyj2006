// by snowcat feb 4 1998

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object who, string arg)
{
  object me;
  object where = environment(who);

  if (! arg ||
      ! where ||
      ! (me = present(arg,where)) ||
      ! me->query("ride/msg"))
    return notify_fail ("你想从什么上下来？\n");

  if (me != who->query_temp("ridee"))
    return notify_fail ("你并没有"+me->query("ride/msg")+"在"+me->name()+"上。\n");
      
  message_vision ("$N挺身从$n上跃下来。\n",who,me);
  me->set_temp("no_return",0);
  me->set_temp("rider",0);
  who->set_temp("ridee",0);          
  who->add_temp("apply/dodge",-who->query_temp("ride/dodge"));
  who->set_temp("ride/dodge",0);
  return 1;
}

int help(object me)
{
    write(@HELP
指令格式 : mount <坐骑名称>

这个指令可以让你从坐骑上下来。

HELP
);
  return 1;
}
