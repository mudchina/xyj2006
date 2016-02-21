// fake-tao.c 猕猴桃干

#include <ansi.h>

inherit ITEM;
void init()
{
object me = this_object();
  object who = this_player();
  object where = environment();
  if (!wizardp(this_player())) {
set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
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
call_out("destroy_me",120,where,me);
  }                                                            

}

void destruct_me(object where, object me)
{
  message_vision("千面怪鬼鬼祟祟地拿起$n撒脚就跑,快追!\n",where,me);
  destruct (me);
}
void create()
{
  set_name(HIY"珍贵药材"NOR, ({"zhengui yaocai","yaocai"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "株");
    set("long", "一株珍贵药材，如果炼成丹药有强身健体延年益寿的功效。\n");
    set("canoe",1); // 身份鉴定,防止假药材
    set("value", 0);
	set("drug_type", "补品");
  }
  
  setup();
}
