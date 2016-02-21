// bawang-qiang.c 【霸王枪法】

/*
霸王枪法    dodge  10    parry  -10    damage  25
枪为百兵之王，霸王枪威力尤猛，所以此枪善于突破
敌手的严密防守。缺点是不够轻灵，敌手要逃还是很
容易的。
*/

inherit SKILL;

mapping *action = ({
        ([      "action":
"$N使一招「迎门三不过」，手中$w连续刺向$n面门，哽嗓，前心",
                "damage":               30,
                "dodge":                5,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N运足精神，抖起$w，一招「拨草寻蛇」刺向$n$l",
                "damage":               20,
                "dodge":                15,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N一个跨步，使一招「高山流水」，手中$w势若飞瀑刺向$n的$l",
                "damage":               25,
                "dodge":                20,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"$N一按枪把，啪！地一声抖出五朵枪花。上下左右，虚虚实实刺向$n全身要害",
                "damage":               25,
                "dodge":                -10,
                "parry":                -5,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"只见$N一个斜跨，使个「举火烧天势」，手中$w带出一道寒气，由下而上疾挑$n$l",
                "damage":               35,
                "dodge":                20,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N手腕一翻，手中$w从意想不到的角度刺向$n的$l。\n这一招「灵蛇出洞」快若闪电，毒辣无比",
                "damage":               15,
                "dodge":                5,
                "parry":                -25,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N使个「飞鸟投林势」，身形斜飞，从侧面突出一枪，径刺$n$l",
                "damage":               20,
                "dodge":                15,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N似欲退走，可是忽地一个转身，百忙中使出一招「回马枪」，$w一挺刺向$n$l",
                "damage":               30,
                "dodge":                10,
                "parry":                -20,
                "damage_type":  "刺伤"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("你的内力不够，没有办法练霸王枪法。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("你必须先找一柄枪才能练枪法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("你必须先找一柄长枪或者是类似的武器，才能练枪法。\n");

        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 5  )
                return
notify_fail("你的体力不够练这门枪法，还是先休息休息吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍霸王枪法。\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("fighter") + "/bawang-qiang/" + func;
}

