inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
        return CLASS_D("dragon") + "/dragonforce/" + func;
}

int practice_skill(object me)
{
        if( (string)me->query("family/family_name")!="东海龙宫")
                return notify_fail("你非龙族，再练有害无益。\n");

        if( !environment(me)->query("dragonforce_practice") )
                return notify_fail("龙神心法只能在特殊的法台上才可练。\n");

//if( (int)me->query_skill("dragonforce",1) >= 200 )
// return notify_fail("你试着练功，可毫无进展，需要驯服更多的海兽以增进龙神心法。\n");

	if( (int)me->query_temp("dragonforce_practice") < 1 )
		return notify_fail("你试着练功，可毫无进展，需要驯服更多的海兽以增进龙神心法。\n");

        if( (int)me->query("kee") < 30 )
                return notify_fail("你的气不够。\n");
	if( (int)me->query("kee") < 30 )
                return notify_fail("你的神不够。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不够");
        me->receive_damage("kee", 30);
	me->receive_damage("sen", 30);
        me->add("force", -10);
	me->add_temp("dragonforce_practice",-1);
        return 1;
}

