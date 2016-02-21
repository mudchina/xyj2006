// Modified by Lestat for 
// 2001.3.15
// kill.c

#include <ansi.h>
#include "valid_kill.h";

inherit F_CLEAN_UP;
void do_kill(object,object);
int main(object me, string arg)
{
	object obj, guard_ob;
	string *killer, callname, msg;
        int obj_level, me_level;
	if( !wizardp(me) && environment(me)->query("no_fight") )
		return notify_fail("这里不准战斗。\n");

	if( !arg )
		return notify_fail("你想杀谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");

	if(userp(obj) && obj->query("age")<16)
		return notify_fail("你的心肠太黑了, 对手无缚鸡之力的玩家也下得了手。\n");

	if(me->query("combat_exp")<500000 && userp(obj))
		return notify_fail("小小年纪就想杀人？\n");

	if(me->query("daoxing")<500000 && userp(obj))
		return notify_fail("小小年纪就想杀人？\n");	

	if(obj==me)
		return notify_fail("用 suicide 指令会比较快:P。\n");

    if(wizardp(obj)&&!wizardp(me)) 
       return notify_fail("杀巫师？还是考虑清楚吧！\n");
	   
      if(!valid_kill(me,obj,0)) return 0;
        callname = RANK_D->query_rude(obj);

        if(me->query("race")=="人类"){
                if(me->query("mute"))
                        msg = "\n$N突然冲向$n，双眼通红，看来是要至$p于死地！！\n\n";
                else if(me->query("combat_exp") > obj->query("combat_exp")*2){
		        if(me->query("bellicosity") < 500)
                       msg = "\n$N对着$n啐了一口：「"+callname+"！，怪你生不逢时，"+RANK_D->query_self_rude(me)+"今天看你极不顺眼，认命吧！！\n\n";
                    else msg = "\n$N对着$n吼道：「"+callname+"！，你记好"+RANK_D->query_self_rude(me)+"的名字，死后到阴司去告我一状吧！！\n\n";
		        }
	        else if(obj->query("combat_exp") > me->query("combat_exp")*2){
		        if(me->query("bellicosity") < 500)
                       msg = "\n$N对着$n一声奸笑：「"+callname+"！，别看你平时耀武扬威，今天"+RANK_D->query_self_rude(me)+"就要取你性命！！\n\n";
		        else msg = "\n$N嘿嘿一笑：$n"+callname+"，我虽技不如你，但今天就是拼了命也要将你碎尸万断！！\n\n";
		        }
	        else {
		        if(me->query("bellicosity") < 500)
                     msg = "\n$N对着$n猛吼一声：「"+callname+"！，明年的今天就是你的祭日，让"+RANK_D->query_self_rude(me)+"送你上路吧！！\n\n";
		        else msg = "\n$N对着$n喝道：「" + callname + "！，你死期已到，今天就让"+RANK_D->query_self_rude(me)+"送你上西天吧！\n\n";
	                }
	        }
	else msg = "\n$N大吼一声，猛然扑向$n，看来是要将$p杀死！！\n\n";
           message_vision(msg, me, obj);

        if( obj->query_temp("protected")
          && objectp(guard_ob=present(obj->query_temp("protect_ob"), environment(obj)))
          && (string)guard_ob->query_temp("protect")==obj->query("id")
	  && guard_ob!=me ) {

	message_vision(HIC"$N对着$n大声说：有我在此，不用担心！\n"NOR,guard_ob,obj);
                        message_vision(HIC"$N冲上前去挡住了$n的攻击。\n"NOR, guard_ob, me);
                        guard_ob->kill_ob(me);
			me->kill_ob(guard_ob);
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
		obj->kill_ob(me);
		tell_object(obj, HIR "如果你要和" + me->name() 
			+ "性命相搏，请你也对这个人下一次 kill 指令。\n" NOR);

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
 

