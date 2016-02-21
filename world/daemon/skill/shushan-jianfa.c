//Cracked by Roath

#include <ansi.h>

inherit SKILL;
mapping *action = ({
([      "action" : "$N一招「白云出岫」，手中$w点向$n的$l",
        "damage" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「有凤来仪」，$w闪烁不定，刺向$n的$l",
        "damage" : 25,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「天绅倒悬」，$w自上而下划出一个大弧，向$n劈砍下去",
        "damage" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，手中$w使出「白虹贯日」直刺$n的$l",
        "damage" : 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N手中的$w一晃，使出「苍松迎客」直刺$n的$l",
        "damage" : 50,
        "damage_type" : "刺伤"
]),
});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("zixia-shengong", 1) < 20)
                return notify_fail("你的紫霞神功火候太浅。\n");
        if ((int)me->query_skill("hunyuan-zhang", 1) < 20)
                return notify_fail("你的混元掌火候太浅。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("你的体力不够练蜀山剑法。\n");
        me->receive_damage("kee", 20);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shushan") + "/shushan-jianfa/" + action;
}
