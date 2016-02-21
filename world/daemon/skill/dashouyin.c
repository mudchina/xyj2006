//密宗大手印 dashouyin.c
#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([     "action":
"$N手结"+HIY"「不动根本印」"NOR",意随心动,攻向$n的$1",
               "dodge":     20,
               "parry":     20,
               "force":     200,
               "damage_type":  "淤伤"
        ]),
        ([     "action":
"$N手结「施无畏印」,体内真气流过七经八脉,然后随拳涌出,正中$n的$1",
               "parry":     15,
               "dodge":     15,
               "force":     150,
               "damage_type":  "淤伤"
        ]),
        ([     "action":
"$N二掌竖合,然后结出「内缚印」,缓缓出掌,攻向$n的$1",
               "dodge":     10,
               "parry":     10,
               "force":     200,
               "damage_type":  "淤伤"
        ]),
        ([     "action":
"$N在$n的攻击中漂亮地躲闪,间中结出「外缚印」,力透指间,刺向$n的$1",
               "dodge":     25,
               "parry":     20,
               "force":     120,
               "damage_type":  "刺伤"
        ]),
        ([     "action":
"$N手结「大日轮印」,惊人气劲排空切向$n",
               "dodge":     -5,
               "parry":     10,
               "force":     200,
               "damage_type":  "淤伤"
        ]),
        ([     "action":
"$N一对手置於眉眼间，使大拇指触到眉心。正是「宝瓶印」,突然取向$N的$1",
               "dodge":     10,
               "parry":     10,
               "force":     100,
               "damage_type":  "淤伤"
        ]),
        ([     "action":
"$N倏地升起，却仍保持盘膝而坐的禅修姿态，双手却作出连串印结，变化无方，忽然大喝一声,「大金刚轮印」如狂风暴雨般攻出",
               "dodge":     25,
               "parry":     20,
               "force":     220,
               "damage_type":  "淤伤"
        ]),
        ([     "action":
"$N结出「外狮子印」,毫无花巧的一掌劈出.",
               "dodge":     -5,
               "parry":     10,
               "force":     180,
               "damage_type":  "淤伤"
        ]),
        ([     "action":
"$N优雅地躲过$n的攻击,暗结「内狮子印」,体内真气潮水般攻向$n",
               "dodge":     25,
               "parry":     20,
               "force":     200,
               "damage_type":  "淤伤"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("练密宗大手印必须空手。\n");
        if( (int)me->query("max_force") < 50 )
                return notify_fail("你的内力太弱，无法练密宗大手印。\n");
        return 1;
}
int valid_enable(string usage) { return usage=="unarmed"; }

int practice_skill(object me)
{
        if( (int)me->query("sen") < 40)
                return notify_fail("你的精神无法集中了，休息一下再练吧。\n");
        if( (int)me->query("kee") < 40 )
                return notify_fail("你现在手足酸软，休息一下再练吧。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不够了。\n");

        me->receive_damage("kee", 10);
        me->receive_damage("sen", 10);
        me->add("force", -10);

        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 100 ) return 0;

        if( random(damage_bonus/2) > victim->query_str() ) {
                victim->receive_wound("kee", (damage_bonus - 100) / 2 );
                switch(random(3)) {
                        case 0: return "你听到「喀啦」一声轻响，竟似是骨碎的声音！\n";
                        case 1: return "$N劲力一吐，$n的$l发出「喀」地一声爆响！\n";
                        case 2: return "只听见$n的$l「喀」地一声 ...\n";
                }
        }
}

string perform_action_file(string func)

{
//return CLASS_D("ghost") + "/jinghun-zhang/" + func;
}
