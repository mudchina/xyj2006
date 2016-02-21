// created 3/31/1997 by snowcat
#include <weapon.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("¥÷¥…≤ËÕÎ", ({ "cuci chawan", "chawan", "wan", "tea" }) );
  set_weight(500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "’‚ «“ª÷ª¥÷¥…≤ËÕÎ°£\n");
    set("unit", "÷ª");
    set("value", 40);
    set("max_liquid", 80); 
  }

  set("liquid", ([
    "type": "tea",
    "name": "µ≠≤Ë",
    "remaining": 80,
  ]) );
  setup();
}
