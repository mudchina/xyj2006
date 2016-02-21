
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIG "舍利子内丹" NOR , ({"shelizi neidan", "neidan", "dan"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗鸡蛋大的舍利子内丹，以数年打坐功之磨难，配了几转雌雄炼就而成。\n");
    set("value", 0);
    set("drug_type", "补品");
  }
  set("no_get","舍利子内丹岂能垂手而得！\n");
  set("no_give","舍利子内丹不可外传也！\n");
  set("no_drop","舍利子内丹不可遗失也！\n");
  set("no_sell","舍利子内丹无价之宝也。\n");
  set("is_monitored",1);
  setup();
}

void init()
{
  add_action("do_eat", "eat");
  call_out("destruct_me",3600);
}

int do_eat(string arg)
{
  object dan = this_object();
  object me = this_player();

  if (present(arg,me) != dan)
    return 0;
    
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  message_vision(HIG "$N将舍利子内丹含入嘴中咽下，一股仙气自丹田缓缓遍布全身了！\n" NOR, me);
  me->start_busy(5);
  destruct(dan);
  return 1;
}

void destruct_me ()
{
  message_vision("舍利子内丹变成粉末在风中吹散了！\n", this_object());
  destruct (this_object());
}
