//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("广目天王", ({"guangmu tianwang", "tianwang"}));
       	set("gender", "男性");
       	set("age", 40);
        set("class", "fighter");
       	set("attitude", "friendly");
        set("per", 30);
        set("int", 30);
	set("str", 30);
       	set("max_kee", 2000);
       	set("max_gin", 2000);
       	set("max_sen", 2000);
       	set("force", 3000);
       	set("max_force", 3000);
       	set("force_factor", 100);
       	set("max_mana", 2000);
       	set("mana", 2000);
       	set("mana_factor", 80);
       	set("combat_exp", 2000000);
        set("daoxing", 1200000);

       	set_skill("dodge", 190);
       	set_skill("parry", 190);
        set_skill("staff", 190);
        set_skill("bawang-qiang", 190);
	set_skill("wusi-mace", 190);
	set_skill("kusang-bang", 190);
        set_skill("spells", 150);
        set_skill("buddhism", 150);
        set_skill("moshenbu", 190);

	set_skill("spear", 190);
	set_skill("mace", 190);
	set_skill("stick", 190);

        map_skill("spells", "buddhism");

        map_skill("parry", "bawang-qiang");
        map_skill("dodge", "moshenbu");
        map_skill("spear", "bawang-qiang");

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :)
        }) );

	setup();
        carry_object("/d/obj/weapon/spear/huaji")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

