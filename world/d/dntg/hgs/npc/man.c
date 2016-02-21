
inherit NPC;

void create()
{
       set_name("×³ºº", ({"man"}));
       set("gender", "ÄĞĞÔ");
        set("combat_exp", 2000+random(2000));
	set("per", 18);
       set("age", 18+random(10));
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 15);
	set_skill("parry", 15);
        setup();
       add_money("coin", 20+random(50));
	carry_object("/d/obj/cloth/linen")->wear();
}

