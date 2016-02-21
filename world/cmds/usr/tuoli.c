// by gslxz@mhsj 1/7/2001
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string banghui,msg;
	object lingpai;
	if(me->is_fighting()||me->is_busy())
		return notify_fail("你正忙着呢。\n");
	if(! (banghui=me->query("banghui")))
		return notify_fail("你没有参加任何帮会，无需脱离。\n");
	if(! arg)
		return notify_fail("你要脱离什么帮会？\n");
	if(arg != banghui)
		return notify_fail("你不是这个帮会的成员。\n");
        lingpai=new("/obj/lingpai");
        lingpai->create(banghui);
        if(lingpai->query("no_use"))    {
                destruct(lingpai);
                return notify_fail("你的帮会文件有问题，请与巫师联系。\n");
        }
	if(me->query("id")==lingpai->query("bangzhu_id"))	{
		msg="你是帮会「"+me->query("banghui")+"」的帮主，脱离前最好指定新任帮主！\n";
	}
	else	msg="你是帮会「"+me->query("banghui")+"」的帮众。\n";
	msg +="你真的要脱离吗(y/n)？";
	write(msg);
	destruct(lingpai);
	input_to("yes_or_no",me,banghui);
	return 1;
}

// by gslxz@mhsj 1/7/2001
int yes_or_no(string str,object me,string banghui)
{
	mapping data;
	object lingpai;
	str=lower_case(str);
	if(str=="y"||str=="yes")	{
		lingpai=new("/obj/lingpai");
		lingpai->create(banghui);
		if( lingpai->query("no_use"))	{
			destruct(lingpai);
			return notify_fail("你的帮会文件有问题，请与巫师联系。\n");
		}
		if(userp(me))	data=lingpai->query("player");
		else	data=lingpai->query("npc");
		if(! mapp(data))	data=([]);
		map_delete(data,me->query("id"));
		if(userp(me))	lingpai->set("player",data);
		else	lingpai->set("npc",data);
		if(me->query("id")==lingpai->query("bangzhu_id"))	{
			lingpai->set("bangzhu_id","???");
			lingpai->set("bangzhu","???");
		}

       message("channel:rumor",YEL"【帮会势力】"+me->query("name")+"脱离"+
                "帮会「"HIW+banghui+NOR+YEL"」！\n"NOR,users());
	me->delete("banghui");
	if(!undefinedp(me->query("score")))
		me->delete("score");
	if(!undefinedp(me->query("bh_rank")))
		me->delete("bh_rank");
	if(!undefinedp(me->query("rank_lv")))
		me->delete("rank_lv");
	if(!undefinedp(me->query("title")))
		me->set("title",NOR+banghui+"叛徒"NOR);
       me->save();
	lingpai->save();
	if(! sizeof(lingpai->query("player")) && 
		! sizeof(lingpai->query("npc")))	{
		rm("/data/guild/"+banghui+".o");
		message("channel:rumor",YEL"【帮会势力】帮会「"HIW+banghui+NOR+YEL
                        "」土崩瓦解了！\n"NOR,users());
	}
	destruct(lingpai);
	return 1;
	}
	write("好吧，请想清楚后再做决定．\n");
	return 1;
}
int help(object me)
{
        write(@HELP
指令格式：tuoli <帮会名称>
这个指令可以使你脱离帮会。
前提是你必须是该帮会成员。
HELP
        );
        return 1;
}
