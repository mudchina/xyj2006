//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//海上三星

inherit NPC;
string ask_me();
void create()
{
        set_name("福星", ({"fu xing", "xing"}));
   set("title", "蓬莱三老");
   set("gender", "男性");
   set("long", "霄汉中间一老人，手捧如意飞蔼绣。葫芦藏蓄万年丹，宝篆名书千纪寿。
洞里乾坤任自由，壶中日月随成就。遨游四海任清闲，散淡十洲容福胄。
曾赴蟠桃醉几遭，醒时名月还依旧。方面玉颜多神俊，三缕长苒飘颌边。\n");
        set("attitude", "peaceful");
        set("combat_exp", 800000);
   create_family("五庄观", 2, "弟子");
   set("age", 70);
   set("per", 100);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
   set("class", "xian");
   set("rank_info/respect", "老福星");
   set("max_kee", 1000);
   set("max_sen", 1000);
   set("force", 1000);
   set("max_force", 1000);
   set("force_factor", 40);
   set("max_mana", 600);
   set("mana",600);
   set("mana_factor", 50);
   
   set_skill("spells", 120);
   set_skill("taiyi", 120);
   set_skill("force",120);
   set_skill("zhenyuan-force",120);
   set_skill("parry", 120);
   set_skill("dodge", 120);
   set_skill("baguazhen", 100);
   set_skill("unarmed", 100);
   set_skill("wuxing-quan", 100);
   set_skill("sword",110);
   set_skill("xiaofeng-sword",120);
   set_skill("blade",110);
   set_skill("yange-blade",120);

   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("dodge", "baguazhen");
   map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "xiaofeng-sword");
   map_skill("blade", "yange-blade");

        set("inquiry", ([
     "碧藕"     : "我没那玩意，去问问老寿星吧！\n",
                "交梨"     : "我没那玩意，去问问老禄星吧！\n",
     "name"     : "老夫福星是也。\n",
     "here"     : "此乃蓬莱仙岛也。\n",
     "下棋"      : "你个臭棋篓子，谁要跟你下棋！\n",
     "围棋"     : "连围棋都不知道？\n",
                "火枣"     : (: ask_me :),
        ]));

   set("time", 1);
   setup();
   carry_object("/d/obj/cloth/bai")->wear();   
   carry_object("/d/penglai/npc/obj/bag");
   carry_object("/d/nanhai/obj/jp2");

}

string ask_me()
{
        object ob;
           
   if((int)this_player()->query("combat_exp") < 30000 )
     return "没见老夫正下棋呢吗，以后再说吧！\n";

   // added by snowcat on 6/22/1997
   if (this_object()->is_fighting())
     return "没见老夫正打着吗，以后再说吧！\n";

   if ( present("huo zao", this_player()) )
     return "吃，吃，吃，胖的都象猪了！\n";

        if ( present("huo zao", environment()) )
     return "那不是有一块呢嘛，吃完再说！\n";

   if(query("time") <1 )
     return "不巧，不巧，我也没了！\n";

     say("福星说道：那到要瞧你够不够格吃了，放马过来吧！\n");
     this_player()->set_temp("shouxing_fight", 1);
     return ("嘿嘿！\n");
}


int accept_fight(object who)
{
     object me;
    me = this_object();
     if (!who->query_temp("shouxing_fight")){
     command("say 不打不打，没见老夫正下棋呢吗！\n");
         return 0;
   }
   // added by snowcat on 6/22/1997
     if (me->is_fighting()){
     command("say 不打不打！\n");
         return 0;
   }
   say("福星笑道：老头子活了几千年，谁也不怕！\n");
   me->set("eff_kee", (int)me->query("max_kee"));
        me->set("kee", (int)me->query("max_kee"));
        me->set("eff_sen", (int)me->query("max_sen"));
        me->set("sen", (int)me->query("max_sen"));

     who->set_temp("shouxing_fight",0);
     remove_call_out("check_fight");
     call_out("check_fight", 1, me, who);
     return 1;
}

void player_win (object me, object who)
{
     object obj;
     // added by snowcat on 6/22/1997
   if (me->query("time")<=0)
     return;
   obj=new("/d/obj/drug/huozao");
   say("福星叹了一口气：年纪大了，到底气力还是不济！\n");
   say("如此武艺高强，真是令我等佩服啊！\n");
   obj->move(who);
        me->add("time", -1);
   message_vision("福星对$N哈哈笑道：深感法力，无物可以表敬，特具火枣，笑纳！\n", who);
   call_out("reg", 750);
}
int reg()
{
   object me=this_object();
   me->set("time", 1);
   return 1;
}
void player_lose (object me, object who)
{
     string msg;
     msg = RANK_D->query_respect(who);
   
   command("jump");
   say("福星哈哈大笑："+msg+"莫要不高兴，回去好好练武吧，来日方长嘛！\n");
}
void check_fight (object me, object who)
{
     int my_kee, whos_kee;
     int my_max_kee, whos_max_kee;

   if(!who) return;
     my_kee = me->query("kee");
     whos_kee = who->query("kee");
     my_max_kee = me->query("max_kee");
     whos_max_kee = who->query("max_kee");

     if (me->is_fighting()){
         remove_call_out("check_fight");
         call_out ("check_fight",1,me,who);
         return;
     }

     if (!present(who, environment(me)))
         return;

   // changed by snowcat on 6/24/1997
   // bug abuse: player can exert recover when fight stops, 
   //if ((my_kee*100/my_max_kee) <=(whos_kee*100/whos_max_kee) )
   //   player_win (me, who);
   //else player_lose (me, who);
   if ((my_kee*100/my_max_kee) <= 50)
     player_win (me, who);
   else if ((whos_kee*100/whos_max_kee) <= 50)
     player_lose (me, who);
}

void die()
{

        if( environment() ) {
        message("sound", "\n\n只听一声鹤鸣，福星化作一道白光向天上直冲而去。。。\n\n
半空中有人哈哈笑了几声。。。\n\n", environment());
        }

        destruct(this_object());
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="五庄观" )
   {
     if( (int)ob->query("family/generation") < 3  )
     {
        command("say 不敢当，不敢当。\n");
     }
     else if( (int)ob->query("family/generation") ==3  )
     {
        command("say 呵呵，是" + ob->query("family/master_name") + "老头的徒弟，那我就不客气了。\n");
        command("recruit " + ob->query("id") );
     }
     else 
     {
        if( ob->query_skill("taiyi", 1) >= 80 )
        {
          command("say 好，有出息，这个徒弟我收下了。\n");
          command("recruit " + ob->query("id") );
        }
        else
        {
          command("say 我们仙家最看重仙法，你还得在这方面下苦功。\n");
        }
     }
   }

   else
   {
     command("say 好，不过你还是先找八仙他们练一些入门的功夫吧。\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "xian");
}




