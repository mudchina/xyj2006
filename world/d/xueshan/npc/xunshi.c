// xunshi.c

inherit NPC;
void create()
{
	set_name("±ù¹ÈÑ²Ê¹", ({"xunshi", "shi"}));
	set("gender", "ÄÐÐÔ" );
	set("age", 33);
	set("long", "Ñ©É½ÃÅÏÂÓÐºÜ¶àÑ²Ê¹¡£ÒòÎªÍâÈËºÜÉÙÄÜµ½ÕâÀï£¬\nÔÚ¹ÈÄÚµÄÑ²Ê¹´ó¶àÎä¹¦²»¸ß£¬ÖÁÓÚ´óÑ©É½µÄ·¨ÊõÔò»ù±¾ÉÏ²»»á¡£\nÕâÎ»Ñ²Ê¹ÉíÅû°×ÅÛ£¬Ñü¿çÍäµ¶¡£°×ÅÛµ±ÐØÐå×ÅÒ»Ö»·ÉÑïÓûÍÑµÄ´óÅôÄñ¡£\nÍäµ¶¿´ÆðÀ´¾§Ó¨Í¸Ã÷£¬ºÃÏñÊÇÒÔº®±ùÖÆ³É¡£\n");
	set("class", "yaomo");
	set("combat_exp", 25000);
  set("daoxing", 20000);

	set("attitude", "peaceful");
	create_family("´óÑ©É½", 4, "µÜ×Ó");
	set_skill("unarmed", 30);
	set_skill("yingzhaogong", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("blade", 30);
	set_skill("bingpo-blade", 30);
	set_skill("xiaoyaoyou", 30);
	set_skill("force", 30);   
	set_skill("ningxie-force", 30);
	map_skill("force", "ningxie-force");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("unarmed", "yingzhaogong");

	set("per", 19);
	set("max_kee", 300);
	set("max_sen", 300);
	set("force", 300);
	set("max_force", 250);
	set("force_factor", 5);

	set("eff_dx", -8000);
	set("nkgain", 60);

	setup();
	carry_object("/d/obj/cloth/xueshan-pao")->wear();
	carry_object("/d/obj/weapon/blade/iceblade")->wield();
}

ÿ