// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "ÉßÈâ",
  "Â¹¸¬",
  "ĞÜÕÆ",
  "ÍÕ·å",
  "ÂíÍÈ",
  "Â¿·Î",
  "ÀÇ¸Î",
  "áóÈâ",
  "»¢´½",
  "Ê¨±Ç",
  "±ªÉà",
});

void create()
{
  string name = names[random(sizeof(names))];
  set_name(name, ({"rou", "meat"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»´ó¿éÉ¹¸ÉµÄÊŞÈâ¡£\n");
    set("unit", "´ó¿é");
    set("food_remaining", 6);
    set("food_supply", 35);
  }
}

