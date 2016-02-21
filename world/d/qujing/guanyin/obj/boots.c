// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit BOOTS;

string *names = ({
    "乌皮靴",
});

string *ids = ({
    "wu pi xue",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "xue", "shoes"}));
  set_weight(2000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "双");
   set("value", 200);
   set("material", "metal");
   set("armor_prop/armor", 10);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}

