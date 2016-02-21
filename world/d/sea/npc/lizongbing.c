inherit NPC;

void create()
{
       set_name("Àð×Ü±ø", ({"li zongbing", "li", "zongbing"}));
	set("long","¶«º£Áú¹¬Àð×Ü±ø¡£\n");
       set("gender", "ÄÐÐÔ");
       set("age", 40);
	set("per", 15);
	set("str", 25);
	set("con", 25);
	set("cps", 25);
       set("attitude", "heroism");
       set("shen_type", 1);
	set("max_kee", 1000);
	set("max_sen", 800);
	set("force", 600);
	set("max_force", 600);
	set("force_factor", 30);
	set("mana", 400);
	set("max_mana", 400);
	set("mana_factor", 30);
        set("combat_exp", 500000);
  set("daoxing", 300000);

        set_skill("parry", 120);
        set_skill("dodge", 120);
	set_skill("unarmed", 120);
	set_skill("spells", 100);
	set_skill("force", 100);
	set_skill("hammer", 100);
        setup();
        carry_object("/d/obj/armor/tiejia")->wear();
	carry_object("/d/obj/weapon/hammer/tongchui")->wield();
}

ÿ