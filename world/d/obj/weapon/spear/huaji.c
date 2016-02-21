//sgzl 


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(HIY "方天画戟" NOR, ({ "fangtian huaji","huaji","ji" }));
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "杆");
    set("value", 10000);
    set("material", "blacksteel");
    set("long", "一杆镔铁打制的方天画戟。\n");
    set("wield_msg", "$N提起$n握在手中，威风凛凛。\n");
  }
  init_spear(40);
  setup();
}

