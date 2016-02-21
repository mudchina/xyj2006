//Cracked by Roath
// invocation.c

inherit SSERVER;

int cast(object me, object target)
{	
        int invocation_time;
        object soldier;
        if(me->query("family/family_name")!="阎罗地府")
                return notify_fail("你不是地府弟子，不能使用这项技能！\n");
        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤阴兵！\n");
	
        invocation_time=60+(200-(int)me->query_skill("spells"));
        if(invocation_time<30) invocation_time=30;
        if((time()-me->query("last_invocation"))<invocation_time)
	    return notify_fail("现在地府中并无空闲的鬼卒来保护你。\n");

        if( (int)me->query("mana") < 100 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神无法集中！\n");

        message_vision("$N喃喃地念了几句咒语。\n\n", me);

        me->add("mana", -50);

        if( random(me->query("max_mana")) < 20 ) {
                message("vision", "但是什么也没有发生。\n",
environment(me));
                return 1;
        }

        seteuid(getuid());
        soldier = new("/obj/npc/hell_guard");
        soldier->move(environment(me));
        soldier->invocation(me);
	soldier->set_temp("invoker",me);
        me->set("last_invocation",time());
	me->start_busy(2+random(2));

        return 8+random(5);
}




