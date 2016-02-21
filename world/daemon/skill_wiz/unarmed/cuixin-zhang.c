//cuixin-zhang.c 【摧心掌】weiqi
//menpai skill(non manpai NPCs can also use it)

inherit SKILL;

mapping *action = ({
        ([      "action":
"只见$N凝神运气，左手护胸，右手掌心呈暗红，带着一股腥热之气拍向$n$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N脚下连换几个方位，双掌一错，右手突然暴涨数尺往$n$l一搭一推",
                "dodge":                -25,
                "parry":                -25,
	    "force":		70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N身形一滚，一脚凌空踢出，并不攻敌。左掌却在这一带之下从意想不到的角度拍上了$n的$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N嘿嘿一笑，双掌在空气中划得嗤嗤着响！劲气纵横中突然飞出一掌，悄无声息地拍向$n$l",
                "dodge":                5,
                "parry":                5,
	    "force":		100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N轻轻一纵，与$n错身而过。便在这时，$N的手臂就象没长骨头似的往外一曲，快若闪电地击上了$n$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		90,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N接连几个急转，身形如陀螺般向$n滚去，转一圈击一掌，掌掌不离$n的$l",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"只听$N一声清啸，身形如流水，掌势若浮云，暗光流转中延绵不绝地拍向$n周身要害",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N往后一纵，就势使了扫堂腿，双掌却借机反卷而上，长驱直入地击向$n$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		60,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("练摧心掌必须空手。\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
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

