// created by snowcat on 4/9/1997
// mabang.c

#include <weapon.h>

inherit STICK;

void create()
{
  set_name("大马棒", ({"mabang", "bang"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "根");
    set("value", 150);
    set("material", "wood");
    set("wield_msg", "$N卷起袖子，操起一根大马棒。\n");
  }
  init_stick(15);
  setup();
}


