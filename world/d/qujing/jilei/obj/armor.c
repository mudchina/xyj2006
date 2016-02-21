//Cracked by Roath
#include <armor.h>

inherit ARMOR;

string *prefixs = ({
  "Ïâ±ß",
  "Ñ¹»¨",
  "ïÎ»¨",
  "Óñ±ú",
  "ÎÚÐÄ",
});

string *names = ({
  "Áú¹Ç¼×",
  "»¢Öñ¼×",
  "Ó²ÌÙ¼×",
  "¼áÄ¾¼×",
  "¹êÎÆ¼×",
  "¹àÇ¦¼×",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))],
           ({"armor","jia"}));
  set_weight(20000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¼þ");
   set("value", 200);
   set("material", "shell");
   set("armor_prop/armor", 30);
   set("armor_prop/dodge", -5);
  }
//  set("no_sell",1);
  setup();
}
