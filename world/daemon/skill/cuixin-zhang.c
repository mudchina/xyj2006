//【摧心掌】 jinhun-zhang.c
//menpai skill
//lestat 修改于2001 for大雪山
#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":
"只见$N凝神运气，左手护胸，右手掌心呈暗红，一招"+RED"「伫倚危楼风细细」"NOR"带着一股腥热之气拍向$n$l",
                "dodge":                -35,
                "parry":                -45,
	        "force":		120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N脚下连换几个方位，双掌一错，使一招"+RED"「草色烟光残照里」"NOR"，右手突然暴涨数尺往$n$l一搭一推",
                "dodge":                -25,
                "parry":                -25,
	        "force":		120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N一招"+RED"「无言谁会凭栏意」"NOR"，手臂就象没长骨头似的往外一曲，快若闪电地击上了$n$l",
                "dodge":                -45,
                "parry":                -35,
	        "force":		120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N一式"+RED"「拟把疏狂图一醉」"NOR"，双掌在空气中划得嗤嗤着响！劲气纵横中突然飞出一掌，悄无声息地拍向$n$l",
                "dodge":                -45,
                "parry":                -5,
	        "force":		100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"只听$N一声清啸，，一招"+RED"「为伊消得人憔悴」"NOR"，身形如流水，掌势若浮云，暗光流转中延绵不绝地拍向$nl周身要害",
                "dodge":                -25,
                "parry":                -50,
	        "force":		120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
HIW"$N接连几个急转，身形如陀螺般向$n"NOR+HIW"滚去，转一圈击一掌，掌掌不离$n"NOR+HIW"的$l"NOR,
                "dodge":                -50,
                "parry":                -100,
	        "force":		360,
                "damage_type":  "瘀伤"
        ]),

});

int valid_learn(object me)
{
	if( (string)me->query_skill_mapped("force")!= "ningxie-force")
     return notify_fail("摧心掌必须配合冰谷凝血功才能练。\n");
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练摧心掌必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("cuixin_per");
        if( !me->query_temp("cuixin_per") ) {
        return action[random(5)];
        }else {
        return action[i];
        }
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
string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/xueshan/cuixin-zhang/"+func;
}

