#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("АўЦЄБо", ({ "bopi bian", "bian", "whip" }) );
  init_whip(35);
  set("unit", "Иљ");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "iron");
  }
  setup();
}

