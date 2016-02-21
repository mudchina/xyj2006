//puti.c
//inherit NPC;
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;

void create()
{
       set_name("±å³ÇÍõ", ({"biancheng wang", "wang"}));
       set("title", "Òõ¼äÊ®ÍõÖ®");
       set("gender", "ÄÐÐÔ");
	set("class", "youling");
       set("age", 50);
       set("attitude", "friendly");
       set("per", 30);
        set("int", 30);
       set("max_kee", 800);
       set("max_gin", 600);
       set("max_sen", 600);
       set("force", 450);
       set("max_force", 400);
       set("force_factor", 40);
       set("max_mana", 1000);
       set("mana", 1000);
       set("mana_factor", 20);
	set("combat_exp", 600000);
  set("daoxing", 500000);

	set_skill("spells", 119);
	set_skill("gouhunshu", 119);
       	set_skill("unarmed", 119);
       	set_skill("dodge", 119);
	set_skill("parry", 119);
	set_skill("force", 100);
	set_skill("tonsillit", 100);
	map_skill("force", "tonsillit");
create_family("ÑÖÂÞµØ¸®", 1, "ÄãºÃ");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
}

ÿ
