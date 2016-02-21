// by snowcat dec 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("五香炒豆", ({"chao dou", "chaodou", "dou", "beans"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一包喷香的炒豆子。\n");
    set("eat_msg", "$N抓出一粒炒豆子往嘴里一扔，嚼了起来。\n");
    set("unit", "包");
    set("value", 110);
    set("food_remaining", 20);
    set("food_supply", 1);
  }
}


