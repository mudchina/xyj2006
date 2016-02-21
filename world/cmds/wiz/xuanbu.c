// xuanbu by Canoe
#include <ansi.h>;
int main(object me, string arg)
{
   if( !wizardp(me) )
     return notify_fail("目前暂不开放玩家 xuanbu。\n");
   if (!arg) return notify_fail("你想要宣布什么?\n");
   shout( BLINK HIW"【巫师公告】：" +NOR HIY+ arg + "\n"NOR);
    write("你宣布：" + BLINK HIW"【巫师公告】：" +NOR HIY+ arg + "\n"NOR);
   return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : xuanbu <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话，和shout唯一不同的就是player不知道你是谁。
 
see also : tune
HELP
    );
    return 1;
}
 

