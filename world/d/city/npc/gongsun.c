//weiqi...97/12/11

inherit NPC;

string apply_dancer(object me);
string answer_leaving(object me);
int do_yes(string arg);
void do_something();

void create()
{
	set_name("公孙大娘", ({"gongsun daniang", "gongsun", "daniang"}));
	set("age", 62);
	set("gender", "女性");
	set("per", 30);
	set("long", "长安城内稍有名望的，不知道公孙大娘的人恐怕没几个。\n特别是那些文人骚客，跟公孙大娘不熟简直就是没面子。\n");
	set("title", "剑圣");
	set("attitude", "friendly");

	set("combat_exp", 8000000);
  set("daoxing", 6000000);

	set("max_force", 4000);
	set("force", 8000);
	set("force_factor", 200);
	set_skill("unarmed", 260);
        set("max_mana", 8000);
        set("mana", 8000);
        set("mana_factor", 500);
	set_skill("dodge", 290);
	set_skill("binfen-steps", 320);
	set_skill("parry", 260);
	set_skill("literate", 290);
	set_skill("sword", 390);
	set_skill("daya-jian", 390);
	map_skill("dodge", "binfen-steps");
	map_skill("sword", "daya-jian");
	map_skill("parry", "daya-jian");


	set("inquiry", ([
		"name" : "嘻嘻...连老娘我公孙大娘你都不知道...\n",
		"here" : "嘿嘿...天下美景不胜数，长安此处最繁华。\n",
		"妓院" : "大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
		"妓女" : "大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
		"嫖妓" : "大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
		"青楼" : "大胆！此乃天子脚下，竟敢出此伤风败俗之言！\n",
		"舞妓" : (: apply_dancer :),
		"舞女" : (: apply_dancer :),
		"歌妓" : (: apply_dancer :),
		"歌女" : (: apply_dancer :),
		"leave" : (: answer_leaving :),
		"离开" : (: answer_leaving :),
		"剑法" : "在下也学过一些粗浅剑术,一直没有传人,倒也是件憾事！",
		"大雅古剑法" : "你说我的剑术啊,传给你倒也可以,不过听说东海的龙珠对内功大有帮助,阁下可否寻来！",
	]) );

set("chat_chance_combat", 90);
set("chat_msg_combat", ({
(: perform_action,"sword", "badao" :),
 }) );
	setup();
	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
        carry_object("/u/lestat/obj/dao")->wield();
	add_money("silver", 200);
}

void do_something()
{
	command(sprintf("bet %d silver", 1+random(5)));
	if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
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

		message_vision("公孙大娘看了$N一眼叹道：这碗饭可不是容易吃的。\n", me);	
		me->set_temp("dancer_applied", 1);
		return "姑娘果真是下了决心？(yes)\n";
	}
}

string answer_leaving(object me)
{
	me=this_player();
	if( (string)me->query("gender") == "男性" ) 
	{
		return "快滚，滚得远远的！老娘这地方还怕没人来吗？\n";
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
		message_vision("公孙大娘拍了拍$N的头道：好好干！只要能碰上好运气，荣华富贵垂手可得！\n", me);
		me->delete_temp("dancer_applied");
		me->set("class", "dancer");
		return 1;
	}

	return 0;
}
int accept_object(object me, object ob)
{
  object skull;
  
  if ((string)ob->query("id")!="jiucai longzhu") {
    command("say 这怎么可以？");
    return 0;
  }
  else {
    if (query_temp("received_longzhu")==1) {
      command("thank "+ me->query("id"));
      command("say 多谢了。刚才有位善士施给老娘一颗珠子，这颗恐怕是假的。");
      command("say "+RANK_D->query_respect(me) +"这份善心，在下心领了。");
      add_temp("received_longzhu", 1);
      return 0;
    }
    else {
        if(query_temp("received_longzhu")<1 || !query_temp("received_longzhu")) {
          command("great " + me->query("id"));
          command("say 这位" + RANK_D->query_respect(me) + "！实在太感谢了！");
          command("say 我也没什么可谢的。我年少时游历江湖有些奇遇,得传一套剑法,现下告诉你。");
         write("公孙大娘低声道:盘丝洞有一密室,你不防去(strike)看看,或许有些收获\n");
          command("grin");
		  this_player()->set("mark/daya-jian", 1);
          command("say "+ RANK_D->query_respect(me) + "莫嫌老娘多嘴。前途险恶，可要保重了。");
          add_temp("received_longzhu", 1);
   	  return 1;
        }
        command("say 多谢"+RANK_D->query_respect(me)+"的好意，不过在下已经有一颗珠子了。");
        return 0;
    }
  }
}
int recognize_apprentice(object ob, object who)
{
if (this_player()->query("mark/dayagett")!= 1)
	return notify_fail("公孙大娘笑道：你我何来师徒之缘！\n");
if (this_player()->query("daoxing")< 2000000)
{this_player()->delete("mark/dayagett");
this_player()->set_temp("noway",1);
        return notify_fail("你这点微末本事也想学大雅古剑法！\n");
}
if (this_player()->query("noway"))
        return notify_fail("公孙大娘笑道：你我师徒之缘已绝！\n");
    return 1;
}
