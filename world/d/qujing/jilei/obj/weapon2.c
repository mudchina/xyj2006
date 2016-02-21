//Cracked by Roath
#include <weapon.h>

inherit FORK;

void create()
{
  set_name("Å£½Ç²æ", ({ "niujiao cha", "cha", "fork" }) );
  init_fork(35);
  set("unit", "¸ù");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 110);
    set("material", "bone");
  }
  setup();
}

