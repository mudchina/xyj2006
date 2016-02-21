#include <weapon.h>

inherit STICK;

void create()
{
  set_name("ÉÕ»ð¹÷", ({ "shaohuo gun", "gun", "stick" }) );
  init_stick(15);
  set("unit", "¸ù");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 100);
    set("material", "bone");
  }
  setup();
}

