//Cracked by Roath
// beans.c 豆豆

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("仙果", ({"xian guo", "guo", "fruit"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一只红得发紫的灵山仙果。\n");
    set("unit", "只");
    set("value", 2000);
    set("food_remaining", 20);
    set("food_supply", 40);
  }
  set("no_get", "仙果乃灵山之佛物，不能拿走！\n");
}
