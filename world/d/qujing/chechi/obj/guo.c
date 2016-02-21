// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("小供果", ({"gong guo", "gong", "guo"}));
  set_weight(400);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一只小供果。\n");
    set("unit", "只");
    set("value", 20);
    set("food_remaining", 3);
    set("food_supply", 5);
  }
}
