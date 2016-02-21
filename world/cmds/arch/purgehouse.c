// purge.c

#include <ansi.h>
#define SYNTAX	"指令格式：purge [<未上线天数>] | <使用者姓名> because <原因>\n"

inherit F_CLEAN_UP;

private int do_purge_players(int day);

int main(object me, string arg)
{
	string name, reason;
	string status;
	int day;

	status = wizhood(me);
	if( me!=this_player(1)
	|| wiz_level(me) < wiz_level(status) )
		return notify_fail("你没有权力使用这个指令。\n");

	if( !arg ) return notify_fail(SYNTAX);

	if( sscanf(arg, "%s because %s", name, reason)!=2 )
		return notify_fail(SYNTAX);

	seteuid(getuid());
	if( file_size(DATA_DIR + "playerhomes/h_" + name + __SAVE_EXTENSION__)<0 )
		return notify_fail("没有这位使用者。\n");
	if( (string)SECURITY_D->get_status(name)!="(player)" )
		return notify_fail("非玩家的房屋档案不能被删除。\n"); 

	rm(DATA_DIR + "playerhomes/h_" + name + __SAVE_EXTENSION__);
	write( "使用者 " + capitalize(name) + " 的房屋档案被删除掉了。\n");
	log_file("static/PURGE", sprintf("[%s] %s purged %s's house because %s.\n",
		ctime(time())[0..15], geteuid(this_player(1)), name, reason));

	return 1;
}

int help(object me)
{
write(@HELP
指令格式：purgehouse <使用者姓名> because <原因>

清除一个使用者的房屋档案。
HELP
	);
    return 1;
}
