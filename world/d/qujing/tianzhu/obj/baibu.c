#include <armor.h>

inherit ITEM;

void create()
{
  set_name("白布", ({ "bai bu", "baibu", "bu" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "一块大白布。\n");
    set("value", 40);
    set("material", "cloth");
  }
  setup();
}

