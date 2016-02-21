// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  string name = "◊ﬂ”Õ¥‡≥¶";
  set_name(name, ({"zouyou cuichang", "cuichang", "chang"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "“ª≈Ã¡Ó»À¥πœ—µƒ"+name+"°£\n");
    set("unit", "≈Ã");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 25);
  }
}
