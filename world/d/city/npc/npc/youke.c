// youke.c

inherit NPC;

void create()
{
	set_name("游客", ({ "youke", "traveller"}));
	if(random(10)<7)
	    set("gender", "男性" );
	else
	    set("gender", "女性" );
	set("age", 15+random(50));
	set("long",
		"这是一位来长安城的外地游客，风尘朴朴。\n");
	set("chat_chance", 40);
        set("chat_msg", ({
		(: random_move :)
	}));

	set("combat_exp", 600+random(400));
	set("attitude", "friendly");
	set_skill("dodge", 10);
	set_skill("unarmed", 10);
	setup();
	carry_object("/obj/cloth")->wear();
	add_money("silver", 3+random(20));
}

