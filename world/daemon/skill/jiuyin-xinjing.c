//Cracked by Roath

//Ansi 99.8
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	if ( me->query_skill("moonforce",1)     
		|| me->query_skill("ningxie-force",1)
		|| me->query_skill("lengquan-force",1)
		|| me->query_skill("zhenyuan-force",1)
		|| me->query_skill("huntian-qigong",1)
		|| me->query_skill("tonsillit",1)
		|| me->query_skill("dragonforce",1)
		|| me->query_skill("huomoforce",1)
		|| me->query_skill("wuxiangforce",1)
		|| me->query_skill("lotusforce",1)
		|| me->query_skill("zixia-shengong",1))
                return notify_fail("你不先散了别派内功，怎能学九阴心经？！\n");
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够，还不能学习九阴心经。\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("九阴心经只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return CLASS_D("pansi") + "/jiuyin-xinjing/" + func;
}
