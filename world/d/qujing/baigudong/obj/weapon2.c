#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("ÎÞÍ·½£", ({ "huazhu jian", "jian", "sword" }) );
  init_sword(35);
  set("unit", "°Ñ");
  set_weight(800);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 390);
    set("material", "iron");
  }
  setup();
}

