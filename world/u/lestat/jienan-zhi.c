//【劫难指】 jienan-zhi.c
// lestat...2001
//menpai skill

inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "action":               "但闻哧哧两声，$n脸色突变，$N却悠闲自在，并无动过手的迹象，好一招"+HIY"「瓶花落砚」"NOR"",
		"dodge":		-15,
		"parry":		-15,
		"force":		170,
		"damage_type":	"刺伤",
                        "weapon":		"$N的右手食中指",
	]),
	([	"action":		"$N一式"+HIY"「伽叶微笑」"NOR"，双手食指交叉，指端射出一缕罡气，穿过$n的$l",
		"dodge":		-25,
		"parry":		-25,
		"force":		180,
		"damage_type":	"刺伤",		
                        "weapon":		"$N的右手食指",
	]),
	([	"action":		"$N左掌竖立胸前，一式"+HIY"「佛祖拈花」"NOR"，右手食指扣住拇指，轻轻对着$n一弹",
		"dodge":		-15,
		"parry":		-15,
		"force":		160,
		"damage_type":	"刺伤",
                        "weapon":		"$N的右手食指",
	]),
	([	"action":		"$N右手伸出，十指叉开，一式"+HIY"「花开见佛」"NOR"，小指拂向$n的太渊穴",
		"dodge":		-25,
		"parry":		-15,
		"force":		120,
		"damage_type":	"刺伤",
                        "weapon":		"$N的左手食指", 
	]),
            ([	"action":		"$N微微一笑，一招"+HIY"「雪地红莲」"NOR"，衣袖连摆，指劲随机弹出，叫人琢磨不透，无法躲避",
		"dodge":		-15,
		"parry":		-25,
		"force":		100,
		"damage_type":	"刺伤",
                        "weapon":		"$N的右手食指",
	]),
            ([	"action":		"$N一招"+HIY"「无色无相」"NOR"向$n点出，闻得一破空之声，却见$P微笑点头，却再无任何动静",
		"dodge":		-55,
		"parry":		-35,
		"force":		150,
		"damage_type":	"刺伤",
                        "weapon":		"$N的左手拇指和食指",
	]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练劫难指必须空手。\n");
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

	me->receive_damage("sen", 20);
	me->receive_damage("kee", 20);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/jienan-zhi/" + func;
}


