#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("÷©Î²±Þ", ({ "manwei bian", "bian", "whip" }) );
  init_whip(25);
  set("unit", "¸ù");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "fish");
  }
  setup();
}

