
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("美味豆腐羹", ({"doufu geng", "geng"}));
  set_weight(400);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一大砂锅美味豆腐羹，冒着热气。\n");
    set("unit", "大砂锅");
    set("value", 310);
    set("food_remaining", 14);
    set("food_supply", 20);
  }
}

