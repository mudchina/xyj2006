// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("锡盆", ({"xi pen", "xipen", "pen"}));
  set_weight(1100);
  set_max_encumbrance(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("long", "一只印花大锡盆．\n"),
    set("value", 2000);
  }
  setup();
}

int is_container()
{
  return 1;
}
