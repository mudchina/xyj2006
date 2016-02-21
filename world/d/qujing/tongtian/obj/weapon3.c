#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("Ê¯Äµ´¸", ({ "shimu chui", "chui", "hammer" }) );
  init_hammer(25);
  set("unit", "°Ñ");
  set_weight(800);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 230);
    set("material", "shell");
  }
  setup();
}

