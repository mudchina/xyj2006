#include <armor.h>

inherit HEAD;

void create()
{
  set_name("硬木盔", ({ "ying mukui", "mukui", "kui" }) );
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long","一顶结实的硬木盔，上面绘着云纹。\n");
    set("value", 600);
    set("material", "cloth");
    set("armor_prop/armor", 5);
    set("armor_prop/personality", 1);
  }
  setup();
}

