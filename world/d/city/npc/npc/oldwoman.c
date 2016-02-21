inherit NPC;

void create()
{
	set_name("老大娘", ({ "lao daniang", "woman", "daniang" }) );
        set("gender", "女性" );
	set("age", 60);
	set("long", "一个面容和蔼的老大娘。\n");
        set("per", 26);
	set("combat_exp", 100);
	set("attitude", "friendly");

	set("chat_chance",30);
	setup();
	
	carry_object(__DIR__"obj/cloth")->wear();
	add_money("coin", 60);
}
