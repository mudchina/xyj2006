// bugao.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
if(me->query("id")!="bear")
return notify_fail("你没有权力使用。\n");
if (!arg) return notify_fail("你想要公布什么?\n");
shout(me->name() + HIR"〖"NOR""HIC"玩 具 熊 频 道"HIR"〗"HIY":" +arg +"
\n"NOR);
write(HIC"【"NOR""HIC"玩 具 熊 频 道"HIC"】"HIW":" +arg +"\n"NOR);
   return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : bugao <讯息>

这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话.

see also : tune
HELP
    );
    return 1;
}
