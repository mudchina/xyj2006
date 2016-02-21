// yinfeng-zhua.c, 【阴风爪】
// created 9-5-97 pickle
//menpai skill(can be used by some yaomo NPCs)

//  霉气扑鼻，千疮百孔，残缺不全，摇摇欲坠

inherit SKILL;

mapping *action = ({
  ([
    "name":		"「霉气扑鼻」",
    "action":
"$n只觉隐隐传来一阵霉气，正奇怪间，$N的左爪已到$l",
    "force":		50,
    "dodge":		-10,
    "parry":		-10,
    "damage_type":	"抓伤",
  ]),
  ([
    "name":		"「千疮百孔」",
    "action":
"$N笨拙无比地伸爪向$n的$l抓去。这招看似千疮百孔，\n"
"破绽无数，但等$n招架时，却被逼得手忙脚乱，叫苦不迭",
    "force":		100,
    "dodge":		10,
    "parry":		-10,
    "damage_type":	"抓伤",
  ]),
  ([
    "name":		"「残缺不全」",
    "action":
"$N左爪不动，右爪迅捷无比地向$n连施五抓。当$n全神贯注地对付\n"
"这五抓时，$N的右爪已神不知鬼不觉地到了$n的$l",
    "force":		70,
    "dodge":		10,
    "parry":		10,
    "damage_type":	"抓伤",
  ]),
  ([
    "name":		"「摇摇欲坠」",
    "action":
"$N突然间跃起数尺，居高临下向$n抓来。$n虽然看出\n"
"$N胸腹间空门大开，却被这「摇摇欲坠」的凌厉攻势逼得回手自救",
    "force":		70,
    "dodge":		-10,
    "parry":		10,
    "damage_type":	"抓伤",
  ]),
});

int valid_learn(object me)
{
    if( me->query_temp("weapon") || me->query_temp("secondary_weapon"))
        return notify_fail("练阴风爪必须空手。\n");
    return 1;
}

int valid_enable(string usage) { return usage=="unarmed"||usage=="parry"; }

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if (me->query("class") != "yaomo")
		return notify_fail("你又没爪子，怎么练阴风爪？\n");
	if( (int)me->query("sen") < 40)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
	if( (int)me->query("kee") < 40 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}
