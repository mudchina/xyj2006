//whois.c

#include <ansi.h>
#include <command.h>
inherit F_DBASE;

int check_name(object who, string arg);

int main(object me, string arg)
{
	int i;
	object *all_user, *named_user;
	
	seteuid(getuid());
	
	if( ! arg )
		return notify_fail("whois <中文名字>\n");
	
	all_user = users();
	
	named_user = filter_array(all_user, (:check_name:), arg);
	
	i = sizeof(named_user);
	
	switch(i){
	case 0:
		printf("在线的没人叫%s。\n", arg);
		break;
	case 1:
		printf("%s的英文名字是"BOLD"%s。\n"NOR,
			arg, named_user[0]->query("id"));
		break;
	default:
		printf("一共有%s个在线玩家叫%s：\n", chinese_number(i), arg);
		while(i --)
			printf(BOLD"%s\n"NOR, named_user[i]->query("id"));
		break;
	}

	return 1;
	
}

int check_name(object who, string arg)
{
	if( who->query("name") == arg )
		return 1;
	return 0;
}

int help(object me)
{
    write(@HELP
指令格式：whois <中文名字> 
 
这个指令可以根据玩家的中文名字查出相应的英文ｉｄ。 
HELP
    );
	return 1;
}

