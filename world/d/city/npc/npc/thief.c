inherit NPC;

void create()
{
        set_name("瘦老头", ({"lao tou","lao", "tou"}));
        set("gender", "男性" );
        set("age", 55+random(10));
        set("long",
"看起来又干又瘦，贼眉鼠眼。
他也正在上下打量着你。\n");

        set("combat_exp", 8000+random(1000));
        set("per", 10);
        set("attitude","heroism");
	set("max_kee", 700);
        set("chat_chance",10);
	set_skill("stealing", 80);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 40);
        set("chat_msg",
        ({
                "老头笑嘻嘻地，不怀好意地打量着你。\n",
                (: random_move :),
        }));
        set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
                (: command, "surrender" :),
        }) );


        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        add_money("silver", 1);
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;

        switch( random(6) ) {
                case 0:
                        say( "老头嘴里不知说着什么。\n");
                        break;
                case 1:
                        command ("steal silver from " + ob->query("id") );
                        break;
                case 2:
                        command ("steal coin from " + ob->query("id") );
                        break;
                case 3:
                        command ("steal jitui from " + ob->query("id") );
                        break;
                case 4:
                        command ("grin");
                        break;
                case 5:
                        command ("look " + ob->query("id") );
                        break;

        }

}

int accept_fight(object me)
{
        command("say 打架？我老头那是您的对手！\n");
        return 0;
}

