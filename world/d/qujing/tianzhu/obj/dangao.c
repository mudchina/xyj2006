// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("小蛋糕", ({"dan gao", "gao"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一小盘切好的的蛋糕。\n");
    set("unit", "盘");
    set("value", 90);
    set("food_remaining", 4);
    set("food_supply", 18);
  }
}

