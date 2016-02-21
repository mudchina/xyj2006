// 惊雷鞭法，jinglei-mace.c
// created 5-19-97 pickle

/*
惊雷鞭法    dodge  -5    parry  -5    damage  25
此鞭法(硬鞭，事实上是锏法)讲究气势力度，为名将尉
迟恭之拿手绝技，使动开来威风凛凛，势难近人。
*/

// 海阔天空，顶天立地，舌绽春雷，
// 乌云密布，电闪雷鸣，八方风雨，
// 狂风骤雨，天公洒泪，暴雨滂沱
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
	([	"name":			"海阔天空",
		"action":
"$N身形促进，手中$w带起一阵劲风，朝$n当头扫去",
		"dodge":		-5,
		"parry":		5,
		"damage":		40,
		"damage_type":		"砸伤"
	]),
	([	"name":			"顶天立地",
		"action":
"$N猛吸一口真气，身形暴长，似乎瞬息间长高了一个头。借此威猛之势，\n"
"$N手中$w一招"+MAG"「顶天立地」"NOR"，向$n兜头盖脑地砸去",
		"dodge":		-5,
		"parry":		-15,
		"damage":		55,
		"damage_type":		"砸伤"
	]),
	([	"name":			"舌绽春雷",
		"action":
"$N气运丹田，一声怒吼，好似平地起了个焦雷，震得$n耳中嗡嗡直响。\n"
"趁此良机，$N抡起手中$w，砸向$n的$l",
		"dodge":		-15,
		"parry":		-5,
		"damage":		45,
		"damage_type":		"砸伤"
	]),
	([	"name":			"乌云密布",
		"action":
"$N把$w舞得风雨不透，慢慢向$n逼去。\n"
"$n只见一团黑影向自己滚来，实在不知如何招架",
		"dodge":		10,
		"parry":		-10,
		"damage":		40,
		"damage_type":		"震伤"
	]),
	([	"name":			"电闪雷鸣",
		"action":
"$N将$w抡了个圆圈，隐隐带起风雷之声，好似在找落锏之处。\n"
"突然间，只见一道寒光闪过，$w已到$n咽喉。好一招"+HIM"「电闪雷鸣」"NOR"",
		"dodge":		-10,
		"parry":		0,
		"damage":		45,
		"damage_type":		"戳伤"
	]),
	([	"name":			"八方风雨",
		"action":
"$N用一招"+HIR"「八方风雨」"NOR"，弓身围$n四周疾转。\n"
"混乱中只见四面八方都是锏影，似乎已将$n逼入死路",
		"dodge":		-5,
		"parry":		-5,
		"damage":		35,
		"damage_type":		"震伤"
	]),
	([	"name":			"狂风骤雨",
		"action":
"$N有如中了邪，丝毫不顾自身安危，手中$w好似狂风骤雨般击向$n",
		"dodge":		-10,
		"parry":		5,
		"damage":		50,
		"damage_type":		"砸伤"
	]),
	([	"name":			"天公洒泪",
		"action":
"激战中只见一条黑影冲逃邙去。$n一愣，已有无数锏影朝当头砸到。\n"
"$N的"+HIW"「天公洒泪」"NOR"用的恰到好处，端地是鬼神莫测",
		"dodge":		0,
		"parry":		-15,
		"damage":		50,
		"damage_type":		"砸伤"
	]),
	([	"name":			"暴雨滂沱",
		"action":
"$N挺起$w向$n的$l缓缓戳去，显然锏上灌入了内力。\n"
"突然间，$w一分为三，向$n身上三个不同的部位飞刺！\n"
"$n被这招"+HIC"「暴雨滂沱」"NOR"逼得连连后退，试图躲开$N的追击",
		"dodge":		-5,
		"parry":		-5,
		"damage":		45,
		"damage_type":		"砸伤"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力修为不够深，不能学惊雷鞭法。\n");
	   if( (string)me->query_skill_mapped("force")!= "lengquan-force")
     return notify_fail("惊雷鞭法必须配合将军府的冷泉神功才能练。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "mace" )
		return notify_fail("手里没有兵器怎么练？\n");
	return 1;
}
	
int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练惊雷鞭法有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练惊雷鞭法有走火入魔的危险。\n");
	me->receive_damage("kee", 10);
	me->add("force", -5);
	message_vision("只见一团黑影中走出$N，原来刚练完惊雷鞭法。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="mace"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
string perform_action_file(string func)
{
return CLASS_D("fighter") + "/jinglei-mace/" + func;
}
