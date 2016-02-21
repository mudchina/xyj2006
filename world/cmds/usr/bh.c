// by gslxz@mhsj 1/7/2001
// bh.c 帮会频道
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *member;
	string bh;
	int i;

	if( !arg)	return notify_fail("你要说什么？\n");
	bh=(string)me->query("banghui");
	if( !bh)	return notify_fail("你没有入帮会，无法使用帮会频道。\n");
	member=users();
	for(i=0;i<sizeof(member);i++)	{
		if( !objectp(member[i]))	member[i]=0;
		else if( !living(member[i]))	member[i]=0;
		else if( (string)member[i]->query("banghui")!=bh)	member[i]=0;
	}
	member-=({ 0 });
// by gslxz@mhsj 1/7/2001
	message("banghui",HIG"【"+bh+"】"+me->query("name")+"("+me->query("id")+")："+arg+"\n"NOR,
		member);
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式 : bh <内容>

本指令用于帮会成员的内部交流。

HELP
        );
        return 1;
}
