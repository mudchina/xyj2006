//  butian-force补天心法
// /daemon/skill/butian-force.c
// writted by mind 2001/2

#include <ansi.h>
inherit FORCE;
int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { return 1; }
int practice_skill(object me)
{
        if( (string)me->query("family/family_name")!="三界散仙")
                return notify_fail("你非散仙，再练有害无益。\n");

        if( !environment(me)->query("butian-force_practice") )
                return notify_fail("补天心法只能在特殊的法台上才可练。\n");

        if( (int)me->query_skill("butian-force",1) >= 200 )
                return notify_fail("你的补天心法很难提高了。\n");
        if( (int)me->query("kee") < 30 )
                return notify_fail("你的气不够。\n");
        if( (int)me->query("sen") < 30 )
                return notify_fail("你的神不够。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不够");
        me->receive_damage("kee", 30);
        me->receive_damage("sen", 30);
        me->add("force", -10);

        return 1;
}

string exert_function_file(string func)
{
        return CLASS_D("sanxian") + "/butian-force/" + func;
}


