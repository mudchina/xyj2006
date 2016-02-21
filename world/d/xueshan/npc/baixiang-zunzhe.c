
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// baixiang-zunzhe.c...weiqi, 97.09.15.

inherit NPC;
string ask_chuxian();
   string ask_cancel();
void create()
{
   set_name("白象尊者", ({"baixiang zunzhe", "baixiang", "zunzhe"}));
   set("title", "明王护法");
   set("gender", "男性" );
   set("age", 43);
   set("per", 112);//no rongmao description.
   set("str", 50);
   set("long", "这位白象尊者是有名的大力士。以前在狮驼山做二大王，\n狮驼山被剿灭后他跟着青狮老魔投奔大鹏明王，做了护法尊者。\n生平最怕的是老鼠，看到尖嘴猴腮的人就讨厌。\n");
   set("class", "yaomo");
   set("combat_exp", 800000);
   set("attitude", "peaceful");
   create_family("大雪山", 2, "弟子");
   set_skill("unarmed", 150);
   set_skill("cuixin-zhang", 80);
   set_skill("dodge",100);
   set_skill("xiaoyaoyou",100);
   set_skill("parry", 120);
   set_skill("blade", 110);
   set_skill("bingpo-blade", 120);
   set_skill("force",110);
   set_skill("ningxie-force",100);
   set_skill("sword", 120);
   set_skill("bainiao-jian", 110);
   set_skill("literate", 70);
   set_skill("spells",100);
   set_skill("dengxian-dafa", 80);
   map_skill("spells", "dengxian-dafa");
   map_skill("force", "ningxie-force");
   map_skill("sword", "bainiao-jian");
   map_skill("unarmed", "cuixin-zhang");
   map_skill("blade", "bingpo-blade");
   map_skill("dodge", "xiaoyaoyou");

   set("max_kee", 1200);
   set("max_sen", 600);
   set("force", 1600);
   set("max_force", 800);
   set("mana", 800);
   set("max_mana", 400);   
   set("force_factor", 60);
   set("mana_factor", 20);

        set("eff_dx", -200000);
        set("nkgain", 400);

    set("inquiry", ([
//"索命" : (:ask_chuxian:),
   "cancel": (:ask_cancel:),
    ]));
   setup();
   carry_object("/d/obj/armor/yinjia")->wear();
   carry_object("/d/obj/weapon/blade/yanblade")->wield();
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}

void attempt_apprentice(object ob)
{
   if( (int)ob->query("str") < 20 ){
     command("kick " + ob->query("id"));
     command("say 快走，快走！我一看到尖嘴猴腮的人就有气。\n");
     return;
   }

   if( (string)ob->query("family/family_name")=="大雪山" ){
     if( (int)ob->query("family/generation") < 2  ){
        command("say 不敢，不敢。我该拜" + RANK_D->query_respect(ob) + "您为师才是。\n");
     }
     else if( (int)ob->query("family/generation") ==2  ){
        command("say 你这个" + RANK_D->query_rude(ob) + "别来消遣你爷爷我了！\n");
     }
     else if( (int)ob->query("family/generation") ==3  ){
        command(":D");
        command("say 你这个" + RANK_D->query_rude(ob) + "是不是被师父赶出来了？你爷爷我今天心情好，就收留你吧...\n");
        command("recruit " + ob->query("id") );
     }
     else {
        if( (int)ob->query("combat_exp") >= 50000 ){
          command(":D ");
          command("say 好，" + RANK_D->query_respect(ob) + "好好跟我干，将来有你的好处！\n");
          command("recruit " + ob->query("id") );
        }
        else {
          command("say 你还是找鹦鹉，乌鸦他们先练着吧。\n");
        }
     }
   }

   else{
     command("hmm");
     command("say 这位" + RANK_D->query_respect(ob) + "，你还是找鹦鹉，乌鸦他们先练练吧。\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "yaomo");
}

void init()
{       
   object ob=this_player();

   ::init();
   if ( ((string)ob->query("gender")=="男性") && ((int)ob->query("str") < 20) && (random(3) > 1) )
        {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
     command("kick " + ob->query("id"));
     command("say 尖嘴猴腮！");
     command("laugh");
     break;
   }
}

string ask_chuxian()
{
   object me=this_player();
   
   if(me->query("family/family_name")!="大雪山")
      return ("你不是本门中人!");

   command("pat "+me->query("id"));
   command("say 有志气！");
   return "/d/obj/mieyao"->query_yao(me);
}
 


