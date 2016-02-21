// staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
  set_name( "竹杖", ({ "zhu zhang", "zhang", "staff" }) );
  set_weight(800); 
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "根");
    set("long", "一根长长的竹杖。\n");
    set("value", 100);
    set("material", "bamboo");
  }

  init_staff(10);
  setup();
}
