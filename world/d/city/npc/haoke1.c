inherit NPC;

void create()
{
        set_name("酒客", ({"jiu ke"}));
        set("age", 32);
        set("gender", "男性");
        set("long",
"一个精精瘦瘦的小个子，越喝还越有精神。\n");
        set("attitude", "peaceful");

        set("combat_exp", 20000);
        set("shen_type", 1);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 5);
        set_skill("unarmed", 40);
        set_skill("dodge", 50);
        set_skill("parry", 50);
	setup();
        carry_object("/d/obj/cloth/piyi")->wear();
}


