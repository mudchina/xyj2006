
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_sell","这种果子值几个钱，卖了也没花头。\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name( GRN "野李子" NOR , ({"lizi", "guo"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗青色的果实，看上去还不是很成熟。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="guo" && arg!="lizi")	return 0;
  
  me->set("sen", (int)me->query("max_sen"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  message_vision(HIG "$N把李子一咬，哇，又酸又甜，味道真好。$N精神一振，路途的辛苦感觉都没了。\n" NOR, me);
  destruct(this_object());
  return 1;
}

