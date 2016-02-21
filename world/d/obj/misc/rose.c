
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create ()
{
  set_name(HIR "九千九百九十九朵玫瑰" NOR, ({ "flower"}));
  set_weight(100);
  set("long","一束玫瑰，送给我的爱人"+query("name")+"。\n");
  set("unit", "把");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  set("unequip_msg","$N将"+query("name")+"轻轻地摘下来……。\n");
  set("wear_msg", "$N戴上"+query("name")+"，不禁流出几滴情人的眼泪。\n");
  setup();
}


