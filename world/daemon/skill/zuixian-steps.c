// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$n一个「醉卧云端」，躲过了$N这一招。\n",
	"$n身形向后一纵，使出一招「饮尽江河」，避过了$N的攻击。\n",
	"$n使出「千杯不倒」，恰好躲过了$N的攻势。\n"
       "但是$n身形飘忽,一招「笑看红尘」,轻轻一纵，早已避开。\n",
       "$n使出「与月共饮」,身随意转，倏地往一旁挪开了三尺，避过了这一招。\n",
       "$n一个「醉眼朦胧」,身形微晃，有惊无险地避开了$N这一招。\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练醉仙望月步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练醉仙望月步。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
