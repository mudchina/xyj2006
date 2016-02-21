inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("茶干", ({"cha gan", "gan"}));
  set_weight(300);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一小包香茶干，散发着香味。\n");
    set("unit", "包");
    set("value", 85);
    set("food_remaining", 5);
    set("food_supply", 15);
  }
}

