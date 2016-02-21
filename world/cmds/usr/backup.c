// backup.c by canoe

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object link_ob;
	//string file;
	seteuid(getuid());

	if( !objectp(link_ob = me->query_temp("link_ob")) )
		return notify_fail("你不是经由正常连线进入，不能储存。\n");
		
 if( (time()-me->query("last_backup")) < 60
||time()-me->query("last_save")<60 )        
		return notify_fail("你迟点才可以储存。\n");
    write(
		"因为档案备份关于到您的数据安全问题，所以需要确认你的管理密码。\n"
		"请输入您的管理密码：");
	input_to("check_password", 1, me);
	return 1;
	}

private mixed check_password(string passwd, object me)
{
	object link_ob;
	string old_pass;
        object* inv;
	int     i; 
	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("super_password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("管理密码错误！\n");
		return;
	}
else 
    me->set("last_backup",time());
    
	if( (int)link_ob->save() && (int)me->save() && (int)me->backup()) {
		// backup for fabao

		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); ++i)  {
		   if( inv[i]->query("owner_id") == getuid(me) && 
		   inv[i]->query("series_no") )   {
			   inv[i]->unequip();
			   if( !(int)inv[i]->backup() )   {
		           write("\n储存失败。\n");
                   write("\n备份失败。\n");
		           return 0;
			   }
		   }
		}

        write("\n恭喜！档案储存完毕。\n");
        write("恭喜！备份完毕。\n");
		return 1;
	} else {
		write("\n储存失败。\n");
        write("\n备份失败。\n");
		return 0;
	}
}

int help(object me)
{
	write(@HELP
指令格式：backup

备份档案。在你的档案遭受莫名其妙的伤害后，可要求巫师恢复。
HELP
	);
	return 1;
}
