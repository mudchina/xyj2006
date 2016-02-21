// toptenadd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string type,player;
	object ob;

	seteuid(geteuid(me));
	if (!arg||sscanf(arg,"%s %s",type,player)!=2)
		return notify_fail("指令格式 : toptenadd <类型> <玩家ID>\n");
	if(!objectp(ob=find_player(player)))
		return notify_fail("没有"+player+"这个玩家或"+player+"不在线。\n");
	switch(type)
	{
	case "rich":
		if(TOPTEN_D->topten_add(ob,type))
			write("玩家"+player+"成功挤入"+RICH_B+"！\n");
		else
			write("玩家"+player+"没资格列入"+RICH_B+"！\n");
		break;
	case "pker":
		if(TOPTEN_D->topten_add(ob,type))
			write("玩家"+player+"成功挤入"+PKER_B+"！\n");
		else
			write("玩家"+player+"没资格列入"+PKER_B+"！\n");
		break;
	case "exp":
		if(TOPTEN_D->topten_add(ob,type))
			write("玩家"+player+"成功挤入"+EXP_B+"！\n");
		else
			write("玩家"+player+"没资格列入"+EXP_B+"！\n");
		break;
	default:
		return notify_fail("现在还没有"+type+"这种排行榜。\n");
	}
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : tadd <类型> <玩家ID>
HELP
    );
    return 1;
}
