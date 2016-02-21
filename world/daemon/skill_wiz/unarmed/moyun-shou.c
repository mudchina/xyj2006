//摩云手


inherit SKILL;

mapping *action = ({
	([	"action":		"$N一招「螳螂捕蝉式」，左手抓向$n的丹田，就在$n回身自防的一瞬间，右手却已掐上了$n的$l",
		"dodge":		10,
		"parry":		10,
		"force":		160,
		"damage_type":	"刺伤",
                        "weapon":		"右手食指",
	]),
	([	"action": "$N双手一翻，出「梅花五朵」，双手如穿花蝴蝶一般上下翻飞。\n$n看花了眼，刹那间$N已欺身到了眼前",
		"dodge":		5,
		"parry":		-15,
		"force":		180,
		"damage_type":	"内伤",
                        "weapon":		"右手",
	]),
	([	"action":		"只见$N一转身，一指由胁下穿出，疾刺$n的$l，却正是一招「穿针引线」",
		"dodge":		5,
		"parry":		10,
		"force":		100,
		"damage_type":	"刺伤",
                        "weapon":		"左手食指",
	]),
	([	"action":		"$N双掌一错，掌心向外横推而出，这一招「力士推山」带着一股罡风扑向$n的$l",
		"dodge":		20,
		"parry":		20,
		"force":		140,
		"damage_type":	"内伤",
                        "weapon":		"左手", 
	]),
            ([	"action":		"$N一招「乌龙翻江」，左手在空中虚划了个半弧，拍向$n的$l",
		"dodge":		30,
		"parry":		10,
		"force":		70,
		"damage_type":	"内伤",
                        "weapon":		"左手",
	]),
            ([	"action":		"忽听$N一声怒吼，右手高高举起，一式「力劈华山」，砍向$n的$l",
		"dodge":		10,
		"parry":		-10,
		"force":		220,
		"damage_type":	"砍伤",
                        "weapon":		"右手",
	]),
	([  "action": 	"$N双掌一错，左右手突发青红之光，随着一声霹雳，青红两色火球电般地射向了$n",
                "dodge":                -50,
                "parry":                -50,
                "force":                500,
                "damage_type":  "内伤",
	 ]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练摩云手必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("moyunshou_per");
        if( !me->query_temp("moyunshou_per") ) {
        return action[random(6)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习摩云手。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍摩云手。\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/kusong/moyun-shou/" + func;
}

