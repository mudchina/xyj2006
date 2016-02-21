// Last modified by jjgod@FYTX. 01/03/07.

#include <ansi.h>
#include <localtime.h>

inherit F_CLEAN_UP;
int help(object me);
int list(object me, int y)
{
	string *note;
	string str;
	int i, j;

	tell_object(me, y+" 年"); 
	note = get_dir("/data/wenxuan/"+y+"/");
	i = sizeof(note);
	if (!i){
		write("还没有任何文选。\n");
		return 0;
		}

	write("共有"+chinese_number(i)+"张文选。\n");
	str = "───────────────────────────────────────\n";
	for(j=0;j<i;j++)
		str += " ["HIW+(j+1)+NOR"] "+read_file("/data/wenxuan/"+y+"/"+(j+1)+".w", 1, 1);
		me->start_more(str+"───────────────────────────────────────\n");
	return 1;           
}

int read_note(object me, int number,int y)
{
	string *note;
	int i;
    
	tell_object(me, y+" 年"); 
	note = get_dir("/data/wenxuan/"+y+"/");
	i = sizeof(note);
	if (!i)
	{
		write("还没有任何文选。\n");
		return 0;
	}
	if( number < 1 || number > i )
	{
		write("目前还没有你所要读的这篇文选。\n");
		return 0;
	}

	write("的第"+chinese_number(number)+"张文选。\n\n");
	me->start_more( "["HIW+number+NOR"] "+read_file("/data/wenxuan/"+y+"/"+number+".w"));
	return 1;
        
}

int main(object me, string arg)
{
	string *file, str;
	int i, j, number,y;

	tell_object(me,"《"HIW+MUD_NAME+NOR"文选大全》，");
        
	file = get_dir("/data/wenxuan/");
	i = sizeof(file);
	if (!i) return notify_fail("现在暂时还没有文选。\n");

	y = localtime(time())[LT_YEAR];
        
	if (!arg) list(me, y);
                
	else if(sscanf(arg, "%d %d", number,j)==2){
		if(j < 1970 || j > y ) 
			return notify_fail("还没有 ["+j+"] 这年的文选呢。\n");
		if(number == 0)
			list(me, j);
		else read_note(me, number, j);
	}
	else if(sscanf(arg, "%d %d", number, y)==2){
		if(number == 0)
			list(me, y);
		else read_note(me, number, y);
	}
	else if(arg == "all"){
		str = "目前有 ";
		while(i--) str += "["+file[i]+"年] ";
		tell_object(me, str+"的文选。\n");
	}
	else if(sscanf(arg, "%d", number)==1)
	read_note(me, number, y);
        
	else help(me);
	return 1;
}

int help(object me)
{
write(@HELP
指令格式：

wenxuan all                  : 列出有文选的年份。
wenxuan                      : 列出本年文选。
wenxuan <编号>               : 阅读本年此编号的文章。
wenxuan 0 <年份>             : 列出本年文选。
wenxuan <编号> <年份>        : 阅读此年份此编号的文章。

HELP
    );
    return 1;
}
