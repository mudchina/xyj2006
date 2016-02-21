// snowcat 4/25/97

#include <weapon.h>

inherit THROWING;

void self_dest()
{
    object env=environment(this_object());
    if(env)
        tell_object(env, name()+"慢慢的裂开，随风化去了。\n");
    destruct(this_object());
}

void create()
{
  set_name("●金丹砂●", ({"jindan sha", "sha"}));
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一些闪闪发光的金丹砂。\n");
    set("unit", "些");
    set("base_unit", "颗");
    set("base_weight", 40);
    set("base_value", 1);
  }
  set("is_monitored",1);
  set_amount(18);
  set("rigidity",100);
  init_throwing(180);
  call_out("self_dest",600+random(600));
  setup();
}


