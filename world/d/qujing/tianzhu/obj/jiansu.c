// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("Ğ¡¼åËÖ", ({"jian su", "jiansu", "su"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»ÅÌÏã´àµÄĞ¡¼åËÖ¡£\n");
    set("unit", "ÅÌ");
    set("value", 140);
    set("food_remaining", 4);
    set("food_supply", 25);
  }
}

