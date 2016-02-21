inherit NPC;

void create()
{
        set_name("胖秀才", ({"xiucai"}));
        set("age", 22);
        set("gender", "男性");
        set("long",
"国子监里的学生，正在吟诗作赋。\n");
        set("attitude", "friendly");
	set("per", 22);
        set("combat_exp", 4000);
        set("shen_type", 1);
        set("class", "scholar");
        set_skill("unarmed", 30);
        set_skill("dodge", 10);
        set("chat_chance", 4);
        set("chat_msg", ({
"胖秀才哈哈大笑，不知想到了什么．\n",
"胖秀才愁眉苦脸的．\n",

}) );

	setup();

        carry_object("/d/gao/obj/changpao")->wear();
}
