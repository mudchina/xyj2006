// by gslxz@mhsj 1/7/2001
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string banghui;
	object ob;
	object lp;
	if(! me->query("banghui"))
		return notify_fail("只有帮会的帮主才能使用这条指令。\n");
	banghui=me->query("banghui");
	if(me->is_fighting()||me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(! arg)
		return notify_fail("你要让位给谁？\n");
	if( me->query("id")==arg)
		return notify_fail("让位给自己？有必要吗？\n");
	if(! ob=present(arg,environment(me)))
		return notify_fail("这儿没有这么个玩家。\n");
	if(! userp(ob))
		return notify_fail("你只能让位给玩家。\n");
	if( ob->query("banghui")!=banghui)
		return notify_fail("你只能让位给本帮会的玩家。\n");
	if(ob->is_fighting()||ob->is_busy())
		return notify_fail("对方正忙着呢。\n");
	lp=new("/obj/lingpai");
	lp->create(banghui);
	if( lp->query("no_use"))	{
		destruct(lp);
		return notify_fail("你的帮会文件有问题，请与巫师联系。\n");
	}
	if(lp->query("bangzhu_id")!=me->query("id"))	{
		destruct(lp);
		return notify_fail("你不是帮会帮主，无法使用这条指令。\n");
	}
// by gslxz@mhsj 1/7/2001
	lp->set("bangzhu",ob->query("name"));
	lp->set("bangzhu_id",ob->query("id"));
	lp->save();
	destruct(lp);
	message_vision("$N将帮会「"+banghui+"」的帮主之位让位给了$n。\n",me,ob);
	ob->set("title",YEL+ob->query("banghui")+"帮主"NOR);
	me->set("title",HIG+ob->query("banghui")+"帮众"NOR);
       return 1;
}
int help(object me)
{
        write(@HELP
指令格式：rangwei <某人>
这个指令为帮主专用，用来将帮主之位让位给他人。
前提是某人必须为本帮帮众。
HELP
        );
        return 1;
}
