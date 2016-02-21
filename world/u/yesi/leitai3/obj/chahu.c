#include <weapon.h>

inherit HAMMER;
inherit F_LIQUID;

void create()
{
  set_name("茶壶", ({"cha hu", "hu"}));
  set_weight(600);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一个白瓷茶壶。\n");
    set("unit", "个");
    set("value", 60);
    set("max_liquid", 7);
    set("wield_msg", "$N抓起一个$n，握在手中当武器。\n");
    set("material", "stone");
  }
  
  set("liquid", ([
                  "type": "water",
                  "name": "清茶",
                  "remaining": 8,
                  ]) );
  init_hammer(1);
  setup();

}

