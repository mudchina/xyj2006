// by snowcat oct 15 1997

inherit ITEM;

void create()
{
  set_name("Он©уд╬вю", ({"zhuo zi", "zhuozi", "table"}));
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "р╩уеОн©уд╬вю║ё\n");
    set("material", "wood");
    set("unit", "уе");
    set("value", 1200);
  }
  setup();
}

