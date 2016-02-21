
//

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name("壳", ({ "shell" }));
  set_weight(8000);
  set("long", "这是一只正在风化的虫壳。\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("material", "bone");
  }
  setup();
}

void init ()
{
  object me = this_object();
  if (me->query("is_disappearing"))
    return;
  me->set("is_disappearing",1);
  call_out ("disappear",20,this_object());
}

void disappear (object me)
{
  destruct (me);
}

