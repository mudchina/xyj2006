
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("黑木耳", ({"hei muer", "muer"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一包刚从山上采来的黑木耳。\n");
    set("unit", "包");
    set("value", 75);
    set("food_remaining", 3);
    set("food_supply", 30);
  }
}

