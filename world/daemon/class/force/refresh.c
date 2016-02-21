// refresh.c

inherit SSERVER;

int exert(object me, object target)
{
    int diff, neilineed;
    
	if( target != me ) return notify_fail("你只能用内功收□自己的心神。\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_skill("force") < 10 )
	    return notify_fail("你的内功修为不够。\n");	
		
    diff = me->query("eff_sen") - me->query("sen");
    neilineed = diff * 50 / (int)me->query_skill("force");
    if(neilineed < 1)
	   return notify_fail("你现在精神饱满，不需吸气。\n");

    if(neilineed > me->query("force")) neilineed = me->query("force");
    diff = neilineed * (int)me->query_skill("force") / 50;
                                      		
	me->receive_heal("sen", diff);
	me->add("force", -neilineed);

	message_vision("$N略一凝神，吸了口气，精神看起来清醒多了。\n", me);

	return 1;
}
