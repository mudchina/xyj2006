#include <weapon.h>

inherit SWORD;

void create()
{
  set_name("×ÏÔÆ½£", ({ "ziyun jian", "jian", "sword" }) );
  init_sword(45);
  set("unit", "°Ñ");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 420);
    set("material", "metal");
  }
  setup();
}

