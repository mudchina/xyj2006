inherit NPC;

void create()
{
        set_name("¹ÖÎï", ({ "Test guai",}));
        set("gender", "ÄĞĞÔ");
        set("long", "¹Ö¡£¡£¡£¡£\n");
        set("age", 29);
        set("str", 30);
        set("con", 30);
        set("combat_exp", 35000);
        set("max_kee", 500);
        set("force", 100);
        set("max_force", 100);
        set("force_factor", 5);
        set("shen_type", 1);
        set("attitude", "heroism");
        set_skill("unarmed", 50);
        set_skill("parry", 50);
        set_skill("dodge", 50);
        set_skill("force", 50);

        setup();
        carry_object("/d/obj/cloth/linen")->wear();

}


