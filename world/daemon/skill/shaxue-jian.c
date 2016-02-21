// By Canoe  12-12-2000
// Sigh, 脑袋想破了,才弄出来的
#include <ansi.h>;
inherit SKILL;

mapping *action = ({
	([	"name":			"借尸还魂",
		"action":
"$N脸上浮现出一丝诡异的笑容，突然使出「借尸还魂」，$w直刺$n的$l",
		 "force" : 120,
        	"dodge" : -10,
        	"parry" : 5,
       	 	"damage" : 15,
        	"damage_type" : "割伤"
	]),
	([	"name":			"魔尸惊魂",
		"action":
"$N手中$w幻出满天剑影，一招「魔尸惊魂」，无声无息地转到$n背后",
		 "force" : 130,
        	"dodge" : -10,
        	"parry" : 10,
        	"damage" : 20,
        	"damage_type":		"刺伤"
	]),
	([	"name":			"尸山血海",
		"action":
"$N一招「尸山血海」泛出闪闪剑光，映得$n眼花缭乱，平削$n的$l",
		"force" : 140,
       		 "dodge" : -5,
        	"parry" : 5,
        	"damage" : 25,
		"damage_type":		"削伤"
	]),
	([	"name":			"歃血魔尊",
		"action":
"$N使出一招「歃血魔尊」，掌中$w发疯般狂砍，攻得$n心惊胆战",
		"force" : 160,
        	"dodge" : 5,
        	"parry" : 5,
        	"damage" : 30,
		"damage_type":		"刺伤"
	]),
	([	"name":			"魔火焚尸",
		"action":
"$N剑光一闪，一招「魔火焚尸」幻出漫天剑影拢向$n的$l，$n手足无措",
		"force" : 180,
        	"dodge" : 10,
        	"parry" : 5,
        	"damage" : 40,
		"damage_type":		"刺伤"
	]),
	([	"name":			"地火焚天",
		"action":
"$N剑式一变，杀机四布，一招「地火焚天」从下而上,逼得$n没有还手之力",
		"force" : 210,
        	"dodge" : 15,
        	"parry" : 15,
        	"damage" : 50,
		"damage_type":		"割伤"
	]),
	([	"name":			"魔焰吞天",
		"action":
"$N跃起三丈，招式陡变，「魔焰吞天」如惊涛骇浪，卷转电擎而落",
		"force" : 240,
        	"dodge" : 15,
        	"parry" : 15,
        	"damage" : 60,
		"damage_type":		"刺伤"
	]),
	
	([	"name":			"天地人魔",
		"action":
"$N一招「天地人魔」，剑人合一，冲杀过去，突然回手一剑，刺向$n的$l",
		"force" : 270,
       		 "dodge" : 25,
        	"parry" :  25,
		"damage":		70,
		"damage_type":		"刺伤"
	]),
	([	"name":			"天魔一击",
		"action":
"$N口念真决，身形化作一团血雾，使出"HIR"「天魔一击」"NOR"攻向$n",
		"force" : 300,
        	"dodge" : 30,
        	"parry" : 15,
        	"damage": 80,
		"damage_type":		"砍伤"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力修为不够深，白骨歃血剑学了也没用。\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一柄剑才能练习剑法。\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("shaxue-jian");

	if (dod<swo/2)
		return notify_fail("你的身法跟不上剑法，练下去很可能会伤到自己。\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("你体质欠佳，强练白骨歃血剑有害无益。\n");
	if ((int)me->query("force") < 5)
		return notify_fail("你内力不足，强练白骨歃血剑有走火入魔的危险。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N默默回忆了一会儿，然后练了一遍白骨歃血剑。\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
int zhaoshu, level;

zhaoshu = sizeof(action);
level   = (int) me->query_skill("shaxue-jian",1);

if (level < 300 )
zhaoshu--;
if (level < 270 )
zhaoshu--;
if (level < 240 )
zhaoshu--;
if (level < 210 )
zhaoshu--;
if (level < 180 )
zhaoshu--;
if (level < 150 )
zhaoshu--;
if (level < 120 )
zhaoshu--;
return action[random(zhaoshu)];
}

void skill_improved(object me)
{
        if( (int)me->query_skill("shaxue-jian", 1) > 30 
	 && (int)me->query_skill("shaxue-jian", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 200);
	}
}

string perform_action_file(string func)
{
return ("/u/canoe/pfm") + func;
}

