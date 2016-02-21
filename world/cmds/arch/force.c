// promote.c
// last modify at 03rd, JUNE 1997 -KEN.Q.Z.ZHANG.

#include <ansi.h>

inherit F_CLEAN_UP;

int help(object);

int main(object me, string arg)
{
	string cmds;
	object ob;

	if (!arg || !sscanf(arg, "%s do %s", arg, cmds)) return help(me);

        if( !(ob = present(arg, environment(me))) )
		return 0;

	if( ob == me )
		return notify_fail("直接打命令比较快些。\n");

	if( wiz_level(me) < wiz_level(ob) )
		return notify_fail("你没有这种权力。\n");

	return ob->force_me(cmds);
}

int help(object me)
{
	write(@HELP
指令格式： force 人物<id> do <命令>
HELP );
    return 1;
}



