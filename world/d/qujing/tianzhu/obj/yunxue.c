#include <armor.h>

inherit BOOTS;

void create()
{
  set_name( "ÔÆÑ¥", ({ "yun xue", "yunxue", "xue" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "Ë«");
    set("long", "Ò»Ë«¸ßÑüºñµ×µÄÔÆÑ¥¡£\n");
    set("value", 120);
    set("material", "boots");
    set("armor_prop/dodge", 2);
  }
  setup();
}

