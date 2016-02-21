// laoyu.c

inherit F_VENDOR_SALE;
void create()
{
    reload("lao_li");
       set_name("老李头", ({"lao li", "li"}));
       set("long", "铁铺的主人．\n");
       set("gender", "男性");
	set("title", "铁匠");
	set("per", 15);
	set("combat_exp", 6800);
       set("age", 56);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 15);
set("chat_chance", 5);
set("chat_msg", ({
name()+"一脚踢在小学徒的屁股上，嚷道：不许偷懒！\n",
name()+"对小学徒嚷道：教你多少次了！你怎么这么笨！\n",
}) );
        set("vendor_goods", ([
                "blade": "/d/gao/obj/blade",
                "sword": "/d/gao/obj/sword",
		"dagger": "/obj/example/dagger",
        ]) );
	setup();
       add_money("coin", 50+random(200));
        carry_object("/obj/cloth")->wear();
        carry_object("/d/obj/weapon/hammer/hammer")->wield();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( name()+"大声说道：这位" +
RANK_D->query_respect(ob)
                                + "，要买铁器吗？\n");
                        break;
        }
}

