// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("肉夹馍", ({"roujia mo", "roujiamo", "mo"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一只热乎乎的肉夹馍。\n");
    set("unit", "只");
    set("value", 200);
    set("food_remaining", 6);
    set("food_supply", 35);
  }
}
