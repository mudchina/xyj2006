// by snowcat oct 15 1997
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name("¹¬ÅÛ", ({"gong pao", "cloth"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "Ò»¼þ¹¬ÅÛ¡£\n");
    set("material", "cloth");
    set("unit", "¼þ");
    set("value", 300);
    set("armor_prop/armor", 15);
  }
  setup();
}

