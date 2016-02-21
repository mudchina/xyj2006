// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("Ãæ½î", ({"mian jin", "mian", "jin"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»ÂÌ´ÅÆ¿³´Ãæ½î¡£\n");
    set("unit", "ÂÌ´ÅÆ¿");
    set("value", 90);
    set("food_remaining", 4);
    set("food_supply", 30);
  }
}
