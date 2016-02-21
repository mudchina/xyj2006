#include <armor.h>

inherit BOOTS;

void create()
{
  set_name( "Â¹Æ¤Ð¬", ({ "pi xie", "pixue", "xie" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "Ë«");
    set("long", "Ò»Ë«ÈíÉíÓ²µ×µÄÂ¹Æ¤Ð¬¡£\n");
    set("value", 140);
    set("material", "boots");
    set("armor_prop/dodge", 3);
  }
  setup();
}

