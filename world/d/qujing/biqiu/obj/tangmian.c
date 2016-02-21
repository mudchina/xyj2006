// by snowcat 11/22/1997
 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("牛肉汤面", ({ "niurou tangmian", "tangmian", "mian" }) );
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一碗鲜美的牛肉汤面。\n");
    set("unit", "碗");
    set("value", 280);
    set("food_remaining", 4);
    set("food_supply", 35);
  }
}

