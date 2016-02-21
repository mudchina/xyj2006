//【轮回杖】lunhui-zhang.c
inherit SKILL;

/*
轮回杖    dodge  5    parry  -10    damage  25
佛门看家武功，用意于以杀止杀，杖沉力猛，杀伤不弱。
*/

mapping *action = ({
        ([      "name":                 "报应不爽",
                "action":
"$N口宣佛号，面色庄严，一招「报应不爽」手中$w长驱直入，迳刺$n$l",
                "dodge":                -10,
		"parry":               -5,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "大限将至",
                "action":
"$N手中$w一荡，使出「大限将至」，但见一道杖影隐隐约约，若有若无地向$n压下",
                "dodge":                15,
		 "parry":               -15,
                "damage":               20,
                "damage_type":  "砸伤"
        ]),
        ([      "name":                 "回头是岸",
                "action":
"只见$N手中$w疾横，斗地点出！这招「回头是岸」轻灵飘逸，\n$n眼见杖风袭来，竟不知如何是好",
                "dodge":                20,
		"parry":               -20,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "在劫难逃",
                "action":
"$N大喝一声，手中$w向$n兜头击落，兵器未至，已将$n各处退路封死，好一招「在劫难逃」",
                "dodge":                -5,
		"parry":               0,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),   
        ([      "name":                 "天网恢恢",
                "action":
"$N倒提$w，轻轻一纵，一招「天网恢恢」从$n意想不到的地方刺出，$n顿时手足无措，狼狈万分",
                "dodge":                -10,
		"parry":               -5,
                "damage":               15,
                "damage_type":  "刺伤"
        ]),   
        ([      "name":                 "再堕轮回",
                "action":
"$N脸上突现煞气，举起手中$w，猛向$n$l击落，这招「再堕轮回」出手又快又狠",
                "dodge":                20,
		"parry":               -15,
                "damage":               35,
                "damage_type":  "砸伤"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("你的内力不够，没有办法学轮回杖，等内力提高了再来吧。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "staff" )
                return
notify_fail("你必须先找一条禅杖才能学轮回杖。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="staff")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return
notify_fail("你的内力或气不够，没有办法练习轮回杖。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍轮回杖。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("bonze") + "/lunhui-zhang/" + func;
}

