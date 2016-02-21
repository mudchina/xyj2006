//Cracked by Roath

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
  set_name(HIR"红枣汤圆"NOR, ({"redty", "tangyuan"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一份十分诱人的汤圆,你不禁口水流了好长.\n");
    set("unit", "碗");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}
