// youke.c

inherit NPC;

void create()
{
	set_name("路人", ({ "luren", "ren"}));
	if(random(10)<6)
	    set("gender", "男性" );
	else
	    set("gender", "女性" );
	set("age", 15+random(50));
	set("chat_chance", 20);
        set("chat_msg", ({
		(: random_move :)
	}));
	set("per", 10+random(10));
	set("combat_exp", 1000+random(1000));
	set("attitude", "friendly");
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	setup();
	carry_object("/obj/cloth")->wear();
	add_money("silver", 3+random(20));
}

