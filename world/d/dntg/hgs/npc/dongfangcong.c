inherit NPC;

void create()
{

        set_name("东方聪", ({ "dongfang cong", "dongfang", "cong"}) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "东方聪是馆主的大儿子，正教一些徒弟武艺。\n");
        set("combat_exp", 20000);
	set("title", "武馆教头");
	set_skill("stick", 50);
	set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
	set_skill("force", 40);
        setup();
        add_money("silver", 1+random(20));
        carry_object("/d/obj/cloth/choupao")->wear();
}

int recognize_apprentice()
{
	if(!this_player()->query("newbie/learn") )
	return notify_fail("东方聪笑道：教不教你，你去问爹。\n");

	return 1;
}
