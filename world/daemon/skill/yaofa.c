// dao
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( 2*(int)me->query_skill("spells") <= (int)me->query_skill("yaofa") )
        return notify_fail("你的法术修为还不够高深，无法学习「妖法」。\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("yaomo") + "/wudidong/yaofa/"+spell;
}

string type() { return "magic"; } 
