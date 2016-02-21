// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("ÑÎ", ({"yan", "salt"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»°ü°×ÑÎ¡£\n");
    set("unit", "°ü");
    set("value", 80);
    set("food_remaining", 20);
    set("food_supply", 1);
  }
}
