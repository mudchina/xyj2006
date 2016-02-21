#include <armor.h>

inherit CLOTH;

string *names = ({
  "Ï¬Æ¤±³ÐÄ",
  "Å£Æ¤ÒÂ",
  "ÐÜÆ¤¶ÌÅÛ",
  "»¢Æ¤È¹",
  "ÀÇÆ¤¿ã",
});

string *ids = ({
  "xipi beixin",
  "niupi yi",
  "xiongpi duanpao",
  "hupi qun",
  "langpi qun",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "cloth"}));
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
