#include <armor.h>

inherit HEAD;

string *names = ({
  "ÌúÍ·¿ø",
  "Í­Í·¿ø",
});

string *ids = ({
  "tie tou kui",
  "tong tou kui",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "tou kui", "kui", "head"}));
  set_weight(4000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¼þ");
   set("value", 200);
   set("material", "metal");
//   set("armor_prop/armor", 12);
   set("armor_prop/armor", 2);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
