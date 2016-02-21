// suicide.c by canoe

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	if( me->is_busy() )
		return notify_fail("你上一个动作还没完成。\n");

	if( !arg ) {
		write("你重新投胎。\n");
		return 1;
	}

	if( arg!="-f" ) 
		return notify_fail("自杀有两种，您是要永远死掉还是重新投胎？\n");

	if(wizardp(me))
	    return notify_fail("请不要自杀掉巫师帐号，谢谢！\n");

	ob = me->query_temp("link_ob");
   	if( !ob ) 
   	    return notify_fail("你不是正常途径进来的,不能自杀！\n");;
        while( ob && ob->is_character() ) ob = ob->query_temp("link_ob");
      if(!me->query_temp("suicide")||time()-(int)me->query_temp("suicide")>30)
        CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"似乎适应不了西游记2006的多彩生活，想打退堂鼓。");
	me->set_temp("suicide",time());
       
        if(ob->query("super_password"))
      {
        write("如果您选择永远死掉的自杀方式，这个人物的资料就永远删除了，请务必\n"
                "考虑清楚，确定的话请输入您的管理密码：");
        input_to("check_super_password",1,me,1);
        return 1;
      }   
      else 
      {
      	 write("如果您选择永远死掉的自杀方式，这个人物的资料就永远删除了，请务必\n"
                "考虑清楚，因为你没有设定管理密码，所以请输入您的登陆密码：");
         input_to("check_password", 1, me, 1);
	return 1;
	}
}

private void check_super_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("super_password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("管理密码错误！\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n你决定要自杀了，如果三十秒钟内不后悔，就真\n的永别了，你还有很多事情没做完吧？\n\n\n" NOR);
		me->set_temp("suicide_countdown", 30);
		me->start_busy( (: call_other, this_object(), "slow_suicide" :) );
	}
}

private void check_password(string passwd, object me, int forever)
{
	object link_ob;
	string old_pass;

	link_ob = me->query_temp("link_ob");
	old_pass = link_ob->query("password");
	if( crypt(passwd, old_pass)!=old_pass ) {
		write("登陆密码错误！\n");
		return;
	}

	if (forever) {
		tell_object( me,
			HIR "\n\n你决定要自杀了，如果三十秒钟内不后悔（quit），就真的永别了。\n\n\n" NOR);
		me->set_temp("suicide_countdown", 30);
		me->start_busy( (: call_other, this_object(), "slow_suicide" :) );
	}
}

private int slow_suicide(object me)
{
	object link_ob;
	int stage;
	string myid, couple;

	stage = me->query_temp("suicide_countdown");
	me->add_temp("suicide_countdown", -1);
	if( stage > 1 ) {
		if( stage%5 == 0 )
		  tell_object(me, 
			HIR "你还有 " + stage + " 秒的时间可以后悔。"+
			"(用quit命令来后悔)\n" NOR);
		return 1;
	}

	link_ob = me->query_temp("link_ob");
	if( !link_ob ) return 0;

	log_file("static/SUICIDE",
		sprintf("%s(%s) commits a suicide on %s from %s\n", geteuid(me), me->name(), ctime(time()), (string)query_ip_name(me) ) );

	seteuid(getuid());
	rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
	rm( me->query_save_file() + __SAVE_EXTENSION__ );
	myid=me->query("id");

	// remove player home.
	rm( "/data/playerhomes/h_"+myid+ __SAVE_EXTENSION__ );

	// remove mailbox.
	rm( "/data/mail/"+myid[0..0]+"/"+myid+ __SAVE_EXTENSION__ );
         // rm pat
         if(me->query("pet"))
         rm( "/data/pet/"+myid[0..0]+"/"+myid+ __SAVE_EXTENSION__ );
	// remove couple's home as well. (the home is registered by the 
	// couple.)
	couple=me->query("coupld/id");
	if(couple)
	  rm("/data/mail/"+couple[0..0]+"/"+couple+__SAVE_EXTENSION__);


	write("好吧，永别了:(\n");
	tell_room(environment(me), me->name() +
		"自杀了，以后你再也看不到这个人了。\n", ({me}));
	CHANNEL_D->do_channel(this_object(),"rumor",me->name()+"没有活下去的勇气，过早地自我毁灭了。");
	destruct(me);
	return 0;
}

int help (object me)
{
        write(@HELP
指令格式: suicide [-f]
 
如果因为某种原因你不想活了, 你可以选择自杀.
自杀分两种:
 
suicide    : 重新投胎
suicide -f : 永远的除去玩家资料, 系统会要求你
             输入密码以确认身份.
 
请慎重选择 :)
 
HELP
);
        return 1;
}
