// created by snowcat
#include <dbase.h>

inherit ITEM;

void create()
{
  set_name("芭蕉骨", ({ "palm bone", "bone"}) );
  set_weight(150);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一根细实的芭蕉骨，不知有什么用。\n");
    set("unit", "根");
  }
  setup();
}

