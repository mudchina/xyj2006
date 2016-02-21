// huoyun-qiang.c 【火云枪法】


inherit SKILL;

mapping *action = ({
        ([      "action":
"$N大吼一声，手中$w微扬，一招「风起云涌」，霎时枪影如封墙，\n"
+"有若旎转钢刀般挟以万钧之势封向$n",
                "damage":               30,
                "dodge":                5,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N反身一弹，重重枪影先将敌人身形罩住，而后一招「覆雨翻云」，\n"
+"只见寒芒一闪，$w己闪电般射向$n",
                "damage":               20,
                "dodge":                15,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N使出「火龙腾云」，七道红芒一经泛出有若苍鹰猎兔以雷霆万钧之势，"
+"快愈飘风的刺向$n",
                "damage":               25,
                "dodge":                20,
                "parry":                -10,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"$N$w指地，身形半曲，使出一招「浴火凤凰」，往前射去，\n"+
"只见一道红芒掠过，人枪如流星似的划过空间，冲向$n",
                "damage":               25,
                "dodge":                -10,
                "parry":                -5,
                "damage_type":  "刺伤"
        ]),
         ([      "action":
"$N微一反身，己使出「天火燎原」，舞出万朵火花，只见红光闪闪，\n"+
"$n被罩入一片红光之中",
                "damage":               35,
                "dodge":                20,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N狂喝一声，$w己泛起一道红芒，只见狂风大作，\n"+
"$N枪势一带，这招「火云敝日」摧枯拉朽，击向$n",
                "damage":               15,
                "dodge":                5,
                "parry":                -25,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N$w一抖，枪影满天，$n顿时被罩在这招「晚霞满天」的一片火光之中",
                "damage":               20,
                "dodge":                15,
                "parry":                0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N$w一抖，向$n脚下磋来，搅起一片尘土，这招「火烧连营」逼得$n连连后退，无处落脚",
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
notify_fail("你的内力不够，没有办法练火云枪。\n");
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
        write("你按着所学练了一遍火云枪。\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/huoyun-qiang/" + func;
}

