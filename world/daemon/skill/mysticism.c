// mysticism.c 【玄玄神机】
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 20 
                || (int)me->query_skill("spells", 1) <= (int)me->query_skill("mysticism", 1) )
                return notify_fail("你的法术修为还不够高深，无法学习玄玄神机。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("sanxian") + "/mysticism/" + spell;
}

string type() { return "magic";} 

