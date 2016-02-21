// ma-yuanshuai.c

inherit NPC;

void create()
{
        set_name("ÂíÔªË§", ({"ma yuanshuai","ma","yuanshuai","hou","mahou"}));
        set("gender", "ÄĞĞÔ" );
        set("age", 50);
        set("long", "Ò»Ö»ÉíÇ¿Ìå×³µÄ´óÂíºï¡£\n");
        set("combat_exp", 90000);
  set("daoxing", 100000);

        set("attitude", "peaceful");
        set("str",40);
        set_skill("unarmed", 80);
        set_skill("dodge", 110);
        set_skill("parry", 80);
        set_skill("force", 50);   
        set("per", 10);
        set("max_kee", 600);
        set("max_gin", 100);
        set("max_sen", 300);
        set("max_force", 400);
        set("force",400);
        set("max_mana",200);
        set("mana",200);
        set("force_factor", 20);
        setup();
}

int accept_fight(object me)
{
        return 0;
}

ÿ