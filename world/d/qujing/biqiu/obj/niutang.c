// by snowcat 11/22/1997
 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("¿±Œ∂≈£Ã¿", ({ "lawei niutang", "niutang", "tang" }) );
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "“ªÕÎ∫Ï∫Ù∫Ùµƒ¿±Œ∂≈£»‚Ã¿°£\n");
    set("unit", "ÕÎ");
    set("value", 160);
    set("food_remaining", 4);
    set("food_supply", 25);
  }
}

