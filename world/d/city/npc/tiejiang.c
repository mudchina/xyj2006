// waiter.c

inherit F_VENDOR_SALE;

void create()
{
    reload("zhoutiejiang");
        set_name("周铁匠", ({ "zhou tiejiang", "zhou", "tiejiang", "smith"
}) );
        set("gender", "男性" );
	set("title","铁匠");
        set("age", 42);
        set("long",
                "周铁匠四十多岁，长得虎背熊腰。。\n");
        set("combat_exp", 10000);
        set("attitude", "peaceful");

        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("literate", 40);

        set("max_kee", 600);
        set("max_sen", 600);


        set("vendor_goods", ([
                "dagger": "/d/obj/weapon/dagger/dagger.c",
                "axe": "/d/obj/weapon/axe/tiefu.c",
                "hammer": "/d/obj/weapon/hammer/hammer",
		"fork": "/d/obj/weapon/fork/fork",
	    "tiegun": "/d/obj/weapon/stick/bintiegun",
		"tielian":"/d/obj/weapon/whip/tielian",
        ]) );
        setup();

        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/weapon/hammer/hammer")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( name()+"说道：这位" +
RANK_D->query_respect(ob)
                                + "，进来随便看看吧。\n");
                        break;
                case 1:
                        say(name()+ "用脖子上的毛巾抹了抹手，说道：这位" +
RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
                case 2:
                        say(name()+ "说道：这位" +
RANK_D->query_respect(ob)
                                + "，进来挑一件称手的兵器吧。\n");
                        break;
        }
}

