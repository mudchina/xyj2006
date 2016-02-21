
#include <ansi.h>
inherit ITEM;

void create() {

  set_name(HIR"请柬"NOR,({"invitation letter","xin","letter",}));
  set("long","一张大红请柬，是王母娘娘邀请众仙参加蟠桃大会的信函。"+
       "抬头写着：赤脚大仙仙长钧鉴。\n");
  set("unit","张");

  set("weight",20);
  setup();

}
