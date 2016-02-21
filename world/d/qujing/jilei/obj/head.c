//Cracked by Roath
// by snowcat dec 19 1997

inherit ITEM;

void create()
{
  set_name("牛头", ({"niu tou", "tou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一只断掉的牛头。\n");
    set("unit", "只");
    set("material", "bone");
  }
  setup();
}

