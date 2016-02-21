// by gslxz@mhsj 1/7/2001
#include <ansi.h>
inherit F_CLEAN_UP;
string *npc_banghui=({
	"明教",
	"日月教",
	"天地会",
	"丐帮",
});


int main(object me, string arg)
{
	mixed *dir;
	string *id;
	mapping data;
	object lingpai;
	string msg,banghui;
	int i;
	if(! arg)	{
	dir=get_dir("/data/guild/",0);
	if(! dir)	return notify_fail("目前没有任何帮会。\n");
	msg=sprintf("%-16s%-10s%-10s%-10s%-10s\n",
		"帮会名称","帮主","玩家数","NPC数","地盘数");
	msg+="------------------------------------------------------------\n";
	lingpai=new("/obj/lingpai");
	for(i=0;i<sizeof(dir);i++)	{
		if(sscanf(dir[i],"%s.o",banghui)==1)	{
			lingpai->create(banghui);
//			msg+=sprintf("%-16s%-10s%-10d%-10d%-10d\n",
			msg+=sprintf("%s%-16s%-10s%-10d%-10d%-10d"NOR"\n",
			member_array(banghui,npc_banghui)!=-1?HIG:"",
			banghui,lingpai->query("bangzhu"),sizeof(lingpai->query("player")),sizeof(lingpai->query("npc")),sizeof(lingpai->query("area")));
	}
	}
	destruct(lingpai);
	}
	else if(arg =="-l")	{
		if(! (banghui=me->query("banghui")))
		return notify_fail("你没有参加任何帮会，无法显示具体细节。\n");
		lingpai=new("/obj/lingpai");
		lingpai->create(banghui);
		if(lingpai->query("no_use"))	{
		destruct(lingpai);
		return notify_fail("你的帮会文件有问题，请与巫师联系。\n");
		}
		msg=HIC"「"+banghui+"」玩家列表\n"NOR;
		msg+="—————————————————————————————————————\n";
		data=lingpai->query("player");
		if(! mapp(data))	data=([]);
		id=keys(data);
		for(i=0;i<sizeof(id);i++)	{
			msg+=sprintf("%-32s%s",data[id[i]]+"("+id[i]+")",
			(i%2==1? "\n": ""));
		}
		if(i%2) msg+="\n";
		msg+="—————————————————————————————————————\n";
		msg+="\n"+HIC"「"+banghui+"」NPC列表\n"NOR;
		msg+="—————————————————————————————————————\n";
// by gslxz@mhsj 1/7/2001
		data=lingpai->query("npc");
		if(! mapp(data))	data=([]);
		id=keys(data);
		for(i=0;i<sizeof(id);i++)	{
			msg+=sprintf("%-32s%s",data[id[i]]+"("+id[i]+")",
			(i%2==1? "\n": ""));
		}
		if(i==0||i%2)	msg+="\n";
		msg+="—————————————————————————————————————\n";
		msg+="\n"+HIC"「"+banghui+"」地盘列表\n"NOR;
		msg+="—————————————————————————————————————\n";
		data=lingpai->query("area");
		if(! mapp(data))	data=([]);
		id=keys(data);
		for(i=0;i<sizeof(id);i++)	{
			msg+=sprintf("%-18s%s",id[i],
			(i%4==3? "\n": ""));
		}
		if(i==0||i%4)	msg+="\n";
		msg+="—————————————————————————————————————\n";
	if(member_array(banghui,npc_banghui)==-1)	{
		msg+="\n"+HIC"「"+banghui+"」收入单\n"NOR;
		msg+="—————————————————————————————————————\n";
		i=lingpai->query("area_money_last");
		if(! intp(i))	i=0;
		msg+="各地盘收入："+MONEY_D->money_str(i)+"\n";
		i=lingpai->query("npc_money_last");
		if(! intp(i))	i=0;
		msg+="NPC帮众收入："+MONEY_D->money_str(i)+"\n";
		i=lingpai->query("bangzhu_money");
		if(! intp(i))	i=0;
		msg+="帮主今日所得："+MONEY_D->money_str(i)+"\n";
		msg+="—————————————————————————————————————\n\n";
	}
		destruct(lingpai);
	}
	else	return notify_fail("命令格式：banghui [-l]\n");
	me->start_more(msg);
	return 1;
}



int help(object me)
{
        write(@HELP
指令格式：banghui [-l]
本指令用来显示目前所有帮会状况。
使用-l参数可查看所在帮会详细资料。
HELP
        );
        return 1;
}
