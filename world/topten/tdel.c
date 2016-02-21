// toptenadd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string type,player;

	seteuid(geteuid(me));
	if (!arg||sscanf(arg,"%s %s",type,player)!=2)
		return notify_fail("指令格式 : tdel <类型> <玩家ID>\n");
	switch(type)
	{
	case "rich":
		TOPTEN_D->topten_del(player,type);
		break;
	case "pker":
		TOPTEN_D->topten_del(player,type);
		break;
	case "exp":
		TOPTEN_D->topten_del(player,type);
		break;
	default:
		return notify_fail("现在还没有"+type+"这种排行榜。\n");
	}
	write("已经完成删除。\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : tdel <类型> <玩家ID>
HELP
    );
    return 1;
}
