inherit NPC;

void create()
{

        set_name("东方小二姐", ({ "dongfang sister", "dongfang", "sister"}) );
        set("gender", "女性");
        set("age", 16);
	set("per", 28);
        set("long", "东方小二姐是馆主的远房侄女，来傲来见见世面。\n");
        set("combat_exp", 5000);
	set("max_kee", 300);
	set_skill("sword", 10);
	set_skill("parry", 10);
        set_skill("dodge", 30);
        set_skill("unarmed", 20);
	set_skill("force", 20);
set("chat_chance", 3);
set("chat_msg", ({
"小二姐说道：我好喜欢花呦！\n",
"小二姐说道：外面的花儿好香呦！\n",
}) );

        setup();
        add_money("silver", 1+random(20));
        carry_object("/d/obj/cloth/pink_cloth")->wear();
	carry_object("/d/obj/cloth/bullboots")->wear();
}

int accept_object(object who,object ob)
{
        object m;
        if (ob->query("id")=="flower") {
                say("小二姐笑道：多谢"  + RANK_D->query_respect(who) + "，我真的好喜欢呦！\n");
		command("whisper " + who->query("id") + " 我这里有舅公的一本书，你拿去看吧！\n");
        m=new("/d/obj/book/forcebook");
        m->move(who);
        call_out("destroy", 1, ob);
        return 1;
        }
        else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

