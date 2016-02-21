#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name("»¢Æ¤´óë©", ({ "hupi dachang", "dachang", "chang" }) );
  set_weight(1600);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "¼þ");
    set("material", "leather");
    set("value", 1600);
    set("armor_prop/armor", 4);
  }
  setup();
}

