// snowsword. 【雪山剑法】

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招「山舞银蛇」，手中$w化为一道疾光刺向$n的$l",
		"dodge":		-20,
		"damage":		20,
		"damage_type":	"刺伤"
	]),
	([	"action":		"只见$N几个急转，使出「独立云海」，一声长笑中剑光冲天而起，扫向$n的$l",
		"dodge":		-20,
		"damage":		20,
		"damage_type":	"割伤"
	]),
	([	"action":		"只见$N纵身扑起，手中$w由中宫直进，径刺$n的$l。这一招「傲越千山」当真是气势非凡",
		"dodge":		-30,
		"damage":		25,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N手中$w轻轻一抖，一式「千里冰封」幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
		"dodge":		-40,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N手中$w再一抖，只见寒光点点，飘浮不定。\n这一招「万里雪飘」只看得$n眼花缭乱，哪里还能招架",
		"dodge":		-20,
		"damage_type":	"刺伤"
	]),
	
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练雪山剑法。\n");

	if( (string)me->query_skill_mapped("force")!= "moonforce")
		return notify_fail("雪山剑法必须配合昆仑山玉女峰的圆月心法才能练。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习雪山剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍雪山剑法。\n");
	return 1;
}
