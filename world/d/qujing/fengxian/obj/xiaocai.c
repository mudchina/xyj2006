// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("小菜", ({"xiao cai", "cai"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一碟子小菜。\n");
    set("unit", "碟");
    set("value", 40);
    set("food_remaining", 5);
    set("food_supply", 12);
  }
}
