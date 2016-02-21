#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
set_name(HIR "大红包" NOR, ({"hong bao", "hongbao"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
set("long", "过年了，大家的一点心意。\n");
    set("value", 5000);
    set("no_sell", 1);
  }
  
  setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
    
  if (!id(arg))
    return notify_fail("你要吃什么？\n");

message_vision(HIY"$N打开红包，拿出礼物，一下塞到肚子里。\n"NOR, me);  
  
	me->add("bellicosity", -random( (int)me->query_kar() * 10));
	if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);
me->add("potential", 500000);

  destruct(this_object());
  return 1;
}
