// created by smile 12/10/98

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("¸¯Èâ", ({"fu rou", "rou"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»¿é¸¯³ôµÄÈâ¡£\n");
    set("unit", "¿é");
    set("value", 100);
    set("food_remaining", 5);
    set("food_supply", 40);
  }
}
