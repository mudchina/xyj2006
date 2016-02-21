// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("花生米", ({"huasheng mi", "huashengmi", "huasheng", "mi"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一包椒盐花生米。\n");
    set("eat_msg", "$N捏着一颗花生米往嘴里一扔，抿嘴嚼了起来。\n");
    set("unit", "包");
    set("value", 170);
    set("food_remaining", 15);
    set("food_supply", 2);
  }
}

