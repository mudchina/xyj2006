//xiaozuanfeng.c

int ask_name(); 

inherit NPC;
void create()
{

	set_name("¹÷É®", ({"gun seng", "seng"}));
	set("gender", "ÄÐÐÔ" );
	set("title", "ÉÙÁÖËÂ" );
	set("age", 28);
	set("long", "ÉÙÁÖËÂÊØËÂ¹÷É®¡£\n");
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 1700);
        set("max_force", 900);
        set("force_factor", 70);
        set("mana", 1700);
        set("max_mana", 900);
        set("mana_factor", 20);
        set("combat_exp", 1000000);
        set("daoxing", 500000);

	set_skill("jienan-zhi", 130);
	set_skill("lotusforce", 130);
	set_skill("buddhism", 100);
	set_skill("spells", 100);
	set_skill("unarmed", 150);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("stick", 130);
	set_skill("qianjun-bang", 150);
        map_skill("unarmed", "jienan-zhi");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("force", "lotusforce");
        map_skill("spells", "buddhism");

	set("max_kee", 1300);
	set("max_sen", 1300);
	setup();
	carry_object("/d/nanhai/obj/sengpao.c")->wear();
	carry_object("/d/ourhome/obj/qimeigun.c")->wield();


}


