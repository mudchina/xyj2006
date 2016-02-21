//Cracked by Roath
// kickout.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg || sscanf(arg, "%s", arg) != 1 )
		return notify_fail("你要摧毁什么？\n");

	if( !objectp(ob = present(arg, me)) )
        return notify_fail("你身上没有这样东西。\n");
	if(me->query("id") != ob->query("owner"))
	return notify_fail("这样东西不是你的，你不可以摧毁它。\n");
	seteuid(ROOT_UID);
	rm(base_name(ob) + ".c");
	ob->move(environment(me));
	destruct(ob);
	me->add("created_item",-1);
	seteuid(getuid());
	write("ＯＫ\n");
	return 1;
}

int help(object me)
{
write(@HELP
你可以用此指令摧毁一件你自己的物件。被摧毁的物件将
永远消失。此指令是用来摧毁你不想再要的自造物品，
指令格式 : destroy <某物件>

HELP
    );
    return 1;
}

