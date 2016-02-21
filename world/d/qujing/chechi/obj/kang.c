// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("菜糠团子", ({"caikang tuanzi", "caikang", "tuanzi"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一只充饥用的菜糠团子。\n");
    set("unit", "只");
    set("value", 40);
    set("food_remaining", 3);
    set("food_supply", 20);
  }
}
