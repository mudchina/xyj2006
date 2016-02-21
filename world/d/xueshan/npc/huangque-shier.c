// sgzl, 99.0.15.

inherit NPC;

int test_hispai(object ob);
void give_yaopai(object ob);
string give_map(object me);
int do_yes(string arg);

void create()
  {
   set_name("黄雀侍儿", ({"huangque shier", "shier", "huangque"}));
   set("gender", "女性" );
   set("age", 22);

   set("long", "孔雀公主的贴身侍卫头领。\n");
   set("class", "yaomo");
   set("combat_exp", 35000);
   set("daoxing", 35000);

   set("attitude", "heroism");
   create_family("大雪山", 3, "弟子");
   set_skill("unarmed", 40);
   set_skill("yingzhaogong", 50);
   set_skill("cuixin-zhang", 50);
   set_skill("dodge", 60);
   set_skill("xiaoyaoyou", 60);
   set_skill("parry", 60);
   set_skill("sword", 60);
   set_skill("bainiao-jian", 60);
   set_skill("throwing", 80);
   set_skill("force", 61);   
   set_skill("ningxie-force", 60);
   set_skill("literate", 80);
   set_skill("spells", 70);
   set_skill("dengxian-dafa", 60);
   map_skill("spells", "dengxian-dafa");
   map_skill("force", "ningxie-force");
   map_skill("unarmed", "yingzhaogong");
   map_skill("blade", "bingpo-blade");
   map_skill("sword", "bainiao-jian");
   map_skill("parry", "bainiao-jian");

   set("max_kee", 300);
   set("max_sen", 300);
   set("force", 300);
   set("max_force", 300);
   set("mana", 300);
   set("max_mana", 300);	
   set("force_factor", 15);
   set("mana_factor", 15);


   set("inquiry", ([
	"here" : "这就是大雪山啦！\n",
	]) );


   setup();

   carry_object("/d/obj/cloth/xueshan-pao")->wear();
   carry_object("/d/obj/armor/tenjia")->wear();
   carry_object("/d/moon/obj/snow_sword")->wield();
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="大雪山" )
     {
       if( (int)ob->query("family/generation") < 3  )
          command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
       else if( (int)ob->query("family/generation") ==3  )
	  command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣本姑娘了！\n");
      else 
         {
	  command("ok");
	  command("say 好！" + RANK_D->query_respect(ob) + "投入我的门下，可要听话，不听师傅的话，有你的好看！\n");
	  command("recruit " + ob->query("id") );
          ob->set("title", "大雪山公主侍卫");
          ob->set("class", "yaomo");
   if(! ob->query_temp("get_yaopai") )  give_yaopai(ob);
	 }
     }

    else
      {
       command(":D ");
       command("say 好，"+ RANK_D->query_respect(ob) +"，你到我大雪山，从巡山的开始当起，早晚定能出人头第！\n");
       command("recruit " + ob->query("id") );
       ob->set("title", "大雪山公主侍卫");
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

　              大雪山公主侍卫－"+ob->query("name")+"\n");
    command("whisper " + ob->query("id") + " 这是你的侍卫腰牌，收好了。");
    command("give yao pai to " + ob->query("id"));
    ob->set_temp("get_yaopai", 1);
    return;
}


