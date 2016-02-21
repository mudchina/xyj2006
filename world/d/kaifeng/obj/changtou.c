// by snowcat

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("走油肠头", ({"chang tou", "changtou", "chang", "tou"}));
  set_weight(600);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一刚刚炒出来的热菜。\n");
    set("unit", "盘");
    set("value", 400);
    set("food_remaining", 8);
    set("food_supply", 25);
  }
}

