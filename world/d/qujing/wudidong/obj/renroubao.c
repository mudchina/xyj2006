// 肉包子 renroubao.c
// 9-16-97 pickle

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("肉包子", ({ "rou baozi","baozi","bao", "dumpling" }) );
  set_weight(80);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", 
"一个香喷喷、热腾腾的大包子。\n");
    set("unit", "个");
    set("value", 0);
    set("name_recognized", "人肉包子");
    set("food_remaining", 4);
    set("food_supply", 100);
  }
}
