// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "°×ÃæâÉâÉ",
  "ÓñÃ×âÉâÉ",
  "ÊíÃæâÉâÉ",
  "¶¹É³âÉâÉ",
  "µËÉ³âÉâÉ",
  "²ËÏÚâÉâÉ",
  "ËñÏÚâÉâÉ",
  "´Ğ»¨âÉâÉ",
  "ÏãÓÍâÉâÉ",
});

void create()
{
  string name = names[random(sizeof(names))];
  set_name(name, ({"mo mo", "mo"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»Ö»ÕôµÃËÉÈíËÉÈíµÄâÉâÉ¡£\n");
    set("unit", "Ö»");
    set("food_remaining", 6);
    set("food_supply", 35);
  }
}

