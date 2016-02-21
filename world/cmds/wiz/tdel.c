// toptenadd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string type,player;

	seteuid(geteuid(me));
	if (!arg||sscanf(arg,"%s %s",type,player)!=2)
		return notify_fail("指令格式 : tdel <类型> <玩家ID>\n");
	if (TOPTEN_D->topten_del(player,type)!=-1)
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
