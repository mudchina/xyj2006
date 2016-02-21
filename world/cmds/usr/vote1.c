// vote command..
// Rewritten by Sunyc@Kync xajh.7758.com 5555 2001年8月30日
// All Copyrights.

#include <ansi.h>
#include <dbase.h>
#include <mudlib.h>

inherit F_SAVE;
inherit F_CLEAN_UP;

/*取得标题*/
int get_subject(string arg);
/*取得选项数目*/
int get_choice_number(string arg);
/*取得选项内容*/
int get_choice(string return_choice);
/*帮助*/
int help(object me);
/*投票*/
int do_vote(int i,string arg);
/*删除动议*/
int do_del_vote(int i);
/*以下是常用变量*/
int number,number1;
string subject,return_choice;
mapping choice=([]);
object ob=this_object();
string *letters=({"!","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"});
/*数据板*/
object data=load_object("/d/wiz/obj/vote_ban");

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    string choice;
    int i,z,j,num;
    if (!arg) { help(me); return 1;}
    if (sscanf(arg,"%d %s",i,choice)==2)
    {
	if (((int)me->query("combat_exp")<300000) && !wizardp(me))
	    return notify_fail("你的条件还不够参与动议投票。\n");
	if(wizardp(me)) return notify_fail("巫师禁止参与投票。\n");
	if(i<=0) return notify_fail("故意捣乱是要受惩罚的。\n");
	if (!data->query_data()) return notify_fail("根本没有一个动议，投什么票啊！\n");
	if (i>sizeof(data->query_data())) return notify_fail("有这个号码嘛？\n");
	if (!data->query_data()[i-1]["choice"][choice]) return notify_fail("有这个选项嘛？\n");
	if (member_array(me->query("id"),data->query_choice()[i-1]["id"])!=-1)
	    return notify_fail("你已经投过票了。\n");
	do_vote(i,choice);
	return 1;
    }
    else    if(sscanf(arg,"%d",num)==1)
    {
	if(!data->query_data()) return notify_fail("目前没有任何动议。\n");
	if(num>sizeof(data->query_data())) return notify_fail("没有这个编号。\n");
	data->do_list(num-1);
	return 1;
    }
    else    if(arg=="list") {
	if(!data->query_data()) return notify_fail("目前没有任何动议。\n");
	data->do_list(-1);
	return 1;
    }
    else    if(arg=="add" && wizardp(me)) {
	if(sizeof(data->query_data())>5) return notify_fail("目前动议数目过多，还是等等吧。\n");
	write("清设定一个标题：");
	input_to("get_subject");
	return 1;
    }
    else   if(sscanf(arg,"del %d",num)==1)
    {
	if((mapping)data->query_data()==([])) return notify_fail("目前没有任何动议。\n");
	if(num>sizeof(data->query_data())) return notify_fail("没有这个编号。\n");
	data->del(num-1);
	return 1;
    }
    help(me);
    return 1;
}

int get_subject(string arg)
{
    if(arg!="") 
    {
	subject=arg;
	write("清设定选项个数：");
	input_to("get_choice_number",0);
	return 1;
    }
    write("请设定一个题目：");
    input_to("get_subject");
    return 1;
}
void choice(int i)
{
    object me=this_player();
    i=number1;
    if(i) 
    {
	choice+=([letters[i]:return_choice]);
    }
    i=i+1;
    number1=i;	
    if(i>number) 
    {	
	data->add_vote(me->short(1),ctime(time()),subject,choice);
	message("channel:chat",HIG+"【表决】"+this_player()->name(1)+"向"+MUD_NAME+"提交了一份动议。\n"NOR,users());
	number1=0;
	number=0;
	return;
    }
    write("请您输入第"+i+"个选项的介绍：");
    input_to("get_choice");
    return;
}
int get_choice_number(string arg)
{
    if(!arg || sscanf(arg,"%d",number)!=1)
    {    
	write("请您设定选项的个数：");
	input_to("get_choice_number");
	return 1;
    }
    choice(0);
    return 1;
}
int get_choice(string arg)
{
    if(arg=="")
    {
	write("请您从新输入选项介绍：");
	input_to("get_choice");
	return 1;
    }
    return_choice=arg;
    choice(number1);
    return 1;
}
int do_vote(int j,string arg)
{
    object me=this_player();
    message("channel:chat",HIG+"【表决】"+this_player()->name(1)+"向"+MUD_NAME+"第"+j+"号动议提交了一票。\n"NOR,users());
    data->add_vote_piao(j,arg,me->query("id"));
    return 1;
}
int help(object me)
{
    write(@HELP
指令格式 : 
最新的vote1系统支持以下命令：
玩家：
vote1 list   			    察看当前的动议列表
vote1 <动议编号> <选项>              向一条动议投票
vote1 <动议编号>                    察看动议的具体情况

巫师：
vote1 add   			    增加一条动议
vote1 del <动议编号>                 删除一条动议
HELP);
    return 1;
}

