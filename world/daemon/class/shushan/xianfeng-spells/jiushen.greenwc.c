// Jiushen
#include <ansi.h>

inherit SSERVER;
inherit F_CLEAN_UP;

int cast(object me, object target)
{
	object *ob;
       int i, skill, damage, spells;
            int success_adj, damage_adj;

              if( !me->is_fighting() )
                return notify_fail("只能在战斗中召唤酒神。\n");

        if((int)me->query_skill("xianfeng-spells", 1) < 100 )
                return notify_fail("你的仙风云体术火候不够，怎么能召唤酒神！\n");

        if((int)me->query("mana") < 200+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够，估计酒神感应不到！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你现在神智不清，连MM都不认识，更别说是酒神了！\n");
           
             if (!me->query_condition("drunk"))
                            return notify_fail("你现在一丝醉意都没有，怎么叫的到酒神？\n");

	me->add("mana", -200-(int)me->query("mana_factor"));
	me->receive_damage("sen", 100);
           me->apply_condition("drunk", 0);
           if( random(me->query("max_mana")) < 100 ) {
		message_vision(HIR "\n$N忽然一张口，朝天喷出一口酒雾\n
只见酒雾中化出一个人形，探了探头，又随酒雾消散开去！n\n"NOR, me);

		return 1;
	}
	skill = me->query_skill("spells");
	spells = me->query("max_mana");

message_vision(HIR "\n$N忽然一张口，朝天喷出一口酒雾\n
只见酒雾中化出一个人形，凭空打出了一个惊雷，击向在场的每一个人！\n\n"NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

 damage = skill + random(skill)+spells/10 - ((int)ob[i]->query("max_mana") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("kee", damage);
                        if( (int)ob[i]->query("mana") < skill * 2 )
                                ob[i]->receive_wound("kee", damage/2);
                        tell_object(ob[i], "结果你被击个正着！\n");
                }
		COMBAT_D->report_status(ob[i]);		
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }

	me->receive_wound("sen", 10);

	me->start_busy(2+random(2));
	return 1;
}

