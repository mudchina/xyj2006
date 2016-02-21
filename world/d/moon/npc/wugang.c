// wugang.c

inherit NPC;

void create()
{
        set_name("Îâ¸Õ", ({"wu gang","wugang","wu","gang"}));
        set("gender", "ÄĞĞÔ" );
        set("age", 35);
        set("long", "Ò»¸öÆøÓî²»·²µÄ´óºº£®");
        set("combat_exp", 100000);
  set("daoxing", 300000);

        set("attitude", "peaceful");

        set("eff_dx", 40000);
        set("nkgain", 200);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 80);
        set_skill("literate", 50);
        set_skill("force", 50);   
        set_skill("axe", 100);
        set("per", 27);
        set("max_kee", 500);
        set("max_gin", 200);
        set("max_sen", 300);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 15);
        setup();
        carry_object("/d/ourhome/obj/linen")->wear();
        carry_object("/d/moon/obj/bigaxe")->wield();
}

int accept_fight(object me)
{
        command("jump");     
        command("say ÕıºÃ£¡ÎÒ¿³ÁË°ëÌìÊ÷£¬Ò²¸Ã»»»»ÁË¡£");
        return 1;
}

ÿ