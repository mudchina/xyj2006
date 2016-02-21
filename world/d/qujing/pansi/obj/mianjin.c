// by snowcat 11/20/1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("烧面筋", ({"shao mianjin", "mianjin", "jin"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一碗烧得黑乎乎的面筋，看上去有点怪。\n");
    set("unit", "碗");
    set("value", 300);
    set("food_remaining", 4);
    set("food_supply", 50);
  }
}

void init ()
{
  add_action ("do_eat", "eat");
}

int do_eat (string arg)
{
  object who, me, ob;

  if( !arg || arg == "" )    return 0;

  who = this_player();
  me = this_object();
  ob = present (arg,who);

  if (ob != me)
    return 0;

  remove_call_out ("reacting");
  call_out ("reacting",2+random(4),who);    
  return ::do_eat(arg);
}

void reacting (object who)
{
  if (! who)
    return;

  message_vision("$N一阵子恶心，差点儿吐出来。\n",who);
}
