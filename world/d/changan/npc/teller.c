// teller.c
//cglaem...12/16/96.

inherit NPC;

void create()
{
        set_name("袁守诚", ({"teller","yuan"}));
        set("title","算命先生");
        set("gender", "男性" );
        set("age", 55);
        set("class","taoist");
        set("long", "能知天地理，善晓鬼神情．长安城里没有不认识他的。\n");
        set("combat_exp", 1000);
        set("attitude", "peaceful");
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("literate", 50);
        set_skill("spells", 50);
        set("per", 15);
        set("max_kee", 250);
        set("max_gin", 300);
        set("max_sen", 300);
        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("inquiry", ([
                "name" : "小道姓袁名守诚...嘿嘿，在这长安一带还算小有薄名。\n",
                "here" : "你没来过长安？这地方可是天下第一繁华所在。\n", 
	    "算命" : "你等会再来吧。我的酒瘾又犯了，得先去喝一杯。\n",
	    "算卦" : "你等会再来吧。我的酒瘾又犯了，得先去喝一杯。\n",
	 ]) );

        set("chat_msg", ({
	    "袁守诚晃了晃手上的桂花酒袋笑道：我这人没别的毛病，就是好点这个。\n",	
                "袁守诚上上下下打量了你几眼。\n",
                "袁守诚皱了皱眉，一副欲言又止的样子。\n",
                "袁守诚神秘兮兮地四面张望了一下，在你耳边悄声道：\n客官最近没觉得哪儿不得劲？\n",
                (: random_move :)
        }) );
}

int accept_object(object me, object ob)
{
	object nowords;

     if ((string)ob->query("name")!="桂花酒袋") {
            command("say 不敢当不敢当...您太客气了。");
	    command("give " + ob->query("id") + "to " + me->query("id"));
            return 1;
        }
        else {
		command("touch " + me->query("id"));
       		command("say 这位" + RANK_D->query_respect(me) + "就是跟我投缘！\n这里我也有一点小意思，请笑纳。\n");
	        carry_object("/d/ourhome/obj/nowords");
	        command("give nowords to " + me->query("id"));
       		return 1;
        }
}


