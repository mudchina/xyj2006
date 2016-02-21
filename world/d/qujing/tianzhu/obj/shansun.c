
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("山笋", ({"shan sun", "shansun", "sun"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一颗刚从山上剥下的山笋。\n");
    set("unit", "颗");
    set("value", 75);
    set("food_remaining", 3);
    set("food_supply", 35);
  }
}

