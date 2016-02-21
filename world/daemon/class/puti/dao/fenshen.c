// fenshen.c 分身术

inherit SSERVER;

int cast(object me, object target)
{
	int fenshen_time; //this time is the time interval fenshen can be used again. 
	object soldier;

	if( !me->is_fighting() )
		return notify_fail("只有战斗中才能使用分身法！\n");
        if(me->query("family/family_name")!="方寸山三星洞")
         {
            if(me->query("family/family_name")!="陷空山无底洞")
              return notify_fail("你不能用「分身术」！\n");
         }
        fenshen_time=60+(200-(int)me->query_skill("spells"));
	if(fenshen_time<60) fenshen_time=60;
	if((time()-me->query("last_fenshen"))<fenshen_time)
		return notify_fail("你刚刚分过身，再分身很危险！\n");
		//hehe...at least 1 minute between 2 fenshens to
		//prevent ppls using too many 假身 to kill top masters...weiqi.
	
	if( (int)me->query("mana") <4*(int)me->query_skill("spells"))
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神无法集中！\n");

	message_vision("$N喃喃地念了几句咒语。\n", me);

	if( random(me->query("max_mana")) < 200 ) {
		me->add("mana",-(int)me->query_skill("spells"));
		me->receive_damage("sen",10);
		message("vision", "但是什么也没有发生。\n", environment(me));
		return 1;
	}

	me->add("mana", -4*(int)me->query_skill("spells"));
	me->receive_damage("sen", 40);

	seteuid(getuid());
	soldier = new("/obj/npc/jiashen");

	soldier->move(environment(me));
	soldier->invocation(me);
	soldier->set_temp("invoker",me);
	me->set("last_fenshen",time());
	me->start_busy(2+random(2));

	return 8+random(5);
}
