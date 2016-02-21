// by snowcat 11/22/1997
#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("绣花针", ({"xiuhua zhen", "zhen", "needle"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("long", "一根星光闪闪的绣花针。\n");
    set("wield_msg", "$N拔出一根绣花针，捏在手里。\n");
    set("unwield_msg", "$N将绣花针藏起。\n");
  }
  set("is_monitored",1);
  init_sword(3);
  setup();
}

void destruct_me(object where, object me)
{
  message_vision("$n突然掉在地上不见了！\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

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

