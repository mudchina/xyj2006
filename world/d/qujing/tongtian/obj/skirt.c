#include <armor.h>

inherit CLOTH;

string *prefixs = ({
  "»¨",
  "ËØ",
  "Èí",
  "Ï¸",
});

string *names = ({
  "ÃÞ",
  "É´",
  "½õ",
  "¶Ð",
});

string *suffixs = ({
  "³¤È¹",
  "¶ÌÈ¹",
  "±¡È¹",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))]+
           suffixs[random(sizeof(suffixs))], ({"skirt"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¼þ");
   set("value", 300);
   set("female_only", 1);
   set("material", "cloth");
   set("armor_prop/armor", 1);
   set("armor_prop/dodge", 1);
  }
//  set("no_sell",1);
  setup();
}
