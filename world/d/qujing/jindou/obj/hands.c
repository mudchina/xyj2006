#include <armor.h>

inherit HANDS;

string *names = ({
  "ÌúÊÖÌ×",
  "Í­ÊÖÌ×",
});

string *ids = ({
  "tie shou tao",
  "tong shou tao",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "shou tao", "tao", "hands"}));
  set_weight(3000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¸±");
   set("value", 200);
   set("material", "metal");
//   set("armor_prop/armor", 10);
   set("armor_prop/armor", 2);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}
