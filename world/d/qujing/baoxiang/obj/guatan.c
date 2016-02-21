// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("¹ÒÌº", ({"gua tan", "guatan", "rug"}));
  set_weight(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "Ò»¼þ¹ÒÌº¡£\n");
    set("material", "cloth");
    set("unit", "¼þ");
    set("value", 700);
  }
  setup();
}

