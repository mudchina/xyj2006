// by snowcat dec 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("熏鱼", ({"xun yu", "xunyu", "yu", "fish"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一条两面熏得酥香金黄的鱼。\n");
    set("unit", "条");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 40);
  }
}
