#include <armor.h>

inherit HEAD;

void create()
{
  set_name("Å£Æ¤Ã±", ({ "niu pimao", "pimao", "mao" }) );
  set_weight(800);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "¶¥");
    set("material", "leather");
    set("value", 200);
    set("armor_prop/armor", 3);
  }
  setup();
}

