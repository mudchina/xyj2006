
//wuxing-quan.c【五行拳】, weiqi...980213

inherit SKILL;

mapping *action = 
({
	([	"action":
"$N使出五行拳中的“金字诀”，提气沉马，双拳对合，\n居然嗡！地一声发出金器交鸣之声。便在各人心神一震之间，\n$N的两只拳头已经砸到了$n的$l",
		"dodge":		5,
		"parry":		5,
		"force":		110,
		"damage_type":		"砸伤"
	]),
	([	"action":
"只见$N脚步变幻不定，身形一晃再晃，双拳径破$n之防守，痛击$n$l！\n人传五行拳中的“水字诀”无孔不入，确是名不虚传",
		"dodge":		5,
		"parry":		5,
		"force":		80,
		"damage_type":		"砸伤"
	]),
	([	"action":
"$N使出“木字诀”，一时间似是脚步沉滞，身法僵硬。旋即大喝一声，\n带着一副刀枪不入的神态和身扑向$n，双手成爪一前一后抓向$n$l",
		"dodge":		5,
		"parry":		5,
		"force":		60,
		"damage_type":		"抓伤"
	]),
	([	"action":
"$N双拳交击，身形连转，虽无一拳直接击向$n，五行拳中的“火字诀”\n却把$N的拳势发挥得淋漓尽致，带出的劲气便如烈火般一道又一道地扑面而来",
		"dodge":		5,
		"parry":		5,
		"force":		60,
		"damage_type":		"内伤"
	]),
	([	"action":
"$N暗运真气，双腿便似钉在地上一般，接连五六个直拳一气打向$n$l！\n五行拳中的“土字诀”既不高妙，亦不凶险，却有一股务求必中的狠气",
		"dodge":		5,
		"parry":		5,
		"force":		80,
		"damage_type":		"砸伤"
	]),
});

int valid_learn(object me)
{
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练五行拳必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}
