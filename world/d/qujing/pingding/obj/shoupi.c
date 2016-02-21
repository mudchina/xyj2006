// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("兽皮", ({"shou pi", "pi"}));
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件硝好的花兽皮。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 600);
  }
  setup();
}

