// ls.c modify by error@xyj 3.10.2000
#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int mark_loaded;
	int i, j, w, col,*dis,d,abs_flag;
	string dir,dir1,*filter;
	mixed *file,*f;
	seteuid(geteuid(this_player(1)));
	abs_flag=0;
	dir = resolve_path(me->query("cwd"), arg);
	arg=dir;
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) 
		dir += "/";
	file = get_dir(dir, -1);
	if( !sizeof(file) )
	{
		if (file_size(dir) == -2) 
			return notify_fail("目录是空的。\n");
		else
			return notify_fail("没有这个目录。\n");
	}

	filter=explode(arg,"/");
	j=sizeof(filter);
	if(j>0)
	{
		arg=(strsrch(filter[0],"*")==-1&&strsrch(filter[0],"?")==-1)?filter[0]:"";
		for(i=1;i<j;i++)
		{
			if(strsrch(filter[i],"*")!=-1)
				i++;
			else
				if(strsrch(filter[i],"?")!=-1)
					i++;
				else
					arg+="/"+filter[i];
		}
	}
	i = sizeof(file);
	w = 0;
	d=0;
	dis=allocate(i);
	while(i--) {
		dir1=file[i][0];
		dir1=(arg[strlen(arg)-1]=='/')?(arg+dir1):(arg+"/"+dir1);
		dir1=(dir1[0]=='/')?dir1:"/"+dir1;
		if(file[i][0]=="."||file[i][0]=="..")
			continue;
		if(file_size(dir1)==-1)
			dis[d++]=i+1;
		file[i][0] =(file[i][1]==-2)?file[i][0]+"/":file[i][0];
		if (strlen(file[i][0])>w) 
			w = strlen(file[i][0]) + 1;
	}
	d=0;
	write("\n目录：" + dir + "\n");
	col = 70 / (w+6);
	d=0;
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++)
		{
			d++;
			if(member_array(i+1,dis)==-1)
				printf("%4d %-*s%s", file[i][1]/1024 + 1, w+1,
					file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
					((i+1)%col)?"  ":"\n");
			else
			{	d--;
				printf(WHT"%4d %-*s%s"NOR, file[i][1]/1024 + 1, w+1,
					file[i][0] + (find_object(dir + file[i][0])? "*":" ") ,
					((i+1)%col)?"  ":"\n");
			}
		}
	else write("    没有任何档案。\n");
	write("\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
指令格式: ls [<路径名>]

列出目录下所有的子目录及档案, 如果没有指定目录, 则列出所在目录
的内容，所列出的档案中前面标示 * 号的是已经载入的物件。

□例:
'ls /' 会列出所有位于根目录下的档案及子目录.

HELP
	);
	return 1;
}

