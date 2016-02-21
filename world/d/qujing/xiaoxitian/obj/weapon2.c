#include <weapon.h>

inherit FORK;

void create()
{
  set_name("ÇàÍ­²æ", ({ "qingtong cha", "cha", "fork" }) );
  init_fork(40);
  set("unit", "¸ù");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 360);
    set("material", "bone");
  }
  setup();
}

