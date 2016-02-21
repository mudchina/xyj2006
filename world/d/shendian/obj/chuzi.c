//by repoo

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIY"厨子"NOR, ({"chu zi"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一个铁铸的小人。\n");
    set("unit", "个");
    set("material", "iron");
  }
  setup();
}
