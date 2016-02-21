//qianjun-bang.c 【千钧棒法】

/*
千钧棒    dodge  10    parry  -10    damage  30
“金猴奋起千钧棒，玉宇澄清万里埃”，可说是为千钧棒
定下了基调：大开大合，气势磅礴。
*/

inherit SKILL;

mapping *action = ({
        ([      "name":                 "大闹阎罗府",
                "action":
"$N身形稍退，手中$w迎风一抖，朝着$n劈头盖脸地砸将下来",
                "dodge":                5,
		"parry":	-10,
                "damage":               35,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "谈笑退天兵",
                "action":
"$N仰天长笑，看也不看，一招「谈笑退天兵」，随手一棒向$n当头砸下",
                "dodge":                0,
		"parry":		0,
                "damage":               25,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "勇斗二郎神",
                "action":
"$N一个虎跳，越过$n头顶，手中$w抡个大圆，呼！地一声砸向$n$l",
                "dodge":                10,
		"parry":	-20,
                "damage":               35,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "脱困老君炉",
                "action":
"$N一声巨喝，好一个「脱困老君炉」！\n就在$n一愣之间，$N手中$w已是呼啸而至，扫向$n的$l",
                "dodge":               10,
		"parry":	-15,
                "damage":               25,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "醉闹蟠桃会",
                "action":
"$N使出「醉闹蟠桃会」，脚步跄踉，左一棒，右一棒，\n打得$n手忙脚乱，招架不迭",
                "dodge":                -5,
		"parry":		-5,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "三打白骨精",
                "action":
"$N连翻几个筋斗云，手中$w转得如风车一般，\n一连三棒从半空中击向$n顶门",
                "dodge":                5,
		"parry":	-10,
                "damage":               20,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "千钧澄玉宇",
                "action":
"$N手中$w一抖，化为千万道霞光，\n就在$n目眩神摇之时，再一抖，霞光顿收，\n$w已到了$n的$l！这一招有个名堂，叫作「千钧澄玉宇」",
                "dodge":                0,
		"parry":	-20,
                "damage":               40,
                "damage_type":  "砸伤"
        ]),
	([	"name":			"乾坤一棒",
		"action":	"$N将手中$w迎风一挥，幻出万千虚影，蓄力劲发，高举过顶，
$w对准$n的脑门就砸了下去。这一下要是打中，恐怕连大罗金仙也难逃一命",
		"parry":	-30,
		"dodge":	-50,
		"damage":	100,
		"damage_type":  "砸伤"
	]),
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，没有办法练千钧棒法，
多练些内力再来吧。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("你必须先找一根棒子才能练棒法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query_temp("QJB_perform");
	if( !me->query_temp("QJB_perform")) {
		return action[random(7)];
	}else {
		return action[i];
	}
//        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习千钧棒法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        write("你按着所学练了一遍千钧棒法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("puti") + "/qianjun-bang/" + func;
}

