// created  by smile 12/07/1998

inherit ITEM;

void create()
{
  set_name("·Û÷¼÷Ã", ({"fen kulou","kulou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "Ò»¶Ñ·Û÷¼÷Ã¡£\n");
    set("unit", "¶Ñ");
    set("material", "bone");
  }
  setup();
}

