// mark.c
// pickle 10-27-97

#include <skill.h>

#define SYNTAX "指令格式：mark [-r] <名字> \n"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string msg, *marks, flag, iden;
    string *spells_systems=({"yaofa"});
    int allowed, i;
    object room;
    
    seteuid(getuid());

    if (member_array(me->query_skill_mapped("spells"), spells_systems) == -1)
	allowed=0;
    else allowed=1;
    if (!me->query_skill("spells")
     || !allowed)
        return notify_fail("你所学的法术系统不允许你施用遁术，所以留了记号也没用。\n");
    if (environment(me)->query("no_mark"))
        return notify_fail("你不能在这里留下记号。\n");

    if (!arg)
    {
        if (!sizeof(me->query("记号")))
	    return notify_fail("你目前并没有留下任何记号。\n");
	msg="这是你目前留下的记号：\n";
        marks=keys(me->query("记号"));
	for(i=0; i<sizeof(marks); i++)
	{
	    msg+=marks[i]+"\t";
	    room=find_object(me->query("记号/"+marks[i]));
	    msg+=room->query("short")+"\n";
	}
	msg+="\n";
	tell_object(me, msg);
	return 1;
    }
    if (!sscanf(arg, "-%s %s", flag, iden)) iden=arg;

    if (!flag)
    {
        if(sizeof(keys(me->query("记号"))) >= 9)
	    return notify_fail("你最多只能记住九个地方。\n");
        me->set("记号/"+arg, file_name(environment(me)));
	tell_object(me, "你准备将「"
		+environment(me)->query("short")
		+"」记为「"+iden+"」。\n");
	return 1;
    }
    if (flag && flag != "r")
        return notify_fail("只能用 mark -r。\n");
    if (member_array(iden, keys(me->query("记号"))) == -1)
	return notify_fail("你并没有用「"+iden+"」来记任何地方。\n");
    me->delete("记号/"+iden);
    tell_object(me, "你删除「"+iden+"」这个记号。\n");
    

    return 1;
}

int help (object me)
{
        write(SYNTAX + @HELP
 
你可以用这个指令在房间中留下自己的记号，这样你可以用
法术直接遁至这个房间。只有某些门派的法术有遁术，所以
这个指令对没有遁术的门派是无用的。

一个人可以记住几个地方跟法术以及法术的等级有关，但是
无论法术有多高，最多只能记住九个地方。

具体如何施用遁术到达目的地，请看各个门派的详细解释，
或各个技能的解释。
HELP
        );
        return 1;
}
