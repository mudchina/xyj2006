// block.c
// modified by mon 7/25/97

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string option, target;

	if( !arg) return notify_fail("你要关掉／或打开谁的频道？\n");

        if( sscanf(arg, "%s %s", option, target)!=2 ) target = arg;
	if ( option != "-s" && option != "-u" ) target = arg;

	obj = find_player(target);
        if(!obj) return notify_fail("没有这个人．．．\n");

	if(option=="-s") {  // say, tell, reply, emote and whisper
	  if( wizardp(obj)) return notify_fail("有必要吗？\n");
	  obj->set("channel/tell_block",time()+86400);
	  tell_object(obj, "你的交谈频道被暂时关闭了！\n");
	  write( "玩家" + obj->query("name") + "的交谈频道被关闭了！\n");
	  
        } else if(option=="-u") { // open channel
          obj->delete("channel/tell_block");
          obj->delete("channel/chat_block");
	  tell_object(obj, "你的频道被打开了！\n");
	  write( "玩家" + obj->query("name") + "的频道被打开了！\n");

	} else {  // chat and rumor
	  // block chat and rumor for 24 hours. (24*3600 sec).
	  if( wizardp(obj)) return notify_fail("有必要吗？\n");
          obj->set("channel/chat_block",time()+86400);
	  tell_object(obj, "你的公用频道被暂时关闭了！\n");
	  write( "玩家" + obj->query("name") + "的公用频道被关闭了！\n");	
        }

	return 1;

}

int help(object me)
{
   write(@HELP
指令格式： block <某人>     暂时关掉某人的chat和rumor频道。
           block -s <某人>  暂时关掉某人的say，reply，emote，tell和whisper。
           block -u <某人>  恢复某人的所有通道。

HELP
   );
   return 1;
}
