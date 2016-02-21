#include <weapon.h>

inherit MACE;

void create()
{
  set_name("´Ì»±ïµ", ({ "cihuai jian", "jian", "mace" }) );
  init_mace(25);
  set("unit", "¸ù");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 240);
    set("material", "wood");
  }
  setup();
}

