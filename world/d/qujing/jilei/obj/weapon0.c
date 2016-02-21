//Cracked by Roath
#include <weapon.h>

inherit STICK;

void create()
{
  set_name("Å£¹Ç°ô", ({ "niugu bang", "bang", "stick" }) );
  init_stick(25);
  set("unit", "¸ù");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 70);
    set("material", "bone");
  }
  setup();
}

