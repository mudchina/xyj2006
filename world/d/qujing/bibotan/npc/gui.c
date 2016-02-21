inherit NPC;

void create()
{
        set_name("Î÷²¨¶ù¹Å", ({"xiboer gu", "gu"}));
        set("long", "ËûÊÇÂÒÊ¯É½±Ì²¨Ì¶µÄÀÏ¹ê¾«¡£\n");
        set("age", 30);
	set("title", "µîÇ°×óÊ¹");
        set("attitude", "heroism");
	set("class", "yaomo");
        set("gender", "ÄÐÐÔ");
        set("str", 20);
        set("int", 20);
        set("per", 10);
        set("con", 30);
        set("max_kee",500);
        set("max_sen", 500);
        set("combat_exp", 50000);
  set("daoxing", 10000);

        set("eff_dx", -20000);
        set("nkgain", 250);

        set("force", 200);
        set("max_force", 200);
        set("mana", 200);
        set("max_mana", 200);
        set("force_factor", 10);
        set("mana_factor", 10);
        set_skill("unarmed", 40);
        set_skill("force", 40);
        set_skill("spells", 40);
        set_skill("dodge", 40);
	set_skill("fork", 40);
	set_skill("yueya-chan", 40);
	map_skill("fork", "yueya-chan");
	map_skill("parry", "yueya-chan");
        setup();
        carry_object("/d/obj/armor/tenjia")->wear();
	carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

ÿ