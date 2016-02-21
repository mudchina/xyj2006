// by snowcat dec 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("蒸螃蟹", ({"zheng pangxie", "zhengpangxie", "pangxie", "crab"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一只蒸得通红的大河蟹。\n");
    set("unit", "只");
    set("value", 650);
    set("food_remaining", 9);
    set("food_supply", 50);
  }
}
