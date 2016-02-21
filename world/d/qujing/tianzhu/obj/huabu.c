#include <armor.h>

inherit ITEM;

void create()
{
  set_name("花布", ({ "hua bu", "huabu", "bu" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "一块大花布。\n");
    set("value", 50);
    set("material", "cloth");
  }
  setup();
}

