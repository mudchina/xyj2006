// pink_cloth.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(HIG "芭蕉裙" NOR, ({ "palm skirt", "skirt" }) );
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "一条绿色的百叶芭蕉裙。\n");
    set("unit", "条");
    set("value", 0);
    set("material", "cloth");
    set("armor_prop/armor", 30);
    set("armor_prop/personality", 3);
  }
  setup();
}


