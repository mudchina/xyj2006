
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("野蘑菇", ({"mo gu", "gu"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一堆刚从山上采来的蘑菇。\n");
    set("unit", "堆");
    set("value", 75);
    set("food_remaining", 3);
    set("food_supply", 35);
  }
}

