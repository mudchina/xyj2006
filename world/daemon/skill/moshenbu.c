// jindouyun.c

inherit SKILL;

string *dodge_msg = ({
	"$n不退反进，向前踏出一步，逼得$N中途撤招。\n",
	"$n左跨一步，右跨一步，一时间身影似乎变成了三个，把$N晃得眼花缭乱。\n",
	"$n身体后仰，一个「铁板桥」，闪开了$N这一招。\n",
	"$n脚步一错，一旋身闪到了$N的背后。\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练魔神步法。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练魔神步法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -2);
	return 1;
}
