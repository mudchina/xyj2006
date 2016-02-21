// wuxiangforce.c
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) 
{ 
        if( (int)me->query("bellicosity") < (int)me->query_skill("huomoforce", 1)*2 )
		return notify_fail("你的杀气太低，领会不到更深层的火魔心法。\n");

	return 1; 
}

int practice_skill(object me)
{
        return notify_fail("火魔心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return CLASS_D("yaomo") + "/kusong/huomo/" + func;
}

