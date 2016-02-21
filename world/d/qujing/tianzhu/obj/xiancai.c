
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("红苋菜", ({"hong xiancai", "xiancai", "cai"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一把极为新鲜的红苋菜。\n");
    set("unit", "把");
    set("value", 80);
    set("food_remaining", 3);
    set("food_supply", 30);
  }
}

