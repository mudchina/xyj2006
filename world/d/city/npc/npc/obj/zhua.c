#include <weapon.h>

inherit DAGGER;

void create()
{
  set_name("短铁爪", ({ "tie zhua", "zhua", "dagger" }) );
  init_dagger(25);
  set("unit", "根");
  set_weight(300);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 280);
    set("material", "tron");

  }
  set("wield_msg","$N拿起$n握在手里。\n");
  set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
				set("no_give","总管发的装备，可不能乱送人哟！\n");
				set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");
  setup();
}

