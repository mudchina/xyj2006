// snowsword. 【风回雪舞剑法】

/*
风回雪舞剑法    dodge  -20    parry  -10    damage  15
此剑法迅急若风回，轻灵似雪舞，敌手极难躲闪招架，多为
气短力弱之女子所喜。
*/

// 寒芳留照魂应驻，碗凝深翠拂平沙
// 攒花染出几霜痕，霜印传神梦也空
// 篱筛破落锁玲珑，暗香浮动影黄昏
// 风波不信菱枝弱
inherit SKILL;

mapping *action = ({
	([	"action":
"$N使一招「寒芳留照魂应驻」，手中$w化为一道疾光刺向$n的$l",
		"dodge":		-5,
                "parry":                -10,
		"damage":		10,
		"damage_type":	"刺伤"
	]),
	([	"action":
"只见$N几个急转，使出「晚凝深翠拂平沙」，一声娇喝中剑光冲天而起，扫向$n的$l",
		"dodge":		-35,
                "parry":                -5,
		"damage":		20,
		"damage_type":	"割伤"
	]),
	([	"action":
"$N淡淡一笑，一式「攒花染出几霜痕」舞出无数幻影，$n只觉得阵阵幽香四面袭来，却不知该如何闪躲",
		"dodge":		-10,
                "parry":                -15,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
	([	"action":
"$N手中$w轻轻一抖，一式「霜印传神梦也空」幻出一遍寒光罩向$n。$n只觉得连呼吸都被冻住了",
		"dodge":		-30,
                "parry":                -5,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
	([	"action":
"$N手中$w再一抖，只见寒光点点，飘浮不定。\n这一招「篱筛破月锁玲珑」只看得$n眼花缭乱，哪里还能招架",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
        ([      "action":
"$n只觉得一缕冷香掠过，$N已悄然间飘至$n身后，剑心直指$n的后胸，正是一式「暗香浮动月黄昏」",  
                "dodge":                -35,
                "parry":                -5,
                "damage":      		20, 
                "damage_type":  "刺伤"
        ]),
	([      "action":
"$N不闪不避，一式「风波不信菱枝弱」，神色娴雅，蓄势待发，一道澄如秋水、寒似玄冰的剑光直指$n破绽所在",
                "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "刺伤"
        ]),
	
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练风回雪舞剑法。\n");

	if( (string)me->query_skill_mapped("force")!= "moonforce")
		return notify_fail("风回雪舞剑法必须配合昆仑山玉女峰的圆月心法才能练。\n");

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
		return notify_fail("你的内力或气不够，没有办法练习风回雪舞剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍风回雪舞剑法。\n");
	return 1;
}
string perform_action_file(string func)
{
return CLASS_D("moon") + "/snowsword/" + func;
}

