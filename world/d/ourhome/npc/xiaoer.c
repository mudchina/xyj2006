// waiter.c

//inherit NPC;
//inherit F_VENDOR;

inherit F_VENDOR_SALE;

void create()
{
	reload("ourhome_xiaoer");
	set_name("店小二", ({ "xiao er" , "xiao" , "waiter" }) );
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
       set("shop_title","店小二");
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位店小二正笑咪咪地忙着，还不时拿起挂在脖子上的抹布擦擦手。 \n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ([
		"jiudai": "/d/ourhome/obj/hdjiudai",
		"gourou": "/d/ourhome/obj/gourou",
		"xigua": "/d/ourhome/obj/watermelon",
		"jitui": "/d/ourhome/obj/jitui",
	]) );
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
	if( !ob || !visible(ob) || environment(ob) != environment() ) return;
		if((string)ob->query("startroom")=="/d/ourhome/kedian"){
                		ob->set("startroom","/d/city/kezhan");
		}	
	switch( random(3) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
		case 2:
			say( "店小二说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝几盅小店的花雕吧，这几天才从窖子里开封的哟。\n");
			break;
	}
}
