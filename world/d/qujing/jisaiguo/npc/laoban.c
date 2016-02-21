inherit NPC;

void create()
{
       set_name("刘老板", ({"liu laoban", "laoban"}));
       set("gender", "男性");
       set("age", 40);
        set("long", "一个矮矮胖胖，满面笑容的小老板。\n");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 20);
	set("str", 20);
       set("combat_exp", 8000);
        set_skill("unarmed", 15);
        set_skill("dodge", 15);
        set_skill("blade", 15);
        set_skill("parry", 15);
	set_skill("force", 15);
	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	add_money("silver", 2+random(3));
}

