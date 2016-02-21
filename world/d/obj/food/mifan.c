// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("Ã×·¹", ({"mi fan", "fan", "rice"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»Íë°×Ã×·¹¡£\n");
    set("unit", "Íë");
    set("value", 90);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}
