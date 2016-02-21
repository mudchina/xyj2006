// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  string name = "»ğÍÈÖñóÏ¸ş";
  set_name(name, ({"huotui zhushenggeng", "zhushenggeng", "geng"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»ÅÌÁîÈË´¹ÏÑµÄ"+name+"¡£\n");
    set("unit", "ÅÌ");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 25);
  }
}
