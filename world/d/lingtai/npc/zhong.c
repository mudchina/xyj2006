// worker.c

inherit NPC;

void create()
{
        set_name("µÀÊ¿", ({"taoist", "dao"}));
        set("gender", "ÄÐÐÔ" );
        set("age", 23);
        set("long", "Ò»¸öµÀÊ¿£¬¿´ÆðÀ´ÎÞ¾«´ò²ÉµÄÑù×Ó¡£\n");
        set("combat_exp", 12000);
  set("daoxing", 30000);

        set("attitude", "peaceful");
        set_skill("dodge", 20);
	set("class", "taoist");
        set_skill("parry", 30);
        set_skill("unarmed", 30);  
        set("per", 30);
        set("max_kee", 300);
        set("max_sen", 300);
        set("force", 150);
        set("max_force", 100);
        set("force_factor", 3);
	set("max_mana", 50);
	set("mana", 50);
	set("mana_factor", 1);
        setup();
	carry_object("/d/lingtai/obj/cloth")->wear();
}

ÿ