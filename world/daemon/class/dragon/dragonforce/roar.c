#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob, where;
        int i, skill, damage, force;

	where=environment(me);
	if( where->query("no_fight") )
		return notify_fail("安全区内不能乱吼乱叫！\n");
        if(me->query("family/family_name")!="东海龙宫")
                return notify_fail("非龙宫弟子不能用「碧海龙吟」！\n");

        if( !me->is_fighting() )
                return notify_fail("碧海龙吟只能在战斗中使用。\n");

        if( (int)me->query("force") < 200 )
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee") < 100)
		return notify_fail("你的力气不够了。\n");

        skill = me->query_skill("force");
	force = me->query("max_force");
        me->add("force", -150);
        me->receive_damage("kee", 50);

        me->start_busy(5);
	message_vision(HIR "\n$N退后两步，深深地吸一口气，猛然发出股如山崩海啸般的龙吟！\n\n"
NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
		if(!me->visible(ob[i])) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

                damage = skill + force/10 - ((int)ob[i]->query("max_force") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("sen", damage, me);
                        if( (int)ob[i]->query("force") < skill * 2 )
                                ob[i]->receive_wound("sen", damage/2, me);
                        tell_object(ob[i], "你觉得眼前一阵金星乱冒，耳朵痛得像是要裂开一样！\n");
                }
		COMBAT_D->report_sen_status(ob[i]);		
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }

        return 1;
}

