// wlist.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *list;

write("西游记2006目前的巫师(不再招收新巫师)
─────────────────────────────────────\n");
	list = sort_array(SECURITY_D->query_wizlist(), 1);
	for(int i=0; i<sizeof(list); i++)
		printf("%-15s%c", list[i],  (i%5==4) ? '\n' : ' ');

write("\n");
write("─────────────────────────────────────\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : wlist

用途 : 列出目前所有的巫师名单(含客座巫师)。
HELP
     );
     return 1;
}
