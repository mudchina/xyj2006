// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

string *names = ({
  "ÓÍìËÉ½Ëñ¼â",
  "ÇåÉÕµØÁúÒÂ",
  "ìÀÌÀÄ¢¹½",
  "Ò°Àõ×Ó¸â",
  "ºÚËÉ×Ó±ı",
  "°×¹ûÈÊ´àËÖ",
});

void create()
{
  string name = names[random(sizeof(names))];
  set_name(name, ({"food"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "Ğ©");
    set("value", 120);
    set("food_remaining", 6);
    set("food_supply", 35);
  }
  set("no_sell",1);
}
