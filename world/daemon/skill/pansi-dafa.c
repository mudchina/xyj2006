// pansi-dafa.c

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells") <= (int)me->query_skill("pansi-dafa") )
		return notify_fail("你的法术修为还不够高深，无法学习盘丝大法。\n");
//        if( (int)me->query("bellicosity") < 10 )

//                return notify_fail("一点杀气都没有，怎么修炼盘丝大法。\n")
	return 1;
}

string cast_spell_file(string spell)
	{
return CLASS_D("pansi") + "/pansi-dafa/" + spell;

	}

string type() { return "magic";}

