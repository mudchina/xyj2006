// by snowcat 11/22/1997

#include <armor.h>

inherit NECK;

void create()
{
  set_name("°×½ğÏîÈ¦", ({ "baijin xiangquan", "xiangquan", "neck" }));
  set("weight", 200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "¸ö");
    set("value", 3500);
    set("material", "gold");
    set("armor_prop/armor", 1);
  }
  setup();
}
