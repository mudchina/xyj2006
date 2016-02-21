//lestat for 昆仑山
//2001 天龙破
 
#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int skill;

       string msg,str; 

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「天龙破」?\n");
        if(me->query_temp("BAIGU_perform")) 
                return notify_fail("你已经使出「天龙破」了！\n");
        if( time()-(int)me->query_temp("BAIGU_end") < 6 )
                return notify_fail("绝招用多就不灵了！\n");
        if( me->query_temp("pfmxue") ) 
                return notify_fail("你正在全身运用天下有雪。\n");

        if(!me->is_fighting(target) )
                return notify_fail("天龙破只能在战斗中使用!!\n");

        if((int)me->query("max_force") <1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") <50 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("kaitian-zhang",1) <100)
                return notify_fail("你的混元开天掌级别还不够施展这一招天龙破!!\n");
        if((int)me->query_skill("unarmed",1) <100)
                return notify_fail("你的格斗扑击之术等级不够!!\n");
        if(me->query("family/family_name") != "昆仑山玉虚洞" )
                return notify_fail("你与昆仑无缘,领悟不到掌法的精髓!!\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        weapon=me->query_temp("weapon");
     msg = HIC
"\n$N默运玄宗心法，突然双掌变爪，使出开天掌绝学"HIR"「天龙破」"HIC"，步法连绵，撒出一片爪影从半空中逼向$n!\n" NOR;
    message_vision(msg, me, target);

        skill = me->query_skill("unarmed");
        me->set_temp("BAIGU_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("BAIGU_perform");
        me->set_temp("BAIGU_end",time());
            if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+HIM"被"+me->name()+"用玉虚秘传"NOR+HIR"「天龙破」"+HIM"抓死了！";
	                 message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
	               }
        me->add("force", -200);
        return 1;
}

