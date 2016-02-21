#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("·¨´¸", ({ "fa chui", "chui", "hammer" }) );
  init_hammer(25);
  set("unit", "°Ñ");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "metal");
  }
  setup();
}

