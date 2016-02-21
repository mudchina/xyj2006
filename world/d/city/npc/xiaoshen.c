inherit NPC;

void create()
{
        set_name("萧升", ({ "xiao sheng", "xiao" }));
        set("title","振远镖局总镖头");
        set("gender", "男性");
        set("age", 35);
        set("long",
                "他就是振远镖局现在的当家－－萧升。
他不但武艺高强，而且为人豪侠仗义。 \n");

        set("combat_exp", 100000);
	set("str", 25);
        set_skill("sword", 70);
        set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
	set("max_kee", 700);
	set_skill("fonxansword", 50);
	set_skill("yanxing-steps", 50);
	map_skill("sword", "fonxansword");
	map_skill("parry", "fonxansword");
	map_skill("dodge", "yanxing-steps");
	set("force", 300);
	set("max_force", 300);
	set("force_factor", 10);

        setup();
        carry_object("/d/obj/cloth/magua")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();

}

