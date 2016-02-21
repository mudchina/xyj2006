// gangcha.c

#include <weapon.h>

inherit FORK;

string *names = ({
  "鹿角叉",
  "羊角叉",
  "牛角叉",
  "犀角叉",
});

void create()
{
  set_name(names[random(sizeof(names))], ({ "cha", "fork" }) );
  set_weight(6000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 300);
    set("material", "bone");
    set("long", "一柄以动物角制造的长叉。\n");
    set("wield_msg", "$N抄起一柄$n举过头顶。\n");
  }
  init_fork(35);
//  set("no_sell",1);
  setup();
}

