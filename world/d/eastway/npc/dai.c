inherit NPC;

void create()
{
        set_name("戴文重", ({"dai wenzhong", "dai"}));
        set("age", 42);
        set("gender", "男性");
        set("long",
"货行里的老板，长的圆圆胖胖的。\n");
        set("title", "货行老板");
        set("attitude", "peaceful");

        set("combat_exp", 40000);
        set("shen_type", 1);
        set("max_force", 300);
        set("force", 300);
        set("force_factor", 5);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("parry", 40);
//        set("inquiry", ([
// 	 ]) );
        setup();
	add_money("silver", 2);
        carry_object("/d/obj/cloth/choupao")->wear();
}

