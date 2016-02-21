// sgzl, 99.0.15.
// 换个名字好听点的好张罗生意

inherit NPC;

int test_hispai(object ob);
void give_yaopai(object ob);
string give_map(object me);
int do_yes(string arg);

void create()
  {
   set_name("神鹰使者", ({"shenying shizhe", "shizhe", "shenying", "eagle"}));
   set("gender", "男性" );
   set("age", 34);

   set("long", "大雪山巡山总督－－神鹰使者，负责四处巡查，八方联络。\n");
   set("class", "yaomo");
   set("combat_exp", 80000);
   set("daoxing", 75000);

   set("attitude", "heroism");
   create_family("大雪山", 3, "弟子");
   set_skill("unarmed", 60);
   set_skill("cuixin-zhang", 60);
   set_skill("dodge", 60);
   set_skill("xiaoyaoyou", 70);
   set_skill("parry", 60);
   set_skill("sword", 60);
   set_skill("bainiao-jian", 90);
   set_skill("force", 60);   
   set_skill("ningxie-force", 70);
   set_skill("literate", 70);
   set_skill("spells", 60);
   set_skill("dengxian-dafa", 60);
   set_skill("throwing", 30);
   map_skill("spells", "dengxian-dafa");
   map_skill("force", "ningxie-force");
   map_skill("unarmed", "yingzhaogong");
   map_skill("blade", "bingpo-blade");
   map_skill("blade", "bingpo-blade");
   map_skill("sword", "bainiao-jian");
   map_skill("parry", "bainiao-jian");

   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 700);
   set("max_force", 700);
   set("mana", 700);
   set("max_mana", 700);	
   set("force_factor", 35);
   set("mana_factor", 35);


   set("inquiry", ([
	"name" : "在下大雪山神鹰使者，有何贵干？\n",
	"here" : "管它呢！反正比不上我们大雪山。\n",
        "腰牌" : (: test_hispai :),
	"大雪山" : (: give_map :),
	]) );

   set("no_map", 0);

   setup();

   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   carry_object("/d/obj/armor/tenjia")->wear();
   carry_object("/d/gao/obj/sword")->wield();
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="大雪山" )
     {
       if( (int)ob->query("family/generation") < 3  )
          command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
       else if( (int)ob->query("family/generation") ==3  )
	  command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣大爷我了！\n");
      else 
         {
	  command(":D");
	  command("say 好！" + RANK_D->query_respect(ob) + "投入我的门下，包你吃香的，喝辣的！\n");
	  command("recruit " + ob->query("id") );
          ob->set("title", "大雪山巡山小妖");
          ob->set("class", "yaomo");
   if(! ob->query_temp("get_yaopai") )  give_yaopai(ob);
	 }
     }

    else
      {
       command(":D ");
       command("say 好，"+ RANK_D->query_respect(ob) +"，你到我大雪山，从巡山的开始当起，早晚定能出人头第！\n");
       command("recruit " + ob->query("id") );
       ob->set("title", "大雪山巡山小妖");
       ob->set("class", "yaomo");
       if(! ob->query_temp("get_yaopai") )  give_yaopai(ob);
      }

  return;
}

int test_hispai(object ob)
{
    object me=this_object();
    ob=this_player();
    if( (! ob->query_temp("get_yaopai") ) && ob->query("family/master_name")=="神鹰使者")   
      {
      give_yaopai(ob);
      return 1;
      }
}


void give_yaopai(object ob)
{
    object yaopai;
    object me=this_object();
    ob=this_player();
    yaopai=new("/d/xueshan/obj/yaopai");
    yaopai->move(me);
    yaopai->set("long","\n  
              ＊＊＊＊＊＊＊＊＊＊
              ＊　　威镇群魔　　＊
              ＊＊＊＊＊＊＊＊＊＊

　              大雪山巡山使者－"+ob->query("name")+"\n");
    command("whisper " + ob->query("id") + " 这是你巡山的腰牌，收好了。");
    command("give yao pai to " + ob->query("id"));
    ob->set_temp("get_yaopai", 1);
    return;
}


string give_map(object me)
{
	me=this_player();
	me->set_temp("need_map", 1);
	return "大雪山，那可是个好地方，你想去吗(yes)？\n";
}

void init()
{
	add_action("do_yes", "yes");
}

int do_yes(string arg)
{
	object me;

	me=this_player();
	
	if(me->query_temp("need_map")) 
	{
		message_vision("$N答道：想去！\n\n", me);
		if( query("no_map") == 0 )
		{
			message_vision("神鹰使者说道：好！那我给你一张地图吧！\n", me);
			me->set_temp("need_map", 0);

			carry_object("/d/obj/misc/xueshan-map");
			command("give xueshan map to " + me->query("id"));
			set("no_map", 1);
			call_out("regenerate", 480);
		}
		else
		{
			message_vision("神鹰使者说道：我本来想给你一张地图的，但是刚才发完了。\n", me);
		}

		return 1;
	}
	return 0;
}

int regenerate()
{
	set("no_map", 0);
	return 1;
}

