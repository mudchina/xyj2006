//Cracked by Roath

//baihua xianzi
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("百花仙子", ({"baihua xianzi", "baihua", "xianzi"}));
       set("long",@LONG
西王母的弟子。奉王母之命，总司天下名花，乃群芳之主。
因与嫦娥不睦，遭其陷害，被谪凡尘。厄满后独居蓬莱，不
与广寒宫来往，所制“百花酿”为天上人间，第一玉液。
LONG);

       set("title", "群芳之主");
       set("gender", "女性");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
        set("int", 30);
       set("max_gin", 600);
  set("max_sen",3000);
  set("max_kee",3000);
   set("force",2000);
       set("max_force", 2000);
       set("force_factor", 100);
       set("max_mana", 2000);
       set("mana", 2000);
       set("mana_factor", 200);
       set("combat_exp", 800000);
       set("daoxing", 1200000);


   set("inquiry",(["百花酿":"可惜这里僻处海外，奇花品种不全。如能在酒中加入(add)它种鲜花，此酒才算酿成。",]));
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 100);
       set_skill("unarmed", 80);
       set_skill("dodge", 70);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("spells", 80);
       set_skill("moonshentong", 80);
       set_skill("baihua-zhang", 200);
       set_skill("moonforce", 80);
       set_skill("moondance", 70);
       set_skill("whip",80);
       set_skill("jueqingbian",80);
       map_skill("spells", "moonshentong");
       map_skill("unarmed", "baihua-zhang");
       map_skill("force", "moonforce");
       map_skill("dodge", "moondance");

           set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "arrow" :),
               (: cast_spell,"mihun" :),
               (: cast_spell,"shiyue" :),
        }) );
       create_family("月宫", 2, "弟子");
       setup();

       carry_object("/d/moon/obj/luoyi")->wear();
     carry_object("/d/obj/book/makeupbook");
      carry_object("/d/shendian/babu/obj/xiangjing");
       if (clonep()) carry_object("/d/obj/flower/rose")->wear();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们月宫只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;}
        if ( !ob->query_temp("denied_by_chang_e")){
          command("shake");
        command("say 我只收有缘之人，这位" +
RANK_D->query_respect(ob) + "还是去请教嫦娥吧。\n");
        return;
}

        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们月宫发扬光大。\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}
