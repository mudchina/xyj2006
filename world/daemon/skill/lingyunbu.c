inherit SKILL;
#include <ansi.h>
string *dodge_msg = ({
     "$n一招"+BLINK""+HIG"「清水池边明月」"NOR+"，$N只觉眼前一花，不见了$n的身影。\n",
     "$n一招"+HIG"「绿柳堤畔桃花」"NOR+"，身形微晃，有惊无险地避开了$N这一招。\n",
     "只见$n身子向后一翻，一招"+BLINK""+HIG"「别是一般风味」"NOR+"，后荡而起，掠向一旁。\n",
     "$n可是$n一个"+BLINK""+HIG"「凌空几片飞霞」"NOR+"，长袖翻飞，躲过$N这一招。\n",
});
int valid_enable(string usage) { return (usage=="dodge"); }
int valid_learn(object me)
{
        if( (int)me->query("spi") < 10 )
                return notify_fail("你的灵性不够，没有办法练凌云步。\n");
        return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}
int practice_skill(object me)
{
        if( (int)me->query("sen") < 30 )
                return notify_fail("你的精神太差了，不能练凌云步。\n");
        me->receive_damage("sen", 30);
        return 1;
}
