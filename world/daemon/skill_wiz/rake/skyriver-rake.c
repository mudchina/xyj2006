// skyriver.c 【天河钯法】 by snowcat

/*
天河法    dodge  -30    parry  -15    damage  25
此钯为天蓬水神－－猪八戒所创。与其攻守之术相比，其招架
之力略胜一筹。
*/

// 三花聚顶  五气朝元
// 意闲性拙  混沌迷心 
// 酒醉意沉  东撒西泼
// 逞雄广寒  戏耍嫦娥
inherit SKILL;

mapping *action = ({
	([	"action":
"$N哼一声使出「三花聚顶」，凌空跃起飞身自上而下$w往$n的$l只一筑",
		"dodge":		-45,
		"parry":		-15,
		"damage":		15,
		"damage_type":	"筑伤"
	]),
	([	"action":
"突然$N倒退几步反身收回丹田，一招「五气朝元」，$w半空划出一阵旋风身砸向$n的$l",
		"dodge":		-15,
		"parry":		-10,
		"damage":		35,
		"damage_type":	"筑伤"
	]),
	([	"action":
"$N恍恍惚惚身子一晃丢下$w，却冷不防一个「意闲性拙」双臂斜向大回转扫将过来，$n顿时慌了手脚",
		"dodge":		-20,
		"parry":		-20,
		"damage":		25,
		"damage_type":	"筑伤"
	]),
	([	"action":
"$N将手中$w收起飞步跳到$n身外，劈头一个「混沌迷心」，$n连忙急转身，只见$w离$l竟只有三分之毫厘",
		"dodge":		-40,
		"parry":		-5,
		"damage":		15,
		"damage_type":	"筑伤"
	]),
	([	"action":
"$N两眼惺忪紧握$w一个踉跄，$n尚未醒悟，早已有一招「酒醉意沉」直逼向$n的$l",
		"dodge":		-35,
		"parry":		-25,
		"damage":		35,
		"damage_type":	"筑伤"
	]),
	([	"action":
"$n忽然不见$N，猛一抬头只见$N轮园了$w一式「东撒西泼」，急风骤雨一般径直扫向$n$l",  
		"dodge":		-25,
		"parry":		-10,
		"damage":		20, 
		"damage_type":	"筑伤"
	]),
	([	"action":
"$N拿出一招「逞雄广寒」，跳出圈外复又俯身撞入圈内，只见$w上下翻飞以迅雷不及掩耳之势砸向$n的$l",
		"dodge":		-25,
		"parry":		-20,
		"damage":		30,
		"damage_type":	"筑伤"
	]),
	([	"action":
"$N大笑一声，眯起双眼一招「戏耍嫦娥」，耍出手中$w又反手一捞，$w已劈头筑向$n",
		"dodge":		-35,
		"parry":		-15,
		"damage":		25,
		"damage_type":	"筑伤"
	]),
	
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 40 )
		return notify_fail("你的内力不够，没有办法练天河钯法。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "rake" )
		return notify_fail("你必须先找一根钯才能练钯法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="rake" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习天河钯法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按照所学练了一遍天河钯法。\n");
	return 1;
}
