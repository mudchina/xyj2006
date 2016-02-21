#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("·Û¹Ç´¸", ({ "qingsho chui", "chui", "hammer" }) );
  init_hammer(30);
  set("unit", "°Ñ");
  set_weight(1500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "stone");
  }
  setup();
}

