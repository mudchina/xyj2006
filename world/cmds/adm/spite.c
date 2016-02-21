// xgrep.c 
// write by JackyBoy@CuteRabbit Studio for SDXL & CCTX 1999/6/1
// 为了避免递归太深，请不要设置进入级别超过16级. JackyBoy
inherit F_CLEAN_UP;
int help();

int sort(string a,string b);
int main(object me, string arg)
{
	string *file;
	string str;
	int i;
	str="";
//        if (!arg) return help();
	file=sort_array(explode(read_file("/data/chinese.o"),","),(:sort:));
	for (i=0;i<sizeof(file);i++)
	  str+=file[i]+",\n";
	if (!write_file("/data/chinese.new",str,1))
	  return notify_fail("失败!\n");
	write("成功!\n");
	seteuid(geteuid(me));
	return 1;
}

int sort(string a,string b)
{
	if (a<b) return -1;
	return 1;
}


int help()
{
  write(@HELP

X grep 命令 v0.1  Write By JackyBoy@CuteRabbit for CCTX & SDXL 1999/6/1
主页：http://mud.yn.cninfo.net/jackyboy
邮件：jackyboy@126.com


指令格式 : xgrep [-d[0-15]] 路径 想要搜索的字符串
此指令可让你在指定(除了目录，可以用通配符来指定)档案或目录里寻找含有要
搜索的字符串的文件，并将其位置显示出来。
注意，默认仅搜索当前目录！
已知BUG：
对二进制文件进行搜索将会出错，因为禁止将'\0'设置到一个string里！
HELP
    );
    return 1;
}
