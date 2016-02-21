inherit NPC;

void create()
{
        set_name("´óºÍÉÐ", ({"monk"}));
        set("long", "Ò»Î»´óºÍÉÐ£¬¿´ÆðÀ´´ÈÉÆµÄºÜ£¬¿ÚÀï»¹²»Í£µÄÓ½¾­¡£\n");

        set("gender", "ÄÐÐÔ");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 30+random(10));
	set("combat_exp", 15000);
  set("daoxing", 30000);

        set("shen_type", 1);
        set("per", 25);
        set("max_kee", 380);
        set("max_gin", 300);
	set("force", 250);
	set("force_factor", 5);
        set_skill("force", 20+random(20));
        set_skill("unarmed", 20+random(20));
        set_skill("dodge", 20+random(20));
        set_skill("parry", 20+random(40));

        setup();
        carry_object("/d/obj/cloth/sengyi")->wear();

        setup();
}

int accept_fight(object me)
{
        command("say ºÃ°É£¬Æö´ê¼¼ÒÕ£¬µãµ½ÎªÖ¹£¡\n");
        return 1;
}

ÿ