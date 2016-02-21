// clone.c

#include "/doc/help.h"
#include "ansi.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
	object obj;
	string err, msg, afile, flag;

	seteuid( geteuid(me) );

	if (!file) file = me->query("cwf");
	if (!file)
		return notify_fail("你要复制什么物件？\n");

	flag = "";
	if( sscanf( file, "%s %s", flag, afile ) == 2 && flag == "-f" )
	   file = afile;
	file = resolve_path(me->query("cwd"), file);
	if( sscanf(file, "%*s.c") != 1 ) file += ".c";
	me->set("cwf", file);

	if( file_size(file) < 0 )
		return notify_fail("没有这个档案(" + file + ")。\n");

	if( !find_object(file) ) {
		err = catch(call_other(file, "???"));
		if (err) {
			write("载入失败：" + err + "\n");
			return 1;
		}
	}

    if( file->query_unique() )  {
           write("目前在Ｍｕｄ中有"+file->query_number()+
                        "个复制，应最多有"+
                        file->query_compare_number()+"个。\n");
	   if( file->in_mud() && flag != "-f" )  {
		  write("该物品为" + HIR + "Unique Item" + NOR + "，请用 clone -f 来强行复制。\n");
		  return 1;
	   }
	}
	err = catch(obj = new(file));
	if (err) {
		write("复制失败：" + err + "\n");
		return 1;
	}

	if( !stringp(msg = me->query("env/msg_clone")) )
		msg = "只见$N伸手凌空一指，变出了$n。\n";
        log_file("static/CLONE","["+ctime(time())+"] "+sprintf("%s(%s) clone %O\n",
         me->query("name"),me->query("id"),
         obj));

	if( !obj->is_character() && obj->move(me) ) {
		write(obj->query("name") + "复制成功，放在你的物品栏。\n");
		if (msg != "") message_vision(msg + "\n", me, obj);
		return 1;
	}
	if( obj->move(environment(me)) ) {
		write(obj->query("name") + "复制成功，放在这个房间。\n");
		if (msg != "") message_vision(msg + "\n", me, obj);
		return 1;
	}

	destruct(obj);
	return notify_fail("无法复制不能移动的物件(" + file + ")。\n");
}

int help(object me)
{
  write(@HELP
指令格式 : clone <档名>

利用此指令可复制任何能移动之物件(含怪物)。
HELP
    );
    return 1;
}
