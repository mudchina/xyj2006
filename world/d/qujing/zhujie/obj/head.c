// by snowcat oct 29 1997
#include <weapon.h>

inherit ITEM;

void create()
{
  set_name("狮子头", ({"shizi tou", "tou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一只被齐齐砍断的狮子头。\n");
    set("unit", "只");
    set("material", "bone");
  }
  setup();
}

