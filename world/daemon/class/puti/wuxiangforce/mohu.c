//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//bula, 1/22
#include <ansi.h>

inherit SSERVER;
int exert(object me, object target)
{
   string msg;
        int skill, damage;
   target = offensive_target(me);

        if(me->query("family/family_name") != "方寸山三星洞" )
                return notify_fail("你是哪儿偷学来的武功，也想用「貘虎之齿」?\n");
        if( !me->is_fighting() )
                return notify_fail("貘虎之齿只能在战斗中使用！\n");

        if( (int)me->query("force") < 400 )
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("force");
   
    msg = HIR
"$N突然脸色一变，现出一个虎形，又尖又长的利齿向$n的颈部刺去！\n";
   me->start_busy(2);
   me->receive_damage("kee", 50);
   me->add("force", -100);

   if((int)me->query_int()  > (int)target->query_int()/2 +random(30) ) {
           damage = skill - ((int)target->query("max_force")/10);
           if( damage > 0 ) {
            msg += "(只见一片肉血飞扬，$n的颈部被咬出一个血洞！)\n\n" NOR;
                target->receive_wound("kee", damage);
           me->add("bellicosity", damage/2);
     }
        else msg += "结果连皮都没划破！\n" NOR;
        }
   else msg += "结果被$n躲开了！\n" NOR;

        message_vision(msg, me, target);
        return 1;
}

