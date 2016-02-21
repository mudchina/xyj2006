// modified by vikee for xlqy
// 2000-11-26 11:08
// reply.c

#include <ansi.h>
#include <net/dns.h>
#include "/cmds/std/block_tell.h";

inherit F_CLEAN_UP;
#define DEBUG "xjh"
#ifdef DEBUG
void debug(string x)
{
    object monitor;
    if (!stringp(x) || !stringp(DEBUG))     return;
    monitor=find_player(DEBUG);
    if(monitor && monitor->query("env/debug"))     tell_object(monitor,x+"\n");
}
#else
#define debug(x)
#endif

object find_player(string target)
{
        int i;
        object *str;
        str=users();
        for (i=0;i<sizeof(str);i++)
                if (str[i]->query("id")==target)
                        return str[i];
        return 0;
}
int help(object me);
void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, mud;
	object obj;

        if(!block_tell(me)) return 1;

	if( !arg || arg=="" )
		return notify_fail("你要回答什么？\n");

	if( !stringp(target = me->query_temp("reply")) )
		return notify_fail("刚才没有人和你说过话。\n");

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(lower_case(mud), lower_case(target), me, arg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}

	obj = find_player(target);
	if( !obj ) return notify_fail(
	  "刚才和你说话的人现在无法听见你，或者已经离开游戏了。\n");
	  
	if(!living(obj) || !interactive(obj)) 
	  return notify_fail(obj->name(1)+"现在听不见你说的话。\n");
debug(sprintf( YEL "%s(%s)回答%s(%s)：%s" NOR,me->name(1),me->query("id"),obj->name(1),obj->query("id"), arg));		  
write(HBBLU "你回答" + obj->name(1) + "：" + arg + "\n" NOR);
	tell_object(obj, sprintf(HBBLU"%s回答你：%s\n"NOR,
		me->name(1), arg ));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：reply|huida <讯息>

你可以用这个指令和刚才用 tell 和你说话的使用者说话。

see also : tell
HELP
	);
	return 1;
}
