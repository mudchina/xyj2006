inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("·¬Ä¾¹Ï", ({"fanmu gua", "fanmugua", "papaya"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»¿ÅË¶´óµÄ·¬Ä¾¹Ï¡££\n");
    set("unit", "¿Å");
    set("value", 110);
    set("food_remaining", 4);
    set("food_supply", 30);
  }
}

