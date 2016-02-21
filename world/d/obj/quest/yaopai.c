inherit ITEM;
#include <task.h>
void create()
{
  set_name("巡山腰牌", ({ "xunshan yaopai", "yaopai" }));
  set_weight(1000);
  set("long", "这是一个豹头山小妖巡山的腰牌。\n" );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "只");
    set("owner_name","刁钻古怪");
                 set("owner_id","diaozuan guguai");
  }
  setup();
}
