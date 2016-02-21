#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

#define MSGFILE "/data/msg/msgd.o"
#define MSGD "/adm/daemons/msgd"

int do_addmsg(string arg);
int do_listmsg(string arg);
int do_delmsg(string arg);

void create()
{
	string *msg;
	
	seteuid(getuid());
	set_name("新闻管理器",({"msgd","msg"}));
	set("channel_id","大唐通告");
	if (file_size(MSGFILE)<=0){
		setup();
		msg=({});
		add("msg",msg);
		save();
		}
	setup();
	restore();
	if (clonep())
		return;
	CHANNEL_D->do_channel( this_object(), "sys", "新闻系统已经启动。\n");	
	call_out("on_time",10);
}

void init()
{
	add_action("do_addmsg","addmsg");
	add_action("do_listmsg","listmsg");
	add_action("do_delmsg","delmsg");
}

int valid_string(string arg)
{
	return 1;
}

int valid_use()
{
	object me=this_player(1);
	
	if (wiz_level(me)<wiz_level("(arch)"))
		return 0;
	return 1;
}
string query_save_file()
{
	return MSGFILE;
}

void on_time()
{
	int i,j;
	string *msg=query("msg");
	
	i=sizeof(msg);
	if (i<=0){
		//CHANNEL_D->do_channel(this_object(),"chat",
		//	"没有新闻\n");
		call_out("on_time",150);
		return;
		}
	j=random(i);
	
	CHANNEL_D->do_channel(this_object(),"chat",
		msg[j]);
	call_out("on_time",150);
}

int do_addmsg(string arg)
{
	object me=this_player(1),ob;
	string *msg;
	
	if (!arg||!valid_string(arg))
		return notify_fail("非法的信息\n");
	msg=query("msg");
	msg=msg+({arg});
	set("msg",msg);
	save();
	ob=find_object(MSGD);
	if (ob)
		ob->restore();
	tell_object(me,"新闻增加完毕\n");		
	return 1;
}

int do_listmsg(string arg)
{
	object me=this_player(1);
	string *msg;
	int i;
	
	msg=query("msg");
	for (i=0;i<sizeof(msg);i++)
		printf("%4d    :    %s\n",i+1,msg[i]);
	return 1;    
}

int do_delmsg(string arg)
{
	object me=this_player(1),ob;
	string *msg;
	int i,j;
	
	if (sscanf(arg, "%d", i)!=1)
		return notify_fail("你要删除哪一条信息？\n");
	msg=query("msg");
	msg=msg-({msg[i-1]});
	set("msg",msg);
	save();
	ob=find_object(MSGD);
	if (ob){
		ob->restore();
		}
	tell_object(me,"新闻删除完毕\n");
	return 1;
}