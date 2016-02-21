// uptime.c

#include <ansi.h>
inherit F_CLEAN_UP;
string report_str();

// This command is also called by LOGIN_D, so we don't want it use 
// arguments.
int report()
{
//      write("西游已经运行了" + report_str()+"。\n");
              write(HIG"西游记2006"NOR"已经运行了" + report_str()+"。\n");
    return 1;
}
string report_str()
{
	int t, d, h, m, s;
	string time;

	t = uptime();
	s = t % 60;		t /= 60;
	m = t % 60;		t /= 60;
	h = t % 24;		t /= 24;
	d = t;

	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";

	return(time);
}

int main()
{
	report();
//          write("\n");
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : uptime
 
这个指令告诉你西游记已经运行了多久。
 
HELP
    );
    return 1;
}
