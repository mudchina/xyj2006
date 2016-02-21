// by gslxz@mhsj 1/7/2001
inherit F_CLEAN_UP;
int check_name(string name);

int main(object me, string arg)
{
	object ob,lp;
	string name,id;
	string banghui;

	if(! arg)	return notify_fail("指令格式：renming <某人> <职务>\n");
	if(! stringp(banghui=me->query("banghui")))
			return notify_fail("只有帮主才能使用本命令。\n");
	lp=new("/obj/lingpai");
	lp->create(banghui);
	if(lp->query("no_use"))	{
		destruct(lp);
		return notify_fail("你的帮会文件有问题，请与巫师联系。\n");
	}
	if(lp->query("bangzhu_id")!=me->query("id"))	{
		destruct(lp);
		return notify_fail("只有帮主才能使用本指令。\n");
	}
	destruct(lp);
	if(sscanf(arg,"%s %s",id,name)==2)	{
		ob=present(id,environment(me));
		if(! ob)	return notify_fail("这儿没有这么个人。\n");
		if(! ob->is_character())
				return notify_fail("看清楚，那并不是人！\n");
		if(!userp(ob))	return notify_fail("你只对本帮会的玩家使用这条命令！\n");
		if(banghui!=(string)ob->query("banghui"))
				return notify_fail("你只对本帮会的玩家使用这条命令！\n");
		if(me->is_busy()||me->is_fighting())
				return notify_fail("你正忙着呢！\n");
		if(ob->is_busy()||ob->is_fighting())
				return notify_fail("对方正忙着呢！\n");
		if(! check_name(name))
				return notify_fail("您任命的职务必须是中文，且为二到八字！\n");
		ob->set("bh_rank",name);
		message_vision("$N任命$n为「"+banghui+"」"+name+"！\n",me,ob);
		return 1;
	}
	else	return notify_fail("指令格式：renming <某人> <职务>\n");
}
// by gslxz@mhsj 1/7/2001

int check_name(string name)
{
        int i;

        i = strlen(name);

        if( (strlen(name) < 4) || (strlen(name) > 16 ) ) {
		return 0;
	}
        while(i--) {
                if( name[i]<=' ' ) {
			return 0;
		}
	if( i%2==0 && !is_chinese(name[i..<0]) ) {
			return 0;
	}
	}
	return 1;
}

int help(object me)
{
        write(@HELP

指令格式：renming <player's id> <职务名称>

这条指令是玩家帮会的帮主专用命令，可以为本帮会
的玩家帮众分配帮会职务。如坛主、堂主、护法、使
者等称谓。
注意：凡是任命为副帮主的玩家，可以代替帮主行使
邀请(yaoqing)的权力。
HELP
        );
        return 1;
}


