//拳击的组合拳
//lestat for 大米们
//给大米一个机会,他们会创造奇迹.fool

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	string msg,str;         
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一套组合拳？\n");

        if(!me->is_fighting())
                return notify_fail("组合拳只能在战斗中使用！\n");
                
        if( time()-(int)me->query_temp("xiao_end") < 5 )
          return notify_fail("绝招用太多容易被对手看破！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("boxing", 1) < 50)
                return notify_fail("你的拳击太差，使用这一招会有困难！\n");

	me->delete("env/brief_message");

	message_vision("\n$N一个划步,竟打出一套组合拳！\n", me);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->receive_damage("kee", 50);
	me->add("force", -100);
	
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {
                       	str=target->name()+HIM"被"+me->name()+"用一套"NOR+HIY"「组合拳」"+HIM"打死了！";
	                 message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
	               }
        me->set_temp("xiao_end",time());
	me->start_busy(2);
	return 1;
}

