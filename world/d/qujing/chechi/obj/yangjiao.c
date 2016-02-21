// by snowcat oct 29 1997
#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("灰羊角", ({"hui yangjiao", "yangjiao"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一根灰色羊角。\n");
    set("unit", "根");
    set("value", 1000);
    set("wield_msg", "$N抓起一根$n当武器。\n");
    set("material", "bone");
  }
  init_hammer(1);
  setup();
}

