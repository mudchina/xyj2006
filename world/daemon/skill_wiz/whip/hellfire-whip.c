//【烈火鞭】hellfire-whip.c

/*
烈火鞭    dodge  -10    parry  -10    damage  20
烈火鞭善缠绕攻敌，一旦被卷入其攻击范围则极难幸免，
且此鞭曲折转拐，来去无踪，要招架抵挡也甚为不易。
特点是杀伤不大。

Attention: 烈火鞭只有前六招，而第七，八两招是苦丧棒
和惊魂掌中，用来 Perform 的，而玩家平常并不会用到。
*/


inherit SKILL;

mapping *action = ({
        ([      "name":                 "地狱烈火",
                "action":
"$N手腕一翻，$w抖得笔直，带出一股锐啸猛刺$n$l",
                "dodge":                0,
                "parry":                -5,
                "damage":               15,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":               
"$N大喝一声，手中$w宛若矫龙飞在半空，大有「横空出世」的气概。\n$n只觉得全身俱在$w笼罩之下",
                "dodge":                -20,
                "parry":                -20,
                "damage":               30,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":
"$N右手一引，$w贴地而飞，再疾卷而上，仿佛带出了地狱中的烈火，夹头夹脑地扑向$n",
                "dodge":                -5,
                "parry":                -15,
                "damage":               25,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":
"也不知$N如何动了一动，但见长空中青光一闪，$n只觉$w已击上了$l",
                "dodge":                -15,
                "parry":                -5,
                "damage":               15,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":
"$N身形往前滑出，手中$w霹啪有声，一圈套一圈地卷向$n",
                "dodge":                -5,
                "parry":                0,
                "damage":               15,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "地狱烈火",
                "action":
"长笑声中$N一个倒翻，手中$w急绞，但见方圆丈许飞沙走石，劲气纵横！\n$n不知如何才能脱困而出，脸都绿了",
                "dodge":                -15,
                "parry":                -20,
                "damage":               25,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "小楼夜哭",
                "action":
"$N喉咙里发出几声嚎叫，高举$w，不顾一切地冲向$n，几乎与$n贴脸而立！\n手中$w却悄无声息地刺向$n的$l，好厉害的「小楼夜哭」",
                "dodge":                -15,
                "parry":                -15,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "name":			"秋坟鬼唱",
		"action":		"$N左手虚晃，右掌飘飘，掌心呈碧绿，一招「秋坟鬼唱」击向$n$l",
                "dodge":                -10,
                "parry":                -10,
                "damage":                30,
                "damage_type":  "瘀伤"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，没有办法练烈火鞭。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                return notify_fail("你必须先找一根鞭子才能练烈火鞭。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query("HellZhen");
	if( !me->query("HellZhen") ) {
        return action[random(6)];
	}else {
	return action[i];
	}
}
		

int practice_skill(object me)
{
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习烈火鞭。\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
        write("你按着所学练了一遍烈火鞭。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


string perform_action_file(string func)
{
return CLASS_D("ghost") + "/hellfire-whip/" + func;
}

