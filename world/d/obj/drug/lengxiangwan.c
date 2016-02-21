
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "冷香丸" , ({"lengxiang wan", "wan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗龙眼大的药丸，有健脾开胃，增进消化之效。\n");
    set("value", 800);
    set("no_sell", 1);
    set("drug_type", "补品");
  }
  setup();
  call_out("self_dest",600);
}

void self_dest()
{
    object env;
    if(this_object()) {
	if(env=environment(this_object()))
	    tell_object(env,name()+"掉在地上不见了。\n");
	destruct(this_object());
    }
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  int food,water;
  object me = this_player();
  if (arg!="lengxiang wan" && arg!="wan") 
    return 0;
  
  food=(int)me->max_food_capacity()/2+random(120)-60;
  water=(int)me->max_water_capacity()/2+random(120)-60;
  if (me->query("food")>food) me->set("food",food);
  if (me->query("water")>water) me->set("water",water);

  message_vision(HIG "$N捏起一颗冷香丸送进嘴里吞下。\n" NOR, me);
  tell_object(me, HIG"顿时你觉得一股清凉之气，在五脏六腑中游走，所到之处，说不出的舒坦！\n"NOR);
  destruct(this_object());
  return 1;
}
