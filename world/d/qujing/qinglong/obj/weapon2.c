#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("狐骨刺", ({ "hugu ci", "ci", "dagger" }) );
  init_dagger(11);
  set("unit", "根");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 180);
    set("material", "bone");
  }
  set("wield_msg","$N操起$n握在手里。\n");
  setup();
}

