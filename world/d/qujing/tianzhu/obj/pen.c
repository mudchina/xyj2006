#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name("白瓷花盆", ({ "hua pen","huapen","pen"}) );
  set_weight(600);
  set_max_encumbrance(6000);
  set_max_items(12);
  if( clonep() ){
    set_default_object(__FILE__);
  } else {
    set("unit", "只");
    set("long", "这是一只白底蓝花的瓷花盆。\n");
    set("value", 500);
  }
  set("wield_msg", "$N捧起白瓷花盆，小心地抱在胸口。\n");
  set("unwield_msg", "$N将白瓷花盆轻轻地放下。\n");
  init_hammer(1);
}

int is_container()
{
  return 1;
}

