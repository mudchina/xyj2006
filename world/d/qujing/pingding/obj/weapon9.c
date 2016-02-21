#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("Å£½ÇÈÐ", ({ "niujiao ren", "ren", "dagger" }) );
  init_dagger(20);
  set("unit", "°Ñ");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "iron");
  }
  setup();
}

