// modified by vikee for xlqy
// 2000-11-26 11:11
// tell.c

#include <ansi.h>
#include <net/dns.h>
#include "/cmds/std/block_tell.h";
#include <tomud.h>
inherit F_CLEAN_UP;

#define DEBUG "xjh"||"hxl"
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
        if (str[i]->query("id")==target){
              if (!environment(str[i])) return 0;
              else
            return str[i];
         }
    return 0;
}
int help(object me);
void add_id(object me, string id);

void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
	object obj;
	string *allow;

	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

	if( sscanf(target, "%s@%s", target, mud)==2 ) {
		GTELL->send_gtell(mud, target, me, msg);
		write("网路讯息已送出，可能要稍候才能得到回应。\n");
		
	        // mon 7/29/98
	        add_id(me, target+"@"+mud);

		return 1;
	}

        if(!block_tell(me)) return 1;

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("没有这个人。\n");

	// mon 7/29/98
	// when a player set no_tell, if he once initiate to tell
	// others, then his target is allowed to use tell to tell him.

	allow=obj->query_temp("allow_tell");
	if(!allow || member_array(me->query("id"), allow)==-1)
	  if( !wizardp(me) && obj->query("env/block_tell") )
	    return notify_fail(obj->name(1) + "眼下不想跟任何人说话。\n");

        if(!living(obj) || !interactive(obj)) 
	  return notify_fail(HIW+obj->name(1)+"现在的状态没法给你任何答复。\n"NOR);
	  
	write(PTEXT(HBBLU "你告诉" + obj->name(1) + "：" + msg + "\n" NOR));
	if(obj->query("env/reply_msg")&&obj->query("msg_on")) write(GRN+obj->name(1)+"给你的留言是:"HIG+obj->query("env/reply_msg")+"。\n"NOR);
	else {
		tell_object(obj, sprintf(PTEXT(HBBLU "%s告诉你：%s\n" NOR),me->name(1)+"("+me->query("id")+")", msg));
	debug(sprintf(PTEXT( YEL "%s(%s)告诉%s(%s)：%s" NOR),me->name(1),me->query("id"),obj->name(1),obj->query("id"), msg));
		if (interactive(obj)&&query_idle(obj)>120) write(YEL+"但是"+obj->name(1)+"已经发呆"HIR+chinese_number(query_idle(obj)/60)+NOR YEL"分钟，看来你是得不到任何答复了！\n"+NOR);
	     }

	obj->set_temp("reply", me->query("id"));
	
	// mon 7/29/98
	add_id(me, target);
	return 1;
}

string remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;
	string *allow;

	if( ob = find_player(to) ) {
	        if(wizardp(ob) && ob->query("env/invisibility"))
		  return "现在找不到这个人。"; //respond no such user.

		// mon 7/29/98
	    allow=ob->query_temp("allow_tell");
	    if(!allow || member_array(lower_case(from+"@"+mud), allow)==-1)
	        if( ob->query("env/block_tell") ) return
		  ob->query("name")+"现在不想和任何人说话。";

                if(!living(ob) || !interactive(ob)) 
	          return ob->query("name")+"现在听不见你说的话。\n";

		if( cname )
			tell_object(ob, sprintf(PTEXT(HIG "%s(%s@%s)告诉你：%s\n" NOR),
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(PTEXT(HIG "%s@%s 告诉你：%s\n" NOR),
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from+"@"+mud);

		return ob->query("name")+"收到了你的消息。";  
		// if succeed, return target's name.
	} else
		return "现在找不到这个人。";
}

// mon 7/29/98
void add_id(object me, string id)
{
    string *allow;

    // temp array of players we allow to talk to.
    allow=me->query_temp("allow_tell");
    if(!allow) allow=({id});
    else if(sizeof(allow)<50 && member_array(id,allow)==-1)
        allow+=({id});
    me->set_temp("allow_tell", allow);
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
