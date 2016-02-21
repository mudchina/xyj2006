#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage, force;

        if(me->query("family/family_name")!="火云洞")
return notify_fail("“三味真火”只有火云洞门人才可以用！\n");
        if( !me->is_fighting() )
                return notify_fail("三味真火只能在战斗中使用。\n");

        if( (int)me->query("force") < 200 )
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("kee") < 100)
		return notify_fail("你的力气不够了。\n");

        skill = me->query_skill("force");
	force = me->query("max_force");
        me->add("force", -150);
        me->receive_damage("kee", 50);
	me->receive_wound("kee", 30);

        me->start_busy(5);
	message_vision(HIR "\n$N退后两步，拳头在鼻子上砸了两下，顿时鲜血直冒\n
忽然从$N口中冲出红橙黄三道火焰烧向所有的人！\n\n"NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

                damage = skill + force/10 - ((int)ob[i]->query("max_force") / 10);
                if( damage > 0 ) {
                        ob[i]->receive_damage("kee", damage);
                        if( (int)ob[i]->query("force") < skill * 2 )
                                ob[i]->receive_wound("kee", damage/2);
                        tell_object(ob[i], "结果你被烧得焦头烂额！n");
                }
		COMBAT_D->report_status(ob[i]);		
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }

        return 1;
}

