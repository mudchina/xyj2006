//Cracked by Roath
 // Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("[1;31m±ùÌÇºùÂ«[m", ({"bingtang hulu", "hulu"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Õý×ÚµÄ±ùÌÇºùÂ«¡£\n");
    set("unit", "´®");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}
