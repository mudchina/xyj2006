// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("醉泥螺", ({"zui niluo", "zuiniluo", "zuiluo", "luo"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一包醉泥螺，用荷叶包着。\n");
    set("eat_msg", "$N捏起一颗醉泥螺，将肉一吸，吐掉空壳。\n");
    set("unit", "包");
    set("value", 125);
    set("food_remaining", 15);
    set("food_supply", 2);
  }
}

