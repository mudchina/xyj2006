inherit NPC;

void create()
{
       set_name("Áú±íµÜ", ({"long biaodi", "long", "biaodi"}));

set("long","ÁúÉÙÒ¯µÄ±íµÜºÍËÀµ³£®\n");
       set("gender", "ÄÐÐÔ");
       set("age", 26);
	set("per", 30);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set_skill("unarmed", 60);
	set_skill("dragonfight", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("dragonstep", 60);
	map_skill("dodge", "dragonstep");
	map_skill("unarmed", "dragonfight");
	set("force", 400);
	set("max_force", 400);
	set("force_factor", 5);
        set("combat_exp", 126000);
  set("daoxing", 50000);

        setup();
        add_money("gold", 1);
        carry_object("/d/ourhome/obj/choupao")->wear();

}

ÿ