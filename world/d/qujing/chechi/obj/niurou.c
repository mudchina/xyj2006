// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("Ω¥≈£»‚", ({"jiang niurou", "jiangniurou", "niurou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "“ª¥Û≈Ã«–µ√±°±°µƒΩ¥≈£»‚∆¨°£\n");
    set("unit", "¥Û≈Ã");
    set("value", 250);
    set("food_remaining", 6);
    set("food_supply", 50);
  }
}
