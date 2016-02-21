// bboard.c


inherit F_CLEAN_UP;
inherit F_SAVE;

int main(object me, string arg)
{
        object user;
	string srcstr, dststr;
	string status;

	status = wizhood(me);
	if( me!=this_player(1) || wiz_level(me) < wiz_level(status) )
		return notify_fail("你没有权力使用这个指令。\n");
	
	if (!arg) return 0;
        if (sscanf(arg, "%s %s", srcstr, dststr)!=2) return 0;

	// login data

        seteuid(getuid());
	user = new(LOGIN_OB);
	if( (string)user->set("id", srcstr) != srcstr ) 
		return notify_fail("Failed setting user name.\n");
	if (! user->restore())	return notify_fail("没有这个玩家。\n");
	export_uid(user);

	if( (string)user->set("id", dststr) != dststr ) 
		return notify_fail("Failed setting user name.\n");
        if (!user->save()) return notify_fail("存档失败！\n");
	destruct(user);

        tell_object(me, 
		"玩家 "+srcstr+" 数据成功转换至玩家 "+dststr+" ！\n");
	return 1;
}	

int help(object me)
{
write(@HELP

指令格式：transfer <source_id> <dest_id>

将一个玩家的数据(login)转换至另一个玩家。

HELP
        );
    return 1;
}

