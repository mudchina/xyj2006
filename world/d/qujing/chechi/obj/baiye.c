// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("牛百叶", ({"niu baiye", "niubaiye", "baiye"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一大盘淋着辣油的牛百叶丝。\n");
    set("unit", "大盘");
    set("value", 240);
    set("food_remaining", 5);
    set("food_supply", 30);
  }
}
