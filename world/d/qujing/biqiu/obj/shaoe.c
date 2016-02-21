// by snowcat 11/22/1997
 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("五味烧鹅", ({ "wuwei shaoe", "shaoe", "e" }) );
  set_weight(180);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一只卤得香香的五味烧鹅。\n");
    set("unit", "只");
    set("value", 300);
    set("food_remaining", 4);
    set("food_supply", 45);
  }
}

