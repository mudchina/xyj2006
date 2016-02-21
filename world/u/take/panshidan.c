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
 set_name(YEL "判师丹" NOR,({"panshi dan","dan"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "黄橙橙的一颗小丹丸，带着一股神秘的气味。\n");
     set("value", 50000000);
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
me->delete("betray");
me->delete("betrayer");
me->add("combat_exp",-(me->query("combat_exp")/4));
me->add("daoxing",-(me->query("daoxing")/4));
  message_vision(HIG "$N一口吞下丹丸，全身不停的颤抖，慢慢的$N又恢复了元气。 \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
