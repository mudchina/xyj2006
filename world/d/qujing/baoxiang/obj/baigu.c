// by snowcat dec 19 1997

inherit ITEM;

void create()
{
  set_name("°×¹Ç", ({"bai gu", "gu"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»¶Ñ°×¹Ç¡£\n");
    set("unit", "¶Ñ");
    set("material", "bone");
  }
  setup();
}

