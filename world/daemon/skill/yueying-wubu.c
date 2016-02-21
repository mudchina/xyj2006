//【月影舞步】 yueying-wubu.c


inherit SKILL;

string *dodge_msg = ({
     "$n一招「歌尽桃花扇底风」，$N只觉眼前一花，不见了$n的身影。\n",
     "$n一招「扫尽浮云风不定」，身形微晃，有惊无险地避开了$N这一招。\n",
     "只见$n身子向后一翻，一招「缥渺孤鸿影」，后荡而起，掠向一旁。\n",
     "$n可是$n一个「流水落花春去也」，长袖翻飞，躲过$N这一招。\n",
     "$n息气上升，意存玉枕，一招「月在青天影在波」，身子飘然而起。\n",
     "$n只见$n一招「月轮穿沼水无痕」，倒掠身形，凌空两个翻转，退出两丈开外。\n",
});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
//	if( (string)me->query("gender") != "女性" )
//		return notify_fail("月影舞步只有女性才能练。\n");
	if( (int)me->query("spi") < 10 )
		return notify_fail("你的灵性不够，没有办法练月影舞步。\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("你的精神太差了，不能练月影舞步。\n");
	me->receive_damage("sen", 30);
	return 1;
}
