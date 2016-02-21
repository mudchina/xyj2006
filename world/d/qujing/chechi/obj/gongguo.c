// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("供果", ({"gong guo", "gong", "guo"}));
  set_weight(2400);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一小竹蓝子香客送来的供果。\n");
    set("unit", "小竹蓝子");
    set("value", 340);
    set("food_remaining", 10);
    set("food_supply", 20);
  }
}
