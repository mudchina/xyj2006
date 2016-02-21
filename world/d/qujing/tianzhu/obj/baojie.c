#include <armor.h>

inherit FINGER;

void create()
{
  set_name("±¦Ê¯½äÖ¸", ({ "bao jie", "baojie", "ring" }));
  set("weight", 400);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "¸ö");
    set("value", 5000);
    set("material", "gold");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 1);
  }
  setup();
}       

