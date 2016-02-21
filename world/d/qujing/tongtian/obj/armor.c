#include <armor.h>

inherit ARMOR;

string *names = ({
  "ÎÚ¹ê¼×",
  "Íõ°Ë¼×",
  "Ç§ÁÛ¼×",
  "¾ÞÐ·¿Ç",
});

string *ids = ({
  "wugui jia",
  "wangba jia",
  "qianling jia",
  "juxie ke",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "jia", "armor"}));
  set_weight(20000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¼þ");
   set("value", 300);
   set("material", "shell");
   set("armor_prop/armor", 20);
   set("armor_prop/dodge", -5);
  }
  set("no_sell",1);
  setup();
}
