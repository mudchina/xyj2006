inherit NPC;

void create()
{
       set_name("书生", ({"shu sheng", "sheng"}));
       set("gender", "男性");
       set("age", 20);
        set("long", "一个白面皮，手无缚鸡之力的书生。\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 24);
	set("str", 10);
       set("combat_exp", 5000);
        set_skill("unarmed", 5);
        set_skill("dodge", 5);
        set_skill("blade", 5);
        set_skill("parry", 5);
	set_skill("force", 5);
	setup();
	carry_object("/d/obj/cloth/changpao")->wear();
	add_money("silver", 2);
}

