 
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("油炸鸡", ({ "youzha ji", "ji" }) );
  set_weight(120);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一只炸得金黄的酥油香鸡。\n");
    set("unit", "只");
    set("value", 200);
    set("food_remaining", 4);
    set("food_supply", 40);
  }
}

