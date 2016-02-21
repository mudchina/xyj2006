#include <armor.h>

inherit WRISTS;

string *names = ({
  "Ìú»¤Íó",
  "Í­»¤Íó",
});

string *ids = ({
  "tie hu wan",
  "tong hu wan",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "hu wan", "wan", "wrists"}));
  set_weight(2000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¼þ");
   set("value", 200);
   set("material", "metal");
//   set("armor_prop/armor", 9);
   set("armor_prop/armor", 1);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
