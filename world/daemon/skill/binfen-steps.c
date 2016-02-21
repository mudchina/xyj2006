// binfen-steps.c 缤纷步法
// edited by mind

inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
        "$n一招"+RED"「晴日催花暖欲然」"NOR+"，不带烟火，轻轻巧巧地避了开去。\n",
        "只见$n身法一折三迭，一式"+MAG"「日长蝴蝶飞」"NOR+"早已避在七尺之外。\n",
        "$n使出"+HIC"「桃李依依春黯度」"NOR+"，轻轻松松地闪过。\n",
        "$n左足一点，一招"+HIW"「带恨眉儿远岫攒」"NOR+"潇洒出尘，避了开去。\n",
        "可是$n使一招"+HIY"「粉英金蕊自低昂」"NOR+"，身子轻轻飘了开去。\n",
        "$n身影连展，已经藉一招"+HIG"「渐岘绿娇红姹」"NOR+"迷惑得$N撤招自保。\n",
        "但是$n一招"+HIW"「醺酣争撼白榆花」"NOR+"使出，早已绕到$N身後！\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 10 )
                return notify_fail("你的内力不够，没有办法练缤纷步法。\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的气或内力不够，不能练缤纷步法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}


