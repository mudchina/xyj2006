#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
string msg;
int myexp,yourexp,mystr,yourstr,lv;
object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("驱神逐魔只能对战斗中的对手使用。\n");
        if(me->query("family/family_name")!="昆仑山玉虚洞")
        return notify_fail("“驱神逐魔”只有昆仑山玉虚洞门人才可以用！\n");
        if (me->query_skill("dashen-bian",1) < 80)
        return notify_fail("你的打神鞭法还有待提高。\n");
weapon = target->query_temp("weapon");
if(!objectp(weapon)) return notify_fail("你的对手没有用兵器！\n");
myexp=me->query("combat_exp");
mystr=me->query_str();
yourexp=target->query("combat_exp");
yourstr=target->query_str();
lv=me->query_skill("mace",1)/10+1;
msg = YEL "$N挥动手中"+weapon->name()+YEL"，$n的兵器不知怎么就落在了地下！ \n" NOR;
if(objectp(weapon) )
{
//if( random(myexp * lv * mystr) > (yourexp * 2) )
if( random(myexp ) > (yourexp / 2) )
{
weapon->unequip();
weapon->move(environment(target));
message_vision(msg, me, target);
target->start_busy(2);
}
else
{
COMBAT_D->do_attack(target,me, weapon);
}
me->start_busy(2);
}
return 1;
}
