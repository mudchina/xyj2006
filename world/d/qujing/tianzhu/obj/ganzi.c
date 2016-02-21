inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("柑子", ({"gan zi", "ganzi", "zi"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一包黄橙橙的柑子。n");
    set("unit", "包");
    set("value", 100);
    set("food_remaining", 4);
    set("food_supply", 20);
  }
}

