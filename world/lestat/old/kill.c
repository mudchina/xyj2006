// kill.c

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;
void do_kill(object,object);
int main(object me, string arg)
{
	object obj, guard_ob;
	string *killer, callname;

	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("这里不准战斗。\n");

	if( !arg )
		return notify_fail("你想杀谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(obj==me)
		return notify_fail("用 suicide 指令会比较快:P。\n");
                
        if (obj->query("taskguai"))
        {if( obj->query("owner") && me != obj->query("owner") )
		      return notify_fail(obj->query("name")+"瞪了你一眼，你觉得手软脚软了。\n");
        }
        if(!valid_kill(me,obj,0)) return 0;

	callname = RANK_D->query_rude(obj);

	message_vision("\n$N对着$n喝道：「" 
		+ callname + "！今日不是你死就是我活！」\n\n", me, obj);	

        if( obj->query_temp("protected")
          && objectp(guard_ob=present(obj->query_temp("protect_ob"), environment(obj)))
          && (string)guard_ob->query_temp("protect")==obj->query("id")
	  && guard_ob!=me ) {

    message_vision(HIC"$N对着$n大声说：有我在此，不用担心！\n"NOR,guard_ob,obj);
    message_vision(HIC"$N冲上前去挡住了$n的攻击。\n"NOR, guard_ob, me);
    guard_ob->fight_ob(me);
    return 1;
		}
	do_kill(me, obj);

	return 1;
}
void do_kill(object me, object obj)
{

	me->kill_ob(obj);
	if( !userp(obj) ){
	
		if(!obj->accept_kill(me) )
		obj->kill_ob(me);

	} else {
		obj->fight_ob(me);
		tell_object(obj, HIR"如果你要和" + me->name() 
			+ "性命相搏，请你也对这个人下一次 kill 指令。\n"NOR);

	}

}
int help(object me)
{
  write(@HELP
指令格式 : kill <人物>
 
这个指令让你主动开始攻击一个人物，并且□试杀死对方，kill 和 fight 最大的
不同在于双方将会真刀实枪地打斗，也就是说，会真的受伤。由于 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对于一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。

其他相关指令: fight

有关 fight 跟 kill 的区分请看 'help combat'.
HELP
    );
    return 1;
}
 


