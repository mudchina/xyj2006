// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("µñÄ¾Ð±¿¿ÒÎ", ({"yi zi", "yizi", "seat"}));
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "Ò»°ÑµñÄ¾Ð±¿¿ÒÎ¡£\n");
    set("material", "wood");
    set("unit", "°Ñ");
    set("value", 900);
  }
  setup();
}

