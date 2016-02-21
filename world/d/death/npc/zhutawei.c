//puti.c
inherit NPC;

void create()
{
       set_name("ÖìÈð", ({"zhu rui", "zhu"}));
	set("title", "Ì«Î¾");
       set("gender", "ÄÐÐÔ");
	set("long", "ÖìÌ«Î¾ÊÇË¾·¿µÄ×Ü¹Ü£¬¸ºÔð¹ÜÀíÎÄ¼þ£®\n");
       set("age", 20);
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 30);
       set("max_kee", 400);
       set("max_gin", 400);
       set("max_sen", 400);
       set("force", 250);
       set("max_force", 300);
       set("force_factor", 10);
       set("max_mana", 200);
	set("mana", 200);
       set("mana_factor", 10);
       set("combat_exp", 70000);
  set("daoxing", 100000);

       set_skill("unarmed", 50);
       set_skill("dodge", 60);
	set_skill("kusang-bang", 40);
       set_skill("parry", 70);
	set_skill("stick", 50);
        set_skill("force", 50);
	map_skill("stick", "kusang-bang");
	map_skill("parry", "kusang-bang");

setup();

        carry_object("/d/obj/cloth/choupao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/obj/weapon/stick/zhaohun")->wield();
}

ÿ