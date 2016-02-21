// tell.c

#include <ansi.h>
#include <net/dns.h>
#include "/cmds/std/block_tell.h";

inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud, filename;
	object obj;

	if( !arg || sscanf(arg, "%s %s", target, filename)!=2 )
	   return help(me);

	msg = "\n";
	msg += read_file(filename);

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		return 1;
	}

        if(!block_tell(me)) return 1;

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("没有这个人。\n");

	if( !wizardp(me) && obj->query("env/block_tell") )
	   return notify_fail(obj->name(1) + "眼下不想跟任何人说话。\n");

        if(!living(obj) || !interactive(obj)) 
	  return notify_fail(obj->name(1)+"现在听不见你说的话。\n");
	  
	write(GRN "你告诉" + obj->name(1) + "：" + msg + "\n" NOR);
	tell_object(obj, sprintf( GRN "%s告诉你：%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));

	obj->set_temp("reply", me->query("id"));
	return 1;
}

string remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
	        if(wizardp(ob) && ob->query("env/invisibility"))
		  return "现在找不到这个人。"; //respond no such user.

	        if( ob->query("env/block_tell") ) return
		  ob->query("name")+"现在不想和任何人说话。";

        if(!living(ob) || !interactive(ob)) 
	          return ob->query("name")+"现在听不见你说的话。\n";

		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)告诉你：%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s 告诉你：%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return ob->query("name")+"收到了你的消息。";  
		// if succeed, return target's name.
	} else
		return "现在找不到这个人。";
}

int help(object me)
{
	write(@HELP
指令格式：tell <某人> <讯息>

你可以用这个指令和其他地方的使用者说话。

其他相关指令：reply
HELP
	);
	return 1;
}
