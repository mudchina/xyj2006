// rou.c 	取经人肉

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(YEL "取经人肉" NOR, ({"qujingren rou","renrou","rou"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "天下的至宝,吃了可以长生不老,还可以增加法术。\n");
    set("value", 5000);
    set("drug_type", "补品");
  }

  set("is_monitored",1);  
  setup();
}

int do_eat(string arg)
{
  object who = this_player();
  
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
//  me->set("food", (int)me->max_food_capacity());
  who->delete("no_qujing");
  destruct(this_object());
  return 1;
}

