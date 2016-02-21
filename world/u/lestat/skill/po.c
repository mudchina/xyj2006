//lestat for 昆仑山
//2001 天龙破
 
#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;

       string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「天龙破」?\n");
        if(me->query_temp("BAIGU_perform")) 
                return notify_fail("你已经使出「天龙破」了！\n");
        if( time()-(int)me->query_temp("BAIGU_end") < 3 )
                return notify_fail("绝招用多就不灵了！\n");

        if(!me->is_fighting(target) )
                return notify_fail("天龙破只能在战斗中使用!!\n");

        if((int)me->query("max_force") <1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") <50 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
/*
        if((int)me->query_skill("jueqingbian",1) <100)
                return notify_fail("你的绝情鞭级别还不够施展这一招天龙破!!\n");
        if((int)me->query_skill("moondance",1) <100)
                return notify_fail("你的冷月凝香舞等级不够!!\n");
        if((int)me->query_skill("moonforce",1)<100)
                return notify_fail("你的圆月心法等级太低!!\n");
        if((int)me->query_skill("moonshentong",1) <100)
                return notify_fail("你的月宫仙法等级不够!!\n");
        if(me->query("family/family_name") != "月宫" )
                return notify_fail("你与痴梦无缘,领悟不到鞭法的精髓!!\n");
*/
        me->delete("env/brief_message");
        target->delete("env/brief_message");

//        ap = 2 + random(1);
        weapon=me->query_temp("weapon");
     msg = HIC
"\n$N默运玄宗心法，突然双掌变爪，使出开天掌绝学"HIR"「天龙破」"HIC"，步法连绵，撒出一片爪影从半空中逼向$n!\n" NOR;
    message_vision(msg, me, target);


        skill = me->query_skill("unarmed");
        me->set_temp("BAIGU_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), skill/10);
        me->add("force", -200);
        return 1;
}

void remove_effect(object me, int amount)
{       
	if ( me->query_temp("BAIGU_perform") ) {
        message_vision(HIM"$N额头上冒出豆大的汗珠，步法逐渐变缓。\n"NOR, me);
        me->delete_temp("BAIGU_perform");
        me->set_temp("BAIGU_end",time());
         }
}
