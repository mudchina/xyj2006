// say.c

#include <ansi.h>
#include "/cmds/std/block_tell.h";

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if(!block_tell(me)) return 1;

	if (!arg) {
		write("你自言自语不知道在说些什么。\n");
		tell_room(environment(me), me->name() + "自言自语不知道在说些什么。\n",
	          	  me);
		return 1;
	}
	if( (int)me->query("kee") < (int)me->query("max_kee") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}
            if ( strsrch( arg , ".") != -1  || strsrch( arg , ".")!= -1 )
                return 0 ;


	write( CYN "你说道：" + arg + "\n" NOR);
	tell_room(environment(me), CYN + me->name() + "说道：" +  arg + "\n" NOR,
	          me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: say <讯息>
 
说话，所有跟你在同一个房间的人都会听到你说的话。
 
注: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
