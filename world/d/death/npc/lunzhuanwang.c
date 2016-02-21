//puti.c
//inherit NPC;
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;

void create()
{
       set_name("ÂÖ×ªÍõ", ({"lunzhuan wang", "wang"}));
       set("title", "Òõ¼äÊ®ÍõÖ®");
       set("gender", "ÄÐÐÔ");
       set("age", 70);
	set("class", "youling");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 30);
        set("int", 30+random(5));
       set("max_kee", 900);
       set("max_gin", 700);
       set("max_sen", 700);
       set("force", 450);
       set("max_force", 400);
       set("force_factor", 30);
       set("max_mana", 800);
       set("mana", 800);
       set("mana_factor", 40);
       set("combat_exp", 660000);
  set("daoxing", 500000);

	set_skill("spells", 100);
	set_skill("gouhunshu", 100);
       set_skill("unarmed", 139);
       set_skill("dodge", 139);
       set_skill("parry", 130);
	set_skill("force", 100);
	set_skill("tonsillit", 100);
	map_skill("spells", "gouhunshu");
	map_skill("force", "tonsillit");
	create_family("ÑÖÂÞµØ¸®", 1, "ÄãºÃ");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/lingtai/obj/putibang")->wield();
}

ÿ
