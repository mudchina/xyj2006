// by snowcat dec 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("烧龙虾", ({"shao longxia", "shaolongxia", "longxia", "lobster"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一只烧得通红的大龙虾。\n");
    set("unit", "只");
    set("value", 750);
    set("food_remaining", 8);
    set("food_supply", 45);
  }
}
