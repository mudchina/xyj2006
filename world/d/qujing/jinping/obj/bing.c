 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("ÓÍ±ı", ({ "you bing", "bing" }) );
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "Ò»ÍëÕ¨µÃ½ğ»ÆµÄËÖÓÍ±ı¡£\n");
    set("unit", "Íë");
    set("value", 110);
    set("food_remaining", 3);
    set("food_supply", 20);
  }
}

