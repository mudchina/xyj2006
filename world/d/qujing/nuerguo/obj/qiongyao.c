// created 3/31/1997 by snowcat

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("ÇíÑş¶¹¸¯", ({"qiongyao", "doufu", "tofu"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "Ò»ÅÌÇåË®±ÌÓñÇíÑş¶¹¸¯\n");
    set("unit", "ÅÌ");
    set("value", 150);
    set("food_remaining", 5);
    set("food_supply", 40);
  }
}

