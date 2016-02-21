// ghost-dodge.c 鬼影迷踪步法
#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({

"$n身似鬼魅，足不动，腿不抬，竟然飘然飞起，居然轻描淡写避过了$N这招。\n\n",

"$N一招击至，看似打个正着，却不料$n身形突然消失，一回头，发现竟然已在身后！\n\n",

"只见$n脚步散乱，身形乱晃，$N眼前顿时只剩一团鬼影，不知如何攻击！\n\n" ,

"$n突然加快步法，化作一团烟雾在$N身前身后忽左忽右游走，$N眼花缭乱招招落空。\n\n",

"$n面带诡笑，身体竟似全无重量，看似被击中，却随$N招式飘出，并未受一丝伤害。\n\n",

"$n膝盖不弯，直上直下地跳动，看似极笨拙，却轻而易举地躲开了$N的攻击。\n\n" NOR });


int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 40)
                return notify_fail("你的体力太差了，不能练鬼影迷踪。\n");
        me->receive_damage("kee", 30);
        return 1;
}

