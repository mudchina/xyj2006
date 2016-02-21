#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("Æß³Ý°Ò", ({ "qichi pa", "pa", "rake" }) );
  init_rake(35);
  set("unit", "¸ù");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 310);
    set("material", "metal");
  }
  setup();
}

