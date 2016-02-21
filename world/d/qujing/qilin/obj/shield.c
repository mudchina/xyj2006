#include <armor.h>

inherit SHIELD;

string *names = ({
  "ÇàÂÜÌÙ¶Ü",
  "×ÏÂÜÌÙ¶Ü",
  "ÕÁÄ¾¶Ü",
  "éªÄ¾¶Ü",
});

string *ids = ({
  "qingluo dun",
  "ziluo dun",
  "zhangmu dun",
  "nanmu dun",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "dun", "shield"}));
  set_weight(6000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¼ş");
   set("value", 200);
   set("material", "wood");
   set("armor_prop/armor", 32);
   set("armor_prop/dodge", -2);
  }
  set("no_sell",1);
  setup();
}
