// waiter.c


inherit F_VENDOR_SALE;

void create()
{
        reload("wudidong_blacksmith");
        set_name("张铁臂", ({ "blacksmith", "smith", "zhang", "zhang tiebi", "tiebi" }) );
        set("gender", "男性" );
        set("age", 42);
        set("title", "铁匠");
        set("long","张铁匠正在打铁，炉火把他的脸映得通红。\n");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set("rank_info/respect", "张大哥");
        set("per",25);
        set("vendor_goods", ([
		"zhadao"  : "/d/obj/weapon/blade/zhadao.c",
		"tiefu"   : "/d/obj/weapon/axe/tiefu.c",
		"sickle"  : "/d/obj/weapon/blade/sickle.c",
		"scythe"  : "/d/obj/weapon/blade/scythe.c",
		"pickaxe" : "/d/obj/weapon/hammer/pickaxe.c",
		"plow"    : "/d/obj/weapon/hammer/plow.c",
	]));
	setup();
	carry_object("/obj/cloth")->wear();
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
	say("张铁匠说道：这位" + RANK_D->query_respect(ob)
		+"，要点什么铁器？\n");
}
