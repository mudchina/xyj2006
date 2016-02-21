//Cracked by Roath
inherit NPC;

void create()
{
       	set_name("É¢Ö¬´ó½«", ({"sanzhi dajiang", "dajiang"}));
       	set("gender", "ÄĞĞÔ");
       	set("age", 30);
        set("class", "fighter");
       	set("attitude", "friendly");
        set("per", 30);
        set("int", 30);
	set("str", 30);
       	set("max_kee", 3000);
       	set("max_gin", 3000);
       	set("max_sen", 3000);
       	set("force", 3000);
       	set("max_force", 3000);
       	set("force_factor", 100);
       	set("max_mana", 600);
       	set("mana", 600);
       	set("mana_factor", 20);
       	set("combat_exp", 1500000);
        set("daoxing", 400000);

       	set_skill("dodge", 180);
       	set_skill("parry", 180);
        set_skill("puti-zhi", 180);
        set_skill("spells", 40);
        set_skill("buddhism", 40);
        set_skill("jindouyun", 180);
	set_skill("unarmed", 180);
	set_skill("stick", 180);
	set_skill("qianjun-bang", 180);
	map_skill("parry", "qianjun-bang");
	map_skill("stick", "qianjun-bang");
        map_skill("spells", "buddhism");
        map_skill("dodge", "jindouyun");
        map_skill("unarmed", "puti-zhi");


	setup();
	carry_object("/d/sea/obj/dragonstick")->wield();
	carry_object("/d/obj/armor/jinjia")->wear();
}

