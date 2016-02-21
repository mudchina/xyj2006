
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("香油臭干", ({"chou gan", "chougan", "gan"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一碟子臭干，淋着香油。\n");
    set("unit", "碟");
    set("value", 110);
    set("food_remaining", 6);
    set("food_supply", 25);
  }
}

