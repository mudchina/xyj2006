//Cracked by Roath
#include <weapon.h>

inherit WHIP;

void create()
{
  set_name("Å£Æ¤±Þ", ({ "niupi bian", "bian", "whip" }) );
  init_whip(35);
  set("unit", "¸ù");
  set_weight(600);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 320);
    set("material", "skin");
  }
  setup();
}

