//Cracked by Roath

// dhxy-evil 2000.7.7
inherit FORCE;
string type() { return "force"; }

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够，还不能学习先天真气。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("先天真气只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("shushan") + "/xiantian-force/" + func;
}
