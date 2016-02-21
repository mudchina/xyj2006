inherit NPC;

void create()
{
	set_name("女孩",({ "girl" }) );
        set("gender", "女性" );
        set("age", 12);
	set("long", "这是个长安城的典型少女，虽然只有十三、四岁，但是已经打扮入时。\n");
        set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("str", 14);
        set("dex", 15);
	set("per", 25);
	set("con", 16);
        set("int", 15);
        set("attitude", "friendly");
	setup();
	carry_object("/d/obj/cloth/pink_cloth")->wear();
	add_money("coin", 50);
}

