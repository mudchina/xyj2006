#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("Ï¬Å£Æ¤ÒÂ", ({"xiniu piyi", "piyi", "yi"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "¼þ");
    set("value", 5000);
    set("material", "leather");
    set("armor_prop/armor", 25);
  }
  setup();
}

