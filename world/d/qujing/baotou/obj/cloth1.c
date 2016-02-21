#include <armor.h>

inherit CLOTH;

string *names = ({
  "»¨±ªÆ¤",
  "°×»¢Æ¤",
  "ºÚ»¢Æ¤",
  "½ðÊ¨Æ¤",
  "¾íÃ«Ê¨Æ¤",
  "É½Ã¨Æ¤",
});

string *ids = ({
  "huabao pi",
  "baihu pi",
  "heihu pi",
  "jinshi pi",
  "juanmao pi",
  "shanmao pi",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i],"pi", "cloth"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¼þ");
   set("value", 500);
   set("material", "leather");
   set("armor_prop/armor", 15);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
