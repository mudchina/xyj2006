// xiaoyaoyou.c
//【逍遥游】weiqi... 97.09.13

inherit SKILL;

string *dodge_msg = ({
	"$n不进不退，身形只是稍稍一转，宛若一道轻风般从$N身边掠过。\n",
	"可是$N眼前一花，居然连$n的影子都找不着了。\n忽然从头顶落下一串母鸡下蛋般的笑声，\n原来$n正如一头大鸟般往数丈开外滑翔过去。\n",
	"$n右脚踏了个虚步，双臂一振，顿时乘风而起，居然从$N头顶越了过去。\n",
	"$n左足一点，身形扶摇直上，却在半空中一个转折，轻飘飘地落在了$N身后。\n",
	"但是$n不慌不忙，身子如行云流水般往后一飘...再一飘，早避到了五尺开外。\n",
	"可是$n腰身微耸，顺势一掌按在有力无力之处，\n便如沾在$N这招上的一团轻絮，悠闲自得地将其化解。\n",
	"$n突然大喝一声：且慢！便在$N一楞之间，笑得合不拢嘴地退了开来。\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("你的内力不够，没有办法学逍遥游。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30)
		return notify_fail("你现在太虚弱，练逍遥游当心摔死。\n");
	if((int)me->query("force") < 3 )
		return notify_fail("你现在内力不够，不能乘风而起。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
