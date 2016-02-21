
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit SSERVER;
string msg;
int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「妖雾冲天」?\n");
        weapon = me->query_temp("weapon");
        if(!me->is_fighting(target))
                return notify_fail("「妖雾冲天」只能在战斗中使用!\n");
		if(me->query("family/family_name")!="陷空山无底洞")
 return notify_fail("“妖雾冲天”只有无底洞门人才可以用！\n");

        if((int)me->query("max_force") < 1500)
                return notify_fail("你的内力不够！\n");

   if((int)me->query("force") < 500 )
     return notify_fail("你的内力不足！\n");

if (!weapon || weapon->query("skill_type") != "sword"  )
    return notify_fail("你必须在使用兵器时才能使用！\n");

        if((int)me->query_skill("qixiu-jian", 1) < 120)
        return notify_fail("你的七修剑等级还不够!!\n");


    msg = MAG
"\n$N阴阴一笑,手中的"+weapon->name()+""+MAG"轻轻一挥,登时飞沙走石,妖雾直冲天际!!\n"NOR;
message_vision(msg, me, target);
   me->delete("env/brief_message");
   target->delete("env/brief_message");
        me->set_temp("QXJ_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));



        me->delete_temp("QXJ_perform");

        //me->receive_damage("sen", 100);
        me->add("force", -150);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                //        else target->kill_ob(me);
                }
        }

        me->start_busy(1+random(1));
        return 1;
}

