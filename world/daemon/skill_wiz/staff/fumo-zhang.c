
//【伏魔杖】fumo-zhang.c, weiqi...980305
inherit SKILL;

/*
伏魔杖    dodge  2.5    parry  -6    damage  23
五庄观功夫。
*/

mapping *action = ({
	([	"action":		"$N运足力气将$w抡了几个大圆，呼！地一声向$n当头砸下",
		"dodge":		15,
		"parry":		-5,
		"damage":		35,
		"damage_type":	"砸伤"
	]),
	([	"action":		"只听$N一声高叫：还不缚手就擒！手中的$w一绞，扫向$n$l",
		"dodge":		0,
		"parry":		-15,
		"damage":		15,
		"damage_type":	"砸伤"
	]),
	([	"action":		"$N使出一招「群魔伏首」，手中的$w带出飞沙走石般的杖风压向$n的$l",
		"dodge":		5,
		"parry":		-5,
		"damage":		30,
		"damage_type":	"砸伤"
	]),
	([	"action":		"只见$N略略一退，旋即一个跨步，$w划出一道弧光刺向$n$l",
		"dodge":		5,
		"parry":		0,
		"damage":		20,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N横持$w，暗运真气，忽然间只见杖头一跳，灵蛇般钻向$n的$l",
		"dodge":		-5,
		"parry":		0,
		"damage":		15,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N的$w望上一挑，中途却使了个巧劲，杖尾嗖！地一翻，砸向$n$l",
		"dodge":		-5,
		"parry":		-10,
		"damage":		25,
		"damage_type":	"砸伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，没有办法学伏魔杖。\n");

	if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "staff" )
		return notify_fail("你必须先找一条禅杖才能学伏魔杖。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="staff"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30 || (int)me->query("force") < 5 )
		return notify_fail("你现在太累了，强练无益。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按着所学练了一遍伏魔杖。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

