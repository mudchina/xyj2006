// by gslxz@mhsj 1/7/2001
#include <ansi.h>

inherit F_CLEAN_UP;


string *npc_banghui=({
	"明教",
	"日月教",
	"天地会",
	"丐帮",
});

int main(object me, string arg)
{
	object ob,*target;
	string banghui,n1,n2;
	int money,i,flag;
	object lingpai;
	mapping data;
	string *what,stuffid,stuffname;
	string name;
	if(! (banghui=me->query("banghui")))
		return notify_fail("你没有参加任何帮会，无法邀请他人加入。\n");
	lingpai=new("/obj/lingpai");
	lingpai->create(banghui);
	if(lingpai->query("no_use"))	{
		destruct(lingpai);
		return notify_fail("你的帮会文件有问题，快与巫师联系吧。\n");
	}
	flag=0;
	if( lingpai->query("bangzhu_id")==me->query("id")
	|| ( stringp(me->query("bh_rank")) &&
	sscanf((string)me->query("bh_rank"),"%s副帮主%s",n1,n2)==2))
		flag=1;
	destruct(lingpai);
	if(! arg)
		return notify_fail("你要邀请谁加入你的帮会？\n");
	if( me->query("id")==arg)
		return notify_fail("邀请自己？！\n");
	if(! objectp(ob=present(arg,environment(me))))
		return notify_fail("这儿有没这么个人。\n");
	if(! ob->is_character() )
		return notify_fail("你只能邀请「人」加入你的帮会。\n");
	if(ob->query("banghui")==me->query("banghui"))
		return notify_fail(ob->query("name")+"已经是本帮弟兄了。\n");
	if(me->is_fighting()|| me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(ob->is_fighting()|| ob->is_busy())
		return notify_fail("对方正忙着呢。\n");
	if(!living(ob))	return notify_fail("你得先弄醒他再说。\n");
	if(member_array(banghui,npc_banghui)!=-1
		&& userp(ob))
		return notify_fail("你无权邀请玩家加入「"+banghui+"」！\n");
	if( userp(ob) && !flag)
		return notify_fail("你无权邀请玩家加入「"+banghui+"」！\n");

	message_vision("$N邀请$n参加帮会「"+me->query("banghui")+"」。\n",me,ob);
	if(! userp(ob) )	{
		if(!ob->query("attitude")) return notify_fail("看样子"+ob->query("name")+"对你的帮会没有兴趣。\n");
		
		 if((!(banghui=ob->query("banghui"))|| ob->query("zhongcheng")<me->query_per())&&ob->query("kee")*100>ob->query("max_kee")*80)	{
			message_vision("$N对$n说道：“即是如此，你我不如切磋(qiecuo)一下武功如何？”\n",ob,me);
			ob->set_temp("oldsix/target",me);
			return 1;
			}
			message_vision("$N冲着$n笑道：“我可不敢高攀贵帮啊。”\n",ob,me);
			return 1;
		
	}
	else	{
		tell_object(ob,"如果你愿意加入对方的帮会，请使用jiaru "+me->query("id")+"。\n");
		ob->set_temp("oldsix/target",me);
		return 1;
	}
}

// by gslxz@mhsj 1/7/2001
void delete_target(object npc,string name)
{
	mapping data;
	if(! objectp(npc))	return;
	data=npc->query_temp("oldsix/target");
	if(! mapp(data))	return;
	map_delete(data,name);
	npc->set_temp("oldsix/target",data);
}


int help(object me)
{
        write(@HELP
指令格式：yaoqing <某人>
这个指令用来邀请某人加入你的帮会。
某人可以是玩家或是可征招的NPC。
注意：邀请玩家加入帮会，你必须是帮
会的帮主，或由帮主任命(renming)的
副帮主。

HELP
        );
        return 1;
}
