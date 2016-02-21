//Cracked by Roath
// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "¿¾Èâ¿é",
  "¿¾Èâ°Í×Ó",
  "¿¾Í·Èâ",
  "¿¾ÍÈ×ÓÈâ",
  "¿¾ĞØ¸¬Èâ",
  "¿¾×øÍÎÈâ",
});

void create()
{
  set_name(names[random(sizeof(names))], ({"rou", "meat"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»´ó¿é¿¾ÊìµÄÊŞÈâ¡£\n");
    set("unit", "´ó¿é");
    set("food_remaining", 6);
    set("food_supply", 35);
    set("value",50);
  }
}
