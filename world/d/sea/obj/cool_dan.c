#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
  set_name(HIC "±ÌË®µ¤" NOR, ({"bishui dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "¿Å");
    set("long", "±ÌÓÍÓÍµÄÒ»¿Å±ÌË®µ¤¡£\n");
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
    return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");

	message_vision(HIC"$N³ÔÏÂÒ»¿Å±ÌË®µ¤£¬Á³É«±äµÄÒ»Æ¬²Ò°×¡£\n"NOR, me);  
  
	me->add("bellicosity", -random( (int)me->query_kar() * 10));
	if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);
	me->add("potential", 100);

  destruct(this_object());
  return 1;
}
