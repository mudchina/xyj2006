
//note: this is created from player data.
//smallfox.c with foxer.c
inherit NPC;

void create()
{
	set_name("小狐狸", ({"smallfox"}));
	set("long", "阿绣的小丫环。\n");
	set("gender", "女性");
	set("age", 15);
	set("attitude", "friendly");
	set("per", 20);

	setup();

	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/cloth/skirt")->wear();
}

