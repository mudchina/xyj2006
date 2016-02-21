// sgzl

inherit NPC;


string *names = ({
  "»ÆÝºÊÌ¶ù",
  "»Æð¿ÊÌ¶ù",
  "»Æº×ÊÌ¶ù",
});


void create()
{
        set_name(names[random(sizeof(names))], ({"shi er", "shier"}));
	set("gender", "Å®ÐÔ" );
	set("age", 16);
	set("long", "Ñ©É½ÃÅÏÂ¹«Ö÷ÊÌÎÀ¡£\n");
	set("class", "yaomo");
	set("combat_exp", 25000);
        set("daoxing", 30000);

	set("attitude", "peaceful");
//	create_family("´óÑ©É½", 4, "µÜ×Ó");
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("sword", 20);
	set_skill("bainiao-jian", 10);
	set_skill("xiaoyaoyou", 20);
	set_skill("force", 20);   
	set_skill("ningxie-force", 20);
	map_skill("force", "ningxie-force");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");


	set("per", 21);
	set("max_kee", 300);
	set("max_sen", 300);
	set("force", 300);
	set("max_force", 120);
	set("force_factor", 2);
	setup();

	set("nkgain", 20);

	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
	carry_object("/d/obj/weapon/sword/peijian")->wield();
	carry_object("/d/obj/weapon/throwing/yinzhen");

        setup();
}
