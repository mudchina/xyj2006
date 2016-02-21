//baogong.c

inherit NPC;

void create()
{
        set_name("包公", ({ "baogong" }));
        set("long", "铁面无私黑包公。见到了他，你不由得胆颤心惊，双腿发软。\n");
        set("gender", "男性");
        set("age", 50);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per" ,10);
        set("combat_exp", 50000);

        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
}

void init()
{       
        object ob=this_player();
	string id;
	object me=this_object();
        ::init();
	if (!wizardp(ob)) 
	{
	 command("chat* 只听"+me->query("name")+"一声暴喝："+ob->query("name")+"，你这"+ RANK_D->query_rude(ob)+"！还不给我从实招来！\n");
	 me->set("id",getuid(ob));
	 me->set("name",ob->query("name"));
	 command("chat* "+ob->query("name")+
	   "膝盖一软，扑通一声跪在地上：是是是...我有罪！我罪该万死！包大人...爷爷饶命！\n");
	 me->set("id","baogong");
	 me->set("name","包公");
	 command("chat* "+me->query("name")+"一声冷哼道：来啊！把这"+RANK_D->query_rude(ob)+"给我打入大牢！\n");
	 ob->set("startroom","/d/wiz/gongtang");
	 ob->move("/d/wiz/punish");
	 }
}


