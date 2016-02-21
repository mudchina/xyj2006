// baguazhen.c
//【八卦阵法】weiqi... 980304
//can consider future development of 阵法.
//乾坤震坎艮离巽兑

inherit SKILL;

string *dodge_msg = ({
	"$n侧身一退，踏入左面的乾门，恰巧躲过了$N这一招。\n",
	"可是$n身形一晃，突然之间转到了坤门，出现在$N的身后。\n",
	"只见$n连着几个旋身，自坎而离，过兑门入震门，脚下一点立在了艮门。$N之攻势顿时化为乌有。\n",
	"说时迟那时快，$n在千钧一发之际不退反进，扑入巽门之中，逃过了$N这一招。\n",
	"$n就势一转，退入右侧坎门之中，远远地躲了开来。\n",
	"$n哈哈大笑几声，一个跟头翻入兑门，轻轻将来势尽数化解。\n",
	"但是$n轻轻一纵，顿时没了踪影。$N定睛一看，原来$n早躲到了离门之中。\n",
	"$n身形斜飞，落入震门之中，毫不费力地化解了$N这一招。\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("你的内力不够，没有办法学八卦阵法。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30)
		return notify_fail("你现在脚下虚浮，先休息一阵吧。\n");
	if((int)me->query("force") < 3 )
		return notify_fail("你现在内力不够，难以继续练下去了。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
