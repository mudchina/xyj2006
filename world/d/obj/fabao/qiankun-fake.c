// qiankun fake
// created by bbs, 4-12-98.

#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
  set_name(YEL "乾坤圈" NOR,({"qiankun quan", "quan", "qiankunquan", "qiankun"}));
  set_weight(10000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","只");
    set("value",0);
    set("long","一只纯钢打造的钢环，很结实。\n");
    set("wield_msg","$N拿出一只$n握在手中。\n");
    set("unequip_msg","$N将手中的$n收入豹皮囊。\n");
  }
  init_hammer(25);
  setup();
}
int ji(string target)
{
    string objname=this_object()->name();
    object me=this_player(), victim;

    if (!target) return notify_fail("你想用对谁用"+objname+"？\n");
    victim=present(target,environment(me));
    if(!victim) return notify_fail("这里没有 "+target+"。\n");
    if(!living(victim)) return notify_fail("你的目标不是活物！\n");
    if(!me->is_fighting()) return notify_fail("只有战斗中才能祭"+objname+"。\n");  
    if( (int)me->query("mana") < 250)
        return notify_fail("你的法力不够了！\n");
    if( (int)me->query("sen") < 100)
        return notify_fail("你的精神无法集中！\n");
    return notify_fail("无论你怎么念咒，"+objname+"就是不动。\n");
}
