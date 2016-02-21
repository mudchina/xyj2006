// wuya-guai.c...weiqi, 97.09.15.

inherit NPC;

string give_map(object me);
string help_fly(object me);
int do_yes(string arg);

void create()
{
	set_name("乌鸦先生", ({"wuya xiansheng", "wuya", "xiansheng"}));
	set("gender", "男性" );
	set("age", 43);
	set("per", 112);//no rongmao description.

	set("long", "这位乌鸦先生来自遥远的大雪山。乃是大鹏明王座下有名的高手之一。\n他远看还不错，走近了才发现他长着长长的一张乌鸦嘴。\n");
	set("class", "yaomo");
	set("combat_exp", 100000);
        set("daoxing", 50000);

	set("attitude", "peaceful");
	create_family("大雪山", 3, "弟子");
	set_skill("unarmed", 50);
	set_skill("yingzhaogong", 50);
	set_skill("cuixin-zhang", 70);
	set_skill("dodge", 90);
	set_skill("xiaoyaoyou", 90);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("bingpo-blade", 80);
	set_skill("force", 60);   
	set_skill("ningxie-force", 70);
	set_skill("literate", 30);
	set_skill("spells", 60);
	set_skill("dengxian-dafa", 60);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "yingzhaogong");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 700);
	set("max_sen", 600);
	set("force", 700);
	set("max_force", 700);
	set("mana", 700);
	set("max_mana", 700);	
	set("force_factor", 35);
	set("mana_factor", 20);

	set("eff_dx", -25000);
	set("nkgain", 150);

	set("inquiry", ([
		"name" : "问什么问，张着眼睛是看的，长着脑袋是想的。\n",
		"here" : "这就是我们大雪山。\n",
		"怎么去" : "飞过去最快，走也能到。\n",
		"怎么走" : "从这儿往北走。\n",
		"怎么飞" : (: help_fly :),		 
//		"大雪山" : (: give_map :),
	]) );

	set("no_map", 0);

	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

void attempt_apprentice(object ob)
{

	if( (string)ob->query("family/family_name")=="大雪山" ){
		if( (int)ob->query("family/generation") < 3  ){
			command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
		}
		else if( (int)ob->query("family/generation") ==3  ){
			command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣大爷我了！\n");
		}
		else {
			command(":D");
			command("say 你这个" + RANK_D->query_rude(ob) + "早就该来拜我为师！你那个破师父什么都不懂...\n");
			command("recruit " + ob->query("id") );
                        ob->set("title", "大雪山守山小妖");
                        ob->set("class", "yaomo");
		}
	}

	else{
		command(":D ");
		command("say 好，到我们大雪山来学艺，又找了个好师父，只要能活下来，" + RANK_D->query_respect(ob) + "可以说是前途无量啊！\n");
		command("recruit " + ob->query("id") );
                ob->set("title", "大雪山守山小妖");
                ob->set("class", "yaomo");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

string help_fly(object me)
{
	me=this_player();
	if( me->query("combat_exp")<30000 ){
/*
		message_vision("乌鸦先生道：马上就叫你飞...闭上眼睛！\n", me);
		message_vision("只见乌鸦先生嘴里念叨了几句，一脚踢中$N的屁股，$N腾云驾雾般飞了出去...\n", me);
		me->move("/d/xueshan/binggu");
		tell_room( environment(me),"只听劈啪！一声，一个人从空中飞过来，死猪般地摔在地上。\n", ({me}));
		return "嘿嘿！\n";
*/
		return "赶紧学吧！\n";
	}
	else{
		return "你现在头脑不清醒，别摔死了！\n";
	}
}

string give_map(object me)
{
	me=this_player();
	me->set_temp("need_map", 1);
	return "大雪山，那可是个好地方，你想去吗(yes)？\n";
}

void init()
{
   add_action("do_answer", "answer");
}

int do_answer(string arg)
{       
        object me=this_player();
        string *ans=({"巡山的","过路的","捣乱的",});
        int ans1;

        if( !arg ) return notify_fail("你说什么？\n");
        if (arg=="0"|| arg=="1"|| arg=="2") 
           {sscanf(arg,"%d",ans1); arg=ans[ans1];}
        message_vision("$N答道：" + arg + "。\n", this_player());
        if( (arg== "巡山" || arg== "巡山的") && present("yao pai", this_player()))
          {
          command("look " + me->query("id") );
          command("kick " + me->query("id") );
          command("say 跑哪去啦？大王等你回话都等急了！\n");
          message_vision("乌鸦先生道：快给我进去！\n", me);
          message_vision("只见乌鸦先生嘴里念叨了几句，一脚踢中$N的屁股，$N腾云驾雾般飞了出去．．．\n", me);
          me->move("/d/xueshan/binggu");
          tell_room( environment(me),"天空中$N狠狠的摔了下来，样子有些狼狈。\n",me);
          } 
        else if( (arg== "护山" || arg== "护山的") && present("yao pai", this_player()))
          {
          command("look " + me->query("id") );
          command("kick " + me->query("id") );
          command("say 护山的跑这来干嘛？快回去！\n");
          message_vision("只见乌鸦先生嘴里念叨了几句，一脚踢中$N的屁股，$N腾云驾雾般飞了出去．．．\n", me);
          me->move("/d/xueshan/binggu");
          tell_room( environment(me),"天空中$N狠狠的摔了下来，样子有些狼狈。\n",me);
          } 
        else if(arg== "守山" || arg== "守山的") 
          {
          command("kick " + me->query("id") );
          command("say 即是守山的，就在这给我老老实实呆着吧！\n");
          command("idle " + me->query("id") );
          command("idle");
          } 
        else 
          {
          command("hehe " + me->query("id") );
          command("say 请吧！\n");
          this_player()->set_temp("to_xueshan", 1);
          }
        return 1;
}


