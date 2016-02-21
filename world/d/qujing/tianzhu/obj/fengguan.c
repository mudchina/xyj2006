#include <armor.h>

inherit HEAD;

void create()
{
  set_name("凤冠", ({ "jin fengguan", "fengguan", "guan" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long","一顶丝质的金色软冠，上面绣着金凤。\n");
    set("value", 800);
    set("material", "silk");
    set("female_only", 1);
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 1);
  }
  setup();
}

