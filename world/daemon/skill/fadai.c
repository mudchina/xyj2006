inherit SKILL;
void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
return notify_fail("发呆大法只能在实际中亲身体会。\n");
        return 1;
}

int practice_skill(object me)
{       
return notify_fail("发呆大法只能在实际中亲身体会。\n");
}
