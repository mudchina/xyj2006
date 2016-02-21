//【龙神身法】 dragonstep.c
// cglaem...12/19/96.

inherit SKILL;

string *dodge_msg = ({
	"但是$n身形一晃，从$N身边轻轻滑过。\n",
            "只见$n往后一退，隐入一团白雾中，$N这一招顿时没了目标。\n",
            "$n一转身，一团白雾冒起，隔断了$N的攻势。\n",
            "$n左脚轻轻在地上一点，如五爪金龙般腾在半空，避开了$N的攻势。\n",
            "$n似乎有点躲闪不及，眼看就要中招。但是$N眼前金光一闪，不知怎的就扑空了。\n",
});

int valid_enable(string usage) { return (usage=="dodge"); }

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if (me->query("class") != "dragon")
		return notify_fail("你非龙族怎能练龙神身法？\n");
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的气或内力不够，不能练龙神身法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
