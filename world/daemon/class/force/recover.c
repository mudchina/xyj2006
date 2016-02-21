// recover.c

inherit SSERVER;

int exert(object me, object target)
{
	int diff, neilineed;

	if( target != me ) return notify_fail("你只能用内功调匀自己的气息。\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("你的内力不够。\n");
    if( (int)me->query_skill("force") < 10 )
		return notify_fail("你的内功修为不够。\n"); 

	diff = me->query("eff_kee") - me->query("kee");
	neilineed = diff * 50 / (int)me->query_skill("force");
    if(neilineed < 1)
	   return notify_fail("你现在气力充沛，不需吸气。\n");
	   
	if(me->query("dhwl"))
	   return notify_fail("你现在正在蓄力怎能吸气。\n");   
    
	if(neilineed > me->query("force")) neilineed = me->query("force");
    diff = neilineed * (int)me->query_skill("force") / 50;
    
	me->receive_heal("kee", diff );
	me->add("force", -neilineed);

	message_vision("$N深深吸了几口气，脸色看起来好多了。\n", me);


	return 1;
}
