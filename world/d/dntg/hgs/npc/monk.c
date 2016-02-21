
inherit NPC;

void create()
{
       set_name("ÓÎ·½É®ÈË", ({"monk"}));
       set("gender", "ÄÐÐÔ");
	set("long", "Ò»Î»°×¾»Á³µÄ´óºÍÉÐ¡£\n");
        set("combat_exp", 8000+random(2000));
  set("daoxing", 10000);

	set("per", 18);
       set("age", 40);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set_skill("unarmed", 25);
	set_skill("parry", 25);
	set_skill("dodge", 25);
        setup();
       add_money("coin", 20+random(50));
	carry_object("/d/obj/cloth/sengyi")->wear();
}

ÿ