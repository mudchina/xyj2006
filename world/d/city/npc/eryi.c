inherit NPC;

void create()
{
        set_name("二姨太", ({"er yitai", "yitai"}));
        set("age", 22);
        set("gender", "女性");
        set("long",
"金家的二姨太太，见你看她，对你抛了个媚眼．\n");
        set("attitude", "friendly");
	set("per", 22);
        set("combat_exp", 1000);
        set("shen_type", 1);
        set_skill("unarmed", 10);
        set_skill("dodge", 40);
	setup();

        carry_object("/d/obj/cloth/nichang")->wear();
	carry_object("/d/obj/cloth/yuanxiang")->wear();
}
