
inherit ITEM;
void create()
{
  set_name("ÆÆÌúÁı", ({"tie long", "long"}));
  set_weight(2800000);
  set("long", "Ò»¸öÆÆÌúÁı¡£\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("no_get", 1);
    set("unit", "°Ñ");
    set("material", "stone");
    set("value", 2000);
    set("no_sell", 1);
  }
  setup();
}

