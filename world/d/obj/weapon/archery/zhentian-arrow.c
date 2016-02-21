// zhentian-arrow.c 震天箭

#include <weapon.h>

inherit ARCHERY;

void create()
{
  set_name("震天箭", ({ "zhentian jian", "arrow", "jian", "zhentian", "zhentian jian", }) );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long",
"震天箭乃是陈唐关总兵李靖的镇关之宝。后因李靖结交\n虬髯客被疑而调入京城，也被李靖带来了。\n");
    set("unit", "壶");
    set("base_unit", "枝");
    set("base_weight", 40);
    set("base_value", 500);
  }
  set_amount(18);
  init_archery(80);
  setup();
}

