// kunxian fake
// created by mes, updated 6-30-97 pickle

#include <ansi.h>
#include <weapon.h>
inherit WHIP;
//inherit ITEM;

void create()
{
  set_name(RED "捆仙索" NOR,({"kunxian suo", "suo", "rope", "kunxiansuo", "kunxian"}));
  set_weight(5000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","条");
    set("value",0);
    set("long","一条暗红色的绳子，也不知道是什么做的。\n");
  }
  init_whip(20);
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
    if(victim->query("no_move")) return notify_fail("对方已经无暇自顾了，有必要用"+objname+"么？\n");
    if( (int)me->query("mana") < 250)
        return notify_fail("你的法力不够了！\n");
    if( (int)me->query("sen") < 100)
        return notify_fail("你的精神无法集中！\n");
    return notify_fail("无论你怎么念咒，"+objname+"就是不动。\n");
}
