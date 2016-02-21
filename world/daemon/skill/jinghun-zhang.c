//【惊魂掌】 jinhun-zhang.c
//menpai skill
//lestat 修改于2001
#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":
"$N左掌微分，右手一长使出一招"+HIB"「小鬼讨债」"NOR"，一只惨白的利爪探向$n的$l",
                "dodge":                15,
                "parry":                15,
                "force":                120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N倏地一个转身，双手往脸上一抹，现出"+HIB"「青面缭牙」"NOR"，张口一吹，一股阴风直扑$n",
                "dodge":                -35,
                "parry":                -35,
                "force":                160,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N身子微斜，随即跨出一步，左手忽掌忽爪使出"+HIB"「群魔乱舞」"NOR"，拍向$n的$l",
                "dodge":                5,
                "parry":                5,
                "force":                180,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出"+HIB"「鬼影幢幢」"NOR"，双手滑溜异常对准$n的$l抓去",
                "dodge":                -5,
                "parry":                -10,
                "force":                180,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N左手虚晃，右掌飘飘，掌心呈碧绿，一招"+HIB"「秋坟鬼唱」"NOR"击向$n$l",
                "dodge":                15,
                "parry":                15,
                "force":                160,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出"+HIB"「饿鬼拦路」"NOR"，凌空跃起，冷不防在落地前对准$n$l踢出一脚",
                "dodge":                -5,
                "parry":                -5,
                "force":                190,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N右手在$n$l划过，随后一招"+HIB"「厉鬼缠身」"NOR"左爪又向同一方位抓到",
	    "dodge":                15,
                "parry":                15,
                "force":                170,
                "damage_type":  "抓伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("练惊魂掌必须空手。\n");
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力太弱，无法练惊魂掌。\n");
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query("HellZhen");
        if( !me->query("HellZhen") ) {
        return action[random(sizeof(action))];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 40)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 40 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("kee", 10);
	me->receive_damage("sen", 10);
	me->add("force", -10);

	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 2 );
                switch(random(3)) {
                        case 0: return "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n";
                        case 1: return "$N劲力一吐，$n的$l发出「喀」地一声爆响！\n";
                        case 2: return "只听见$n的$l「喀」地一声 ...\n";
                }
        }
}

string perform_action_file(string func)
{
return CLASS_D("ghost") + "/jinghun-zhang/" + func;
}

