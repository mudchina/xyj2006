
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("花菜", ({"hua cai", "huacai", "cai"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一颗极为新鲜的花菜。\n");
    set("unit", "颗");
    set("value", 80);
    set("food_remaining", 3);
    set("food_supply", 30);
  }
}

