inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("柚子", ({"you zi", "youzi", "zi"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一颗大柚子。n");
    set("unit", "颗");
    set("value", 80);
    set("food_remaining", 3);
    set("food_supply", 20);
  }
}

