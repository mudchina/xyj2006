//五虎断门刀, wuhu-blade.c
//modified 4-17-97 pickle

/*
五虎断门刀    dodge  0    parry  0    damage  20
江湖中常见之功夫，但大多使得花梢，当非真传。其实
这门功夫是相当实用的。
*/

// 狐假虎威；虎落平阳；骑虎难下
// 饿虎扑食；三人成虎

inherit SKILL;

mapping *action = ({
        ([      "name":                 "饿虎扑食",
                "action":
"$N纵身跃在空中，有如饿虎扑食一般，手中$w借着下落之势，向$n当头劈下",
                "dodge":		0,
		"parry":		0,
                "damage":		15,
                "damage_type":  "劈伤"
        ]),
        ([      "name":                 "三人成虎",
                "action":
"$N展开轻功在$n周围飞奔，疾跑中向$n砍去数刀。\n"
"$n只见三个人影，从三个不同的方向砍来，不由惊慌失措",
                "dodge":		0,
		"parry":		0,
                "damage":		20,
                "damage_type":  "砍伤"
        ]),   
        ([      "name":                 "狐假虎威",
                "action":
"$N一声巨吼，震得$n耳中回声不止。趁此机会，$N一刀削向$n的$l。\n"
"原来是五虎断门刀中的杀手「狐假虎威」",
		"dodge":		0,
		"parry":		0,
                "damage":		25,
                "damage_type":  "割伤"
        ]),   
        ([      "name":                 "虎落平阳",
                "action":
"$N左掌护身，滚倒在地上，右手$w连连向$n的双脚削去",
                "dodge":		0,
		"parry":		0,
                "damage":		10,
                "damage_type":  "劈伤"
        ]),   
        ([      "name":                 "骑虎难下",
                "action":
"$N站稳马步，运起浑身之力，逼入$w中，向$n发出雷霆一击！\n"
"这招「骑虎难下」名字虽然难听，招数果然有效",
                "dodge":		0,
		"parry":		0,
                "damage":		30,
                "damage_type":  "劈伤"
        ]),
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，不能学五虎断门刀， 多练些内力再来吧。\n");
        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀才能练刀法。\n");

        return 1;
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的气太低，再练下去会有危险的！\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你的内力不够，无法练习五虎断门刀。\n");
	me->receive_damage("kee", 20);
	me->add("force", -3);
	message_vision("$N按着所学练了一遍五虎断门刀。\n", me);
	return 1;
}

int valid_enable(string usage)
{
        return usage=="blade"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
