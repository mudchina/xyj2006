inherit NPC;

void create()
{
        set_name("王林", ({"wang lin", "wang"}));
        set("age", 32);
        set("gender", "男性");
        set("long", "肉铺的老板，长的虎背熊腰。\n");
        set("attitude", "peaceful");
	set("title", "肉铺老板");
        set("combat_exp", 40000);
        set("shen_type", 1);
	set("max_force", 400);
	set("force", 400);
	set("force_factor", 5);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("parry", 50);
	set_skill("blade", 40);
	setup();
	add_money("silver", 10);
        carry_object("/d/obj/cloth/linen")->wear();
	carry_object("/d/city/npc/obj/caidao")->wield();
}


