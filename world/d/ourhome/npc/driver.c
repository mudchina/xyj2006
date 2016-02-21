// waiter.c

inherit NPC;

void create()
{
	set_name("司机", ({ "driver", "siji" }) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
		"他揭开盖在脸上的破草帽看了你一眼 ，又放下来继续打瞌睡。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "师傅");
	setup();
	carry_object("/obj/cloth")->wear();
}

