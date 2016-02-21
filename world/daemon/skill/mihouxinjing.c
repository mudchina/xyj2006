//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 10
        ||      (int)me->query_skill("spells", 1) <=
(int)me->query_skill("mihouxinjing", 1) )
                return
notify_fail("你的法术修为还不够高深，无法学习弥猴心经。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("houyao") + "/mihouxinjing/" + spell;
}


