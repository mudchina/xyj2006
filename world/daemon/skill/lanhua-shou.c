//兰花手


inherit SKILL;

mapping *action = ({
	([	"action":		"$N二手合十，一式「莲花座」，双拳蓄势而发，击向$n的$l",
		"dodge":		-10,
		"parry":		10,
		"force":		100,
		"damage_type":	"刺伤",
                        "weapon":		"右手食指",
	]),
	([	"action":		"$N腾空飞起，一式「五指山」，攻向$n的身前身后",
		"dodge":		-20,
		"parry":		-20,
		"force":		140,
		"damage_type":	"内伤",
                        "weapon":		"左手", 
	]),
            ([	"action":		"$N一式「观音渡」，两手十指虚点$n的全身三十六道要穴",
		"dodge":		30,
		"parry":		-10,
		"force":		200,
		"damage_type":	"内伤",
                        "weapon":		"左手",
	]),
            ([	"action":		"$N两目内视，双手内笼，一式「天龙唱」，四面八方响起震人心魄的龙吟",
		"dodge":		10,
		"parry":		-10,
		"force":		120,
		"damage_type":	"砍伤",
                        "weapon":		"右手",
	]),
	([  "action": 	"$N似笑非笑，双拳无形无定，一式「如来笑」，骤然击向$n的前胸",
                "dodge":                -50,
                "parry":                -50,
                "force":                120,
                "damage_type":  "内伤",
	 ]),
});

int valid_learn(object me)
{
        if( (string)me->query_skill_mapped("force")!= "jiuyin-xinjing")
     return notify_fail("兰花手必须配合九阴心经才能练。\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练兰花手必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("lanhuashou_per");
        if( !me->query_temp("lanhuashou_per") ) {
        return action[random(5)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{

        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习兰花手。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍兰花手。\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("pansi") + "/lanhua-shou/" + func;
}

