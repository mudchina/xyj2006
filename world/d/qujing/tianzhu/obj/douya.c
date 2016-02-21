
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("豆芽", ({"dou ya", "douya", "ya"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一把刚发出的豆芽。\n");
    set("unit", "把");
    set("value", 70);
    set("food_remaining", 3);
    set("food_supply", 20);
  }
}

