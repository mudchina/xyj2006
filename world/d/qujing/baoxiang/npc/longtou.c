// staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
  set_name( "龙头拐", ({ "long tou guai", "long tou", "guai", "staff" }) );
  set_weight(800); 
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("long", "一根长长的龙头拐杖。\n");
    set("value", 100);
    set("material", "bamboo");
  }

  init_staff(10);
  setup();
}
