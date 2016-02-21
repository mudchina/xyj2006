// 灵蝠五式

inherit SKILL;

// 灵蝠出洞，夜遇苍鹰，良禽择木，笨鸟先飞，蝠去无踪

string *dodge_msg = ({
	"$n身形一缩，一招「夜遇苍鹰」，身形朝暗处遁去。\n",
	"$N正要击中$n之时，忽然只见$n以极快的身法向后退去，\n"
	"霎时间已经不见踪影。原来是救命绝招「蝠去无踪」。\n",
	"但是$n似乎早已觉出不对，在$N发招之前就已以「笨鸟先飞」高跃避之。\n",
	"$N的凌厉攻势似乎以把$n逼入一个死角。$n一咬牙，不退反进，\n"
	"一招「灵蝠出洞」，果然奏效，挡开了$N。\n",
	"$n身形一闪，似欲向右避去。$N正待追击，只见$n已经向左跃开。\n"
	"好一招「良禽择木」！把$N闹的狼狈不堪。\n",

});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，不能学习灵蝠五式的绝招。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的气太低，再练下去太危险了！\n");
	if ((int)me->query("force") < 100)
		return notify_fail("你的内力不足，强练灵蝠五式会走火入魔。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
