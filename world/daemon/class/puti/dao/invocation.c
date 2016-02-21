// invocation.c

inherit SSERVER;

int cast(object me, object target)
{	
        int invocation_time;
        object soldier;

        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤天将！\n");
	if(me->query("family/family_name")!="方寸山三星洞")
          {
           if(me->query("family/family_name")!="陷空山无底洞")
              return notify_fail("你不能召唤天将！\n");
         }
        invocation_time=60+(200-(int)me->query_skill("spells"));
        if(invocation_time<30) invocation_time=30;
        if((time()-me->query("last_invocation"))<invocation_time)
	    return notify_fail("你刚叫过天将，他们都被你叫烦了！\n");

        if( (int)me->query("mana") < 150 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 80 )
                return notify_fail("你的精神无法集中！\n");

        message_vision("$N喃喃地念了几句咒语。\n", me);

        me->add("mana", -150);
        me->receive_damage("sen", 80);

        if( random(me->query("max_mana")) < 250 ) {
                message("vision", "但是什么也没有发生。\n",
environment(me));
                return 1;
        }

        seteuid(getuid());
        soldier = new("/obj/npc/heaven_soldier");
        soldier->move(environment(me));
        soldier->invocation(me);
	soldier->set_temp("invoker",me);
        me->set("last_invocation",time());
	me->start_busy(2+random(2));

        return 8+random(5);
}




