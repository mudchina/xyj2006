// liangyi-sword. 【两仪剑法】

/*
两仪剑法    dodge  -10    parry  -10    damage  15
此剑法为菩提祖师年少之时偶然悟出，共八式，分为阴阳二部，威力不算强，但练习
时一招一式与体内阴阳之气相合，于内功修为颇有益处。
*/

// 阴：幻，绕，缠，点 (dodge: -15, parry: -15, damage 10)
// 阳：劈，砍，刺，扑 (dodge: -5, parry: -5, damage 20)
inherit SKILL;

mapping *action = ({
	([	"name":			"幻",
		"action":
"$N一抖手中的$w，瞬间刺出三十六剑，$n顿时手忙脚乱，分不清虚实",
		"dodge":		-10,
                "parry":                -20,
		"damage":		5,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "绕",
		"action":
"$N一剑刺向$n，$n急忙向旁边一闪，\n"
"不料$N一运劲儿，手中的$w突然弯了过来，转而刺向$n的$l",
		"dodge":		-20,
                "parry":                -10,
		"damage":		10,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "缠",
		"action":
"$N手中$w连续划出几个光环，一阵吸力带得$n向前踏出一步，$N左手剑指已刺向$n的$l",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "点",
		"action":
"$N一转身，背向$n，手中$w从腋下反手刺向$n的$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		10,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "劈",
		"action":
"$N举起手中的$w，自上而下，劈向$n的$l",
		"dodge":		0,
                "parry":                -10,
		"damage":		25,
		"damage_type":		"割伤"
	]),
        ([      "name":                 "砍",
		"action":
"$N身子一侧，手中的$w平着挥出，砍向$n的$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":      		15, 
                "damage_type":  	"割伤"
        ]),
	([      "name":                 "刺",
		"action":
"$N向前踏出半步，手中$w中宫直进，刺向$n的前心",
                "dodge":                -10,
                "parry":                0,
                "damage":     		20,
                "damage_type":  	"刺伤"
        ]),
	([      "name":                 "扑",
                "action":
"$N双脚一顿，身子凌空，头下脚上，手中$w刺向$n的头顶",
                "dodge":                -5,
                "parry":                -5,
                "damage":               20,
                "damage_type":  	"刺伤"
        ]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练两仪剑法。\n");

//	if( (string)me->query_skill_mapped("force")!= "moonforce")
//		return notify_fail("风回雪舞剑法必须配合昆仑山玉女峰的圆月心法才能练。\n");

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
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习两仪剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍两仪剑法。\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}
