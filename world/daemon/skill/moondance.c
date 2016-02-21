//【冷月凝香舞】 moondance.c
// cglaem...12/07/96.

inherit SKILL;

string *dodge_msg = ({
     "$n低头细数裙褶，情思困困，步法回旋之际似乎娇柔无力，却将$N攻势一一化于无形。\n",
     "只见$n一个转身，忽然回眸一笑。$N一楞之下，哪里还有人在。\n",
     "可是$n婉尔一笑，不退反进，身形径向$N飘来。\n$N只觉一股甜香入鼻，这一招竟无着力之处。\n",
     "$n身法轻灵，腰肢几拧，居然幻出斑驳月影。$N眼一花，哪里分得出是人，是影。\n",
     "$n裙裾飘飘，白衣姗姗，已然从$N头顶飞过，这般女神端丽之姿，仙子缥缈之形，$N不由得看呆了！\n",
     "$n脚步轻盈，风姿嫣然，身子便如在水面上飘浮一般掠过，不等$N劲风袭到，已悄然隐去。\n",
     "$n纤腰微颤，带飞如虹，轻轻将$N的劲力拨在一旁，尽数化解。\n",

});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
	if( (string)me->query("gender") != "女性" )
		return notify_fail("冷月凝香舞只有女性才能练。\n");
	if( (int)me->query("spi") < 10 )
		return notify_fail("你的灵性不够，没有办法练冷月凝香舞。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，不能练冷月凝香舞。\n");
	me->receive_damage("sen", 30);
	return 1;
}
