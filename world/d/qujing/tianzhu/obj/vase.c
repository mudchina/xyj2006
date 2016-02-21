#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("青石花瓶", ({ "hua ping","huaping","ping","vase"}) );
  set_weight(600);
  set_max_encumbrance(6000);
  set_max_items(12);
  if( clonep() ){
    set_default_object(__FILE__);
  } else {
    set("unit", "只");
    set("long", "这是一只绘着粉红小花的青石花瓶。\n");
    set("value", 2000);
  }
  set("wield_msg", "$N捧起青石花瓶，小心地抱在胸口。\n");
  set("unwield_msg", "$N将青石花瓶轻轻地放下。\n");
  init_hammer(1);
}

int is_container()
{
  return 1;
}

