#include <weapon.h>

inherit AXE;

void create()
{
  set_name("Ëé¹Ç¸«", ({ "suigu fu", "fu", "axe" }) );
  init_axe(30);
  set("unit", "°Ñ");
  set_weight(1100);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "iron");
  }
  setup();
}

