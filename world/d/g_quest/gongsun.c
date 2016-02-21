//weiqi...97/12/11

inherit NPC;
#include <quest.h>
string apply_dancer(object me);
string answer_leaving(object me);
int do_yes(string arg);
void do_something();

void create()
{
	set_name("太平公主", ({"taiping gongzhu", "taiping", "gongzhu"}));
	set("age", 32);
	set("gender", "女性");
	set("per", 20);
	set("long", "她便是大唐天朝太平公主，江湖中的能人异士都争相投靠其府中。\n尤其近年招兵买马，野心不小。\n");
//	set("title", "长安乐坊老板娘");
	set("attitude", "friendly");

	set("combat_exp", 40000);
	set("max_force", 400);
	set("force", 400);
	set("force_factor", 5);
	set_skill("unarmed", 60);
	set_skill("dodge", 490);
	set_skill("moondance", 520);
	set_skill("parry", 60);
	set_skill("literate", 690);
	set_skill("sword", 290);
	set_skill("snowsword", 290);
	map_skill("dodge", "moondance");
	map_skill("sword", "snowsword");

	set("quest_type", "captor");
	set("inquiry", ([
		"name" : "嘻嘻...连我太平公主你都不知道...\n",
		"here" : "嗯...天下美景不胜数，长安此处最繁华。\n",
		"舞妓" : (: apply_dancer :),
		"舞女" : (: apply_dancer :),
		"歌妓" : (: apply_dancer :),
		"歌女" : (: apply_dancer :),
		"leave" : (: answer_leaving :),
		"离开" : (: answer_leaving :),
		"mihan": (:give_quest:),
		"密函": (:give_quest:),
	]) );

	setup();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/weapon/sword/snow_sword")->wield();
	add_money("silver", 200);
}

void do_something()
{
	command(sprintf("bet %d silver", 1+random(5)));
	call_out ("do_something", 120);	
}

string apply_dancer(object me)
{
	me=this_player();
	if( (string)me->query("gender") == "男性" ) 
	{
		return "这就要看阁下的本事了，我可帮不上多少忙。\n";
	}
	else
	{
		if( (string)me->query("class") == "dancer" )
			return "好好干吧，以后不愁嫁不上好人家。\n";

		if( (int)me->query("age") >= 30 )
			return "岁月不饶人，姑娘还是另寻它路吧。\n";

		message_vision("太平公主看了$N一眼叹道：这碗饭可不是容易吃的。\n", me);	
		me->set_temp("dancer_applied", 1);
		return "姑娘果真是下了决心？(yes)\n";
	}
}

string answer_leaving(object me)
{
	me=this_player();
	if( (string)me->query("gender") == "男性" ) 
	{
		return "快滚，滚得远远的！\n";
	}
	else
	{
		if( (string)me->query("class") == "dancer" )
			return "既入此门，大家都知道了，离不离开又有什么分别呢？\n";
		else return "快走吧，这里本来就不是女人玩的地方。\n";
	}
}

void init()
{
	::init();

	remove_call_out("do_something");
	call_out ("do_something", 120);		

	add_action("do_yes", "yes");
}

int do_yes(string arg)
{
	object me;

	me=this_player();
	
	if(me->query_temp("dancer_applied")) 
	{
		message_vision("$N答道：我都想清楚了！\n\n", me);
		message_vision("太平公主拍了拍$N的头道：好好干！只要能碰上好运气，荣华富贵垂手可得！\n", me);
		me->delete_temp("dancer_applied");
		me->set("class", "dancer");
		return 1;
	}

	return 0;
}



