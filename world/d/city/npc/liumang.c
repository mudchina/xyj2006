inherit NPC;

void create()
{
        set_name("小流氓", ({"xiao liumang", "liumang", "punk"}) );
        set("gender", "男性" );
        set("age", 18+random(10));
        set("long",
"这是长安城里一个游手好闲的小流氓，一双眼睛贼溜溜的。\n");

        set_temp("apply/defense", 15);
        set("combat_exp", 3500);
        set("per", 15);
        set("attitude","heroism");

        set("chat_chance",10);
        set("chat_msg",
        ({
                "小流氓嘴里不干不净地嘟囔着。\n",
                "小流氓笑嘻嘻地，不怀好意地打量着你。\n",
                (: random_move :),
        }));

        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        add_money("coin", 40+random(90));
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
                        say( "小流氓贼塌兮兮地说：这位" +
RANK_D->query_respect(ob)
                                + "，要我给你介绍一些有趣的去处吗？\n");
                        break;
                case 1:
                        command ("hehe " + ob->query("id") );
                        break;
                case 2:
                        command ("grin " + ob->query("id") );
                        break;
                case 3:
                        command ("hi " + ob->query("id") );
                        break;
                case 4:
                        command ("xixi " + ob->query("id") );
                        break;
                case 5:
                        command ("look " + ob->query("id") );
                        break;

        }

}

