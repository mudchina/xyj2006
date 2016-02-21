//modified by vikee
//2000.10

inherit SKILL;

mapping *action = ({
		([	"name":			"御剑生风",
		"action":
"$N双脚一顿，笔直跃起，手中$w不停地颤抖着，\n"
"笼罩住$n全身。这势「御剑生风」果然是无孔不入",
		"dodge":		-5,
		"parry":		-10,
		"damage":		 25,
		"damage_type":		"刺伤"
	]),
	([	"name":			"御剑如虹",
		"action":
"$N手中$w带起点点寒光，指向$n前胸穴道。$n正专心致志地对付着剑招，\n"
"不料$N左手运力拍向$n的$l。这势「御剑如虹」亦真亦幻，实是难防",
		"dodge":		-5,
		"parry":		15,
		"damage":		25,
		"damage_type":		"震伤"
	]),
	([	"name":			"御剑成龙",
		"action":
"$N在$n四周游走，一招[御剑成龙],手中$w去势飘忽不定，只看得$n眼花缭乱。\n"
"趁此良机，$N于朦朦胧胧中一抖$w，向$n的$l疾挑",
		"dodge":		-15,
		"parry":		10,
		"damage":		25,
		"damage_type":		"刺伤"
	]),
	([	"name":			"御剑行空",
		"action":
"$N仗起手中$w，带出点点寒光，罩住$n的胸腹，只等$n的破绽。\n"
"这招「御剑行空」直如细雨般紧密，$n实在不知$w将要指向自己身上何处",
		"dodge":		25,
		"parry":		-10,
		"damage":		25,
		"damage_type":		"刺伤"
	]),
	([	"name":			"御剑无影",
		"action":
"$N手中$w中宫直进，疾速刺向$n的前心。\n"
"这招「御剑无影」令人耳目一新。$n只觉浑身一紧，$w已刺到了$l",
		"dodge":		-15,
		"parry":		15,
		"damage":		25,
		"damage_type":		"刺伤"
	]),
	([	"name":			"御剑飞腾",
		"action":
"$N手中$w向$n的右手疾刺，但正当$n要招架时，\n"
"$w却突然转向了$n的左足！这招「御剑飞腾」确实神鬼莫测",
		"dodge":		10,
		"parry":		-15,
		"damage":		25,
		"damage_type":		"刺伤"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力修为不够深，御剑术学了也没用。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄剑才能练习剑法。\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("yujianshu");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练御剑术有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练御剑术有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍御剑术。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
	return CLASS_D("shushan") + "/yujianshu/"+func;
}
