inherit NPC;

void create()
{

        set_name("东方英", ({ "dongfang ying", "dongfang", "ying"}) );
        set("gender", "女性");
        set("age", 22);
	set("per", 25);
        set("long", "东方英是馆主的独生女，武功又高，人又漂亮。\n");
        set("combat_exp", 18000);
	set("title", "武馆教头");
	set_skill("sword", 50);
	set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
	set_skill("force", 40);
        setup();
        add_money("silver", 1+random(20));
        carry_object("/d/obj/cloth/pink_cloth")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();

}

int recognize_apprentice()
{
        if(!this_player()->query("newbie/learn") )
        return notify_fail("东方英害羞地一笑：爹要是不同意，我可不敢教。\n");

        return 1;
}

