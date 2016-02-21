
// sanqing-jian.c【三清剑法】
//for 道士 NPCs, if going to be used by players, need refine. 

/*
三清剑法    dodge  -5    parry  15    damage  20
道家功夫，轻灵飘逸，不沾凡尘之气。但唯其太过讲究
而不太实用。
*/

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使出一招「星河影动」，剑光闪烁不定，若有若无地刺向$n$l",
		"dodge":		0,
		"parry":		15,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N身形转个不停，突然一招「一点灵犀」使出，手中$w划出一道银弧，径刺$n$l",
		"dodge":		-10,
		"parry":		15,
		"damage":		25,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N脚下踏了个七星步，一招「古道西风」手中$w势若飞瀑向$n拦腰一斩",
		"dodge":		-5,
		"parry":		15,
		"damage":		20,
		"damage_type":	"劈伤"
	]),
	([	"action":		"但见$N连退几步，忽然间纵身跃起，手中$w一式「沧海月明」对准$n的$l凌空一斩",
		"dodge":		-15,
		"parry":		5,
		"damage":		30,
		"damage_type":	"劈伤"
	]),
	([	"action":		"$N轻轻一跃，使了个「乘风归去」，却在转身之际对准$n$l斜斜挥出一剑",
		"dodge":		5,
		"parry":		25,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N神态悠闲，手中$w凭空一指，一招「白云千载」轻妙地划向$n的$l",
		"dodge":		-10,
		"parry":		10,
		"damage":		20,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N手中$w向外一分，使一招「曲径通幽」反手对准$n$l一剑刺去",
		"dodge":		0,
		"parry":		20,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练三清剑法。\n");

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
		return notify_fail("你的内力或气不够，没有办法练习三清剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按着所学练了一遍三清剑法。\n");
	return 1;
}

