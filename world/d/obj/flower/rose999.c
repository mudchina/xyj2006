// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

#include "message.h"

void create ()
{
  set_name(HIB "九百九十九朵玫瑰" NOR, ({ "flower"}));
  set_weight(100);
  set("long","色彩艳丽的"+query("name")+"。\n");
  set("unit", "把");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 2);
  set("unequip_msg","$N将"+query("name")+"轻轻地摘下来……。\n");
  set("wear_msg", "$N戴上"+query("name")+"，不禁想起年少时曾经的梦中人。\n");
  setup();
}


