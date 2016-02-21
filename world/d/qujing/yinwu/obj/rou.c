// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "É½Êó",
  "»¨Éß",
  "»ÒÍÃ",
  "ºÚºü",
  "ÁçÑò",
  "Ò°Âí",
  "Ò°Â¹",
  "Ò°Â¿",
  "É½ÍÕ",
  "ÍÁáó",
  "É½¼¦",
  "Ê÷Ñ»",
  "ĞÉĞÉ",
});

string *pieces = ({
  "Èâ¸É",
  "Èâ°Í",
  "ÈâÌõ",
  "Èâ±ı",
  "Èâ°å",
});

void create()
{
  string name = names[random(sizeof(names))]
                + pieces[random(sizeof(pieces))];
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
