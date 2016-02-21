#include <ansi.h>
inherit ITEM;
void create()
{
  set_name("八卦符", ({"bagua fu", "fu",}));
  set_weight(100);
  set("unit", "张");
  set("value", 0);
  setup();
}
void init()
{
  object me = this_object();
  object who = this_player();
  object where = environment();
  add_action("do_direct","direct");
  if (! me->query("my_owner") &&
      interactive (who))
    me->set("my_owner",who->query("id"));
   
     if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
    
}

void destruct_me(object where, object me)
{
  message_vision("千面怪鬼鬼祟祟地拿起$n撒脚就跑，快追！\n",where,me);
  destruct (me);
}


int do_direct (string arg)
{
  object me = this_player();
  
  if (!arg) return notify_fail("用法：direct <direction>\n");
  write ("你用朱笔在八卦符上写下 "HIR+arg+ NOR" 。\n");
  set("dir",arg);
  return 1;
}
