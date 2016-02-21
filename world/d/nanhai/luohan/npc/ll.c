//Cracked by Roath
inherit NPC;

void create()
{
	set_name("½µÁúÂÞºº", ({ "luo han"}));
	set("long", @LONG
ÄÏº£¹ÛÒô×ùÏÂÊ®°ËÂÞºº¡£
LONG);
	set("gender", "ÄÐÐÔ");
	set("age", 25);
	set("attitude", "peaceful");
	set("rank_info/self", "Æ¶É®");
	set("class", "bonze");
	set("max_kee", 2000);
	set("max_gin", 2000);
	set("max_sen", 2000);

	set("force", 3000);
	set("max_force", 1800);
	set("force_factor", 70);
	set("max_mana", 1800);
	set("mana", 3000);
	set("mana_factor", 70);

	set("combat_exp", 2000000);
	set("daoxing", 2000000);


        set("eff_dx", 720000);
        set("nkgain", 500);

	set_skill("spells", 170);
	set_skill("buddhism", 170);
	set_skill("unarmed", 170);
	set_skill("jienan-zhi", 170);
	set_skill("dodge", 170);
	set_skill("lotusmove", 170);
	set_skill("parry", 170);
	set_skill("force", 170);
	set_skill("lotusforce", 170);
	set_skill("staff", 170);
	set_skill("lunhui-zhang", 170);

	map_skill("spells", "buddhism");
	map_skill("unarmed", "jienan-zhi");
	map_skill("dodge", "lotusmove");
	map_skill("force", "lotusforce");
	map_skill("parry", "lunhui-zhang");
	map_skill("staff", "lunhui-zhang");

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: cast_spell, "bighammer" :),
		(: cast_spell, "jingang" :)
	}) );

	setup();
	carry_object("/d/nanhai/obj/sengpao")->wear();
	carry_object("/d/nanhai/obj/budd_staff")->wield();
}

