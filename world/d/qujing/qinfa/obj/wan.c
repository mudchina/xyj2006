// by snowcat 12/2/1997

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "辟谷丸" , ({"pigu wan", "wan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗橙黄色的辟谷丸。\n");
    set("value", 1000);
    set("no_sell", 1);
    set("drug_type", "补品");
  }
  setup();
  call_out ("becoming_old",1800);
}

void becoming_old ()
{
  object me = this_object();
  object where = environment (me);
  object wan = new (__DIR__"wanbad");

  wan->move(where);
  destruct (me);
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="pigu wan" && arg!="wan") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*3+random(100));
  me->set("water", (int)me->max_water_capacity()*3+random(100));
  message_vision(HIG "$N捏起一颗小小的辟谷丸往舌下一放。\n" NOR, me);
  tell_object(me, "顿时你觉得口中生津，一股仙气自上而下如醍醐灌顶。\n");
  destruct(this_object());
  return 1;
}

