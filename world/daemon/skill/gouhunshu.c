// 勾魂术

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 10
        ||      (int)me->query_skill("spells", 1) <=
(int)me->query_skill("gouhunshu", 1) )
                return
notify_fail("你的法术修为还不够高深，无法学习勾魂术．\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("ghost") + "/gouhunshu/" + spell;
}
string type() { return "magic"; }
