// dumpling.c

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("肉包子", ({ "bao zi","baozi","bao", "dumpling" }) );
  set_weight(80);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", 
"一个香喷喷、热腾腾的大包子。\n");
    set("unit", "个");
    set("value", 1);
    set("food_remaining", 4);
    set("food_supply", 100);
  }
}

