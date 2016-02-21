#include <ansi.h>

inherit F_SAVE;
inherit COMBINED_ITEM;

void create()
{
  set_name("野花", ({ "flower","yehua","hua" }) );
  set("unit","束");
  set("base_weight",10);
  set("long","一束娇美可人的小野花，散发着一丝淡淡的幽香。\n");
  set("base_unit","朵");
  set("material", "flower");
  set_amount(1+random(3));
  setup();
}


