// created 5-15-97 pickle

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("√∑≤Àø€»‚", ({"meicai kourou", "kourou", "rou"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "“ª≈Ãœ„≈Á≈Áµÿ√∑≤Àø€»‚°£\n");
    set("unit", "≈Ã");
    set("value", 0);
    set("food_remaining", 5);
    set("food_supply", 40);
  }
}

