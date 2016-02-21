#include <ansi.h>

inherit F_CLEAN_UP;
#define MAX_ICONS 2159

int help();

int main(object me,string arg)
{
	mixed tmp;
	int ico;
	string str="",icon=HIR"空，没有设置"NOR;
	if( (tmp = me->query("icon")))
	{
		if( intp(tmp) )
		{
			icon = sprintf("%d",tmp);
			str=L_ICON(icon);
		}
		else if( stringp(tmp) )
		{
			icon = tmp;
			str=L_ICON(icon);
		}
	}

	str+=NOR+"你原来的头像编号是"+HIY+icon+NOR+"！\n";

	if(arg)
	{
		if(sscanf(arg,"%d",ico)!=1||ico<=0||ico>=MAX_ICONS)
			return help();
		icon=sprintf("%d",ico);
		while( sizeof(icon)<5 )	icon = "0" + icon;
		str+="它已经被修改为"+HIG+icon+NOR+"了！\n";
		me->set("icon",icon);
	}
	else help();
	tell_object(me,str);
	return 1;
}

int help()
{
	write("命令格式："+HIY+"icon [图标编号]\n"+NOR+
		"    你可以用本命令查询和修改自己的头像编号。\n"+
		"    你可以去[http://www.qqchat.net]查询和选择自己的头像图标编号。\n"+
		"    目前图标可以选择范围是"+HIR+" 1 - "+MAX_ICONS+NOR+" 。\n");
	return 1;
}


