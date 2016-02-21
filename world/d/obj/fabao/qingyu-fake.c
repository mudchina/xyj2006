// 青玉葫芦, created by mes
// updated 6-9-97 pickle
 
#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;
 
void create()
{
    set_name(HIC "青玉葫芦" NOR,({"qingyu hulu", "qingyu", "hulu", "qingyuhulu", "fabao"}));
    set_weight(5000);
    set_max_encumbrance (50000);
    if(clonep())
	set_default_object(__FILE__);
    else {
	set("unit","只");
	set("value",100);
	set("material","jade");
	set("long","一只暗青色的葫芦，不知是拿什么做的，触手生温。\n");
    }
}
int ji(string target)
{
    string objname=this_object()->name();
    object me=this_player(), victim, weapon;

    if(!target) return notify_fail("你想用对谁用"+objname+"？\n");
    victim=present(target,environment(me));
    if(!victim) return notify_fail("这里没有 "+target+"。\n");
    if(!living(victim)) return notify_fail("死人的兵器还需要用法宝去拿？\n");
    if(!me->is_fighting()) return notify_fail("只有战斗中才能祭"+objname+"。\n");
    if( (int)me->query("mana") < 300 ) return notify_fail("这么一点点法力也想驱动法宝？\n");
    if( (int)me->query("sen") < 100 ) return notify_fail("你无法集中精神念咒语。\n");
    weapon = victim->query_temp("weapon"); 
    if(!weapon) return notify_fail("你的敌人并没有使用武器。\n");
    return notify_fail("无论你怎么念咒，"+objname+"就是不动。\n");
}
