inherit NPC;

void create()
{
       set_name("öë¶¼Ë¾", ({"qing dusi", "qing", "dusi"}));
        set("long","¶«º£Áú¹¬öë¶¼Ë¾¡£\n");
       set("gender", "ÄÐÐÔ");
       set("age", 40);
        set("per", 15);
        set("str", 25);
        set("con", 25);
        set("cps", 25);
       set("attitude", "heroism");
       set("shen_type", 1);
        set("max_kee", 700);
        set("max_sen", 600);
        set("force", 300);
        set("max_force", 300);
        set("force_factor", 15);
        set("mana", 200);
        set("max_mana", 200);
        set("mana_factor", 10);
        set("combat_exp", 200000);
  set("daoxing", 100000);

        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("spells", 100);
        set_skill("force", 100);
        setup();
        carry_object("/d/obj/cloth/magua")->wear();
}

ÿ