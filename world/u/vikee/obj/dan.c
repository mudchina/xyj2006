#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();
void init()
{
  if (!wizardp(this_player())) {
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}
void create()
{
  set_name( HIG "天王护心丹" NOR , ({"tianwang dan", "dan"}));
  set_weight(90);
if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗淡青色的丹丸，是名贵的药材炼制而成。\n");
    set("value", 100000);
    set("drug_type", "补品");
  }
  setup();
}
int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="yun dan")     return 0;
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", ((int)me->query("max_mana"))*2);
  me->set("force", ((int)me->query("max_force"))*2);
  me->set("food", ((int)me->max_food_capacity())*3);
  me->set("water", ((int)me->max_water_capacity())*3);
  message_vision(HIG "$N从怀里小心翼翼的拿出一颗，送入嘴中，果然见$N脸上慢慢泛出红光，法力和内力到了极限！\n" NOR, me);
  destruct(this_object());
  return 1;
}
