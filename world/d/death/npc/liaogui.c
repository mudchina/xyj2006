//puti.c
inherit NPC;

void create()
{
       set_name("â²ÑÀ¹í", ({"liaoya gui", "gui"}));
       set("gender", "ÄÐÐÔ");
       set("age", 30);
	set("long", "Ò»¸öâ²ÑÀ¹í£¬ÃæÄ¿ÕøÄü¿ÉÅÂ£®\n");
       set("attitude", "heroism");
       set("shen_type", 1);
       set("per", 100);
       set("combat_exp", 40000);
  set("daoxing", 20000);

	set_skill("unarmed", 45);
	set_skill("blade", 45);
	set_skill("dodge", 45);
	set_skill("parry", 55);
	set_skill("force", 50);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 10);
	set("max_kee", 550);
	set("max_sen", 300);
        set("mana", 60);
        set("max_mana", 60);
        set("mana_factor", 10);


setup();

        carry_object("/d/gao/obj/blade")->wield();
}

ÿ