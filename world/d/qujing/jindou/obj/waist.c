#include <armor.h>

inherit WAIST;

string *names = ({
  "Ìú»¤Ñü",
  "Í­»¤Ñü",
});

string *ids = ({
  "tie hu yao",
  "tong hu yao",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "hu yao", "yao", "waist"}));
  set_weight(5000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¼þ");
   set("value", 200);
   set("material", "metal");
//   set("armor_prop/armor", 14);
   set("armor_prop/armor", 3);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
