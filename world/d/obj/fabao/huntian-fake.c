// huntian fake
// created by bbs, 4-12-98.

#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
  set_name(HIR "混天绫" NOR,({"huntian ling", "ling", "huntianling", "huntian"}));
  set_weight(5000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("unit","条");
    set("value",0);
    set("long","这是一条红色的绸带，也不知道是干什么用的。\n");
    set("wield_msg","$N从腰间解下一条$n，顿时染红了一天云霞。\n");
    set("unequip_msg","$N把$n细心的卷好系在腰间。\n");
  }
  init_whip(10);
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
