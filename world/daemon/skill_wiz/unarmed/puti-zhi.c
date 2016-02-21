//【菩提指】puti-zhi.c
// cglaem...12/10/96.
//menpai skill

inherit SKILL;

mapping *action = ({
	([	"action":		"$N“呼”地一指点出，这一招由中宫直进，\n指未到，指风已把$n压得揣不过气来",
		"dodge":		-5,
		"parry":		-5,
		"force":		60,
		"damage_type":	"刺伤",
                        "weapon":		"右手食指",
	]),
	([	"action":		"$N身形不动，右手作「佛祖拈花」状。$n稍一犹豫，$N的中指指节已敲向$n的$l",
		"dodge":		10,
		"parry":		-10,
		"force":		120,
		"damage_type":	"砸伤",
                        "weapon":		"右手中指",
	]),
	([	"action":		"只见$N一转身，一指由胁下穿出，疾刺$n的$l",
		"dodge":		-5,
		"parry":		10,
		"force":		80,
		"damage_type":	"刺伤",
                        "weapon":		"左手食指",
	]),
	([	"action":		"$N双掌一错，十指如穿花蝴蝶一般上下翻飞。$n只觉得全身都在$N指力笼罩之下",
		"dodge":		-15,
		"parry":		10,
		"force":		60,
		"damage_type":	"刺伤",
                        "weapon":		"左手食指", 
	]),
            ([	"action":		"只见$N面带微笑，负手而立。但是$n觉得有一道指力直扑$l而来",
		"dodge":		15,
		"parry":		-5,
		"force":		60,
		"damage_type":	"内伤",
                        "weapon":		"右手食指",
	]),
            ([	"action":		"忽听$N一声轻叱，左手划了个半弧，右手食指闪电般点向$n的$l",
		"dodge":		-5,
		"parry":		-5,
		"force":		70,
		"damage_type":	"刺伤",
                        "weapon":		"右手食指",
	]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练菩提指必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("sen", 20);
	me->receive_damage("kee", 20);
	me->add("force", -10);

	return 1;
}

