inherit NPC;

void create()
{
        set_name("高秀才", ({"xiucai"}));
        set("age", 22);
        set("gender", "男性");
        set("long",
"国子监里的学生，正在吟诗作赋。\n");
        set("attitude", "peaceful");
	set("per", 22);
        set("combat_exp", 8000);
        set("shen_type", 1);
        set("class", "scholar");
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 3);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("changquan", 20);
	map_skill("unarmed", "changquan");
        set("chat_chance", 4);
        set("chat_msg", ({
"高秀才低声吟道：一二三四五，上山打老虎，好诗，好诗呀！\n",
"高秀才长叹一声：天生我才必有用，可惜不到有用时！\n",

}) );
	setup();

        carry_object("/d/gao/obj/changpao")->wear();
}
int accept_fight(object me)
{
        command("say 哈哈，本秀才不仅才华横溢，武功也是鲜有对手！\n");
        return 1;
}

