//【月牙铲】yueya-chan.c 
inherit SKILL;

/*
月牙铲法    dodge  5    parry  -10    damage  25
月牙铲法使动开来甚为凶险，亦善于击破敌手防卫。缺点是
笨重异常。
*/

mapping *action = ({
        ([      "name":                 "",
                "action":
"$N斜步飞身向上，手中$w迎风一晃，闪电般劈向$n的后脑",
                "dodge":                0,
		"parry":		-20,
                "damage":               25,
                "damage_type":  "劈伤"
        ]),
        ([      "name":                 "",
                "action":
"$N缩身一个滚翻，$w随身而走，悄无声息地劈向$n的双脚",
                "dodge":                -10,
		"parry":		0,
                "damage":               25,
                "damage_type":  "割伤"
        ]),
        ([      "name":                 "",
                "action":
"$N双手一振，$w突发血光，「哗，哗，哗」一连三刀向$n刺去",
                "dodge":                5,
		"parry":		-15,
                "damage":               25,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "",
                "action":
"$N脸上突然紫气大做，手中$w挟着一股血腥劈向$n的$l",
                "dodge":                5,
		"parry":	-5,
                "damage":               30,
                "damage_type":  "劈伤"
        ]),   
});


int valid_learn(object me)
{
        object ob;
	int a,b;
	a=(int)me->query_skill("huaxue-force", 1);
	b=(int)me->query_skill("huaxue-blade", 1);

	if( a < b )
		return notify_fail("你的化血神功不够，等提高了再来吧。\n");

        if(  !(ob = me->query_temp("weapon"))
        ||     (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀才能学化血刀法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="parry"||usage=="blade";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	int a,b;
	a=(int)me->query_skill("huaxue-force",1);
	b=(int)me->query_skill("huaxue-blade",1);
	if( a < b )
		return notify_fail("你的化血神功不够，等提高了再来练吧。\n");

        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 10 )
                return notify_fail("你的内力或气不够，没有办法练习化血刀法。\n");

	if(!environment(me)->query("cold"))
		return notify_fail("此地不够阴冷，再练有害无益。\n");

        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍化血刀法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/bibotan/huaxue-blade/" + func;
}

