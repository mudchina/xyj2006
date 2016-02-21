// by snowcat 11/20/1997

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("茶盏", ({"cha zhan", "cha", "zhan", "tea"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一个小巧玲珑的茶盏。\n");
    set("unit", "个");
    set("value", 80);
    set("max_liquid", 5);
  }

  set("liquid", ([
    "type": "tea",
    "name": "清茶",
    "remaining": 5,
    "drunk_supply": 6,
  ]));
}
