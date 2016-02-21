// mihoutao.c 猕猴桃

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
//   set("no_get","你手里一松"+this_object()->query("name")+"丹从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(YEL "猕猴桃" NOR, ({"mihou tao","mihoutao","tao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "黄橙橙的一颗猕猴桃，真叫人垂涎欲滴。\n");
    set("value", 5000);
    set("drug_type", "补品");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->add_maximum_force(1);
  me->add_maximum_mana(1);
  message_vision(HIG "$N吃下一颗弥猴桃，忍不住抓耳挠腮，高兴得直想翻跟头！ \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
