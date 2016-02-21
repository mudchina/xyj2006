// rake.c

#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("九齿钉钯", ({ "ding pa", "pa","rake" }) );
  set_weight(9000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 8000);
    set("material", "iron");
    set("long", "一柄长长的九齿钢耙。\n");
    set("wield_msg", "$N抡起一柄$n，呼地一声举过头顶。\n");
  }
  init_rake(75);
  setup();
}


