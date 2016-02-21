 
inherit NPC;
 
void create()
{
 
        set_name("Ò©²æ½«", ({ "yaocha jiang", "jiang", "yaocha" }) );
        set("gender", "ÄÐÐÔ" );
        set("long","ÍÐËþÀîÌìÍõÕÊÏÂ´ó½«£¬°òÀ«ÑüÔ²£¬Á¦´óÎÞÇî¡£\n");
        set("age",40);
        set("str", 30);
        set("int", 20);
	set("con", 30);
	set("spi", 20);
        set("per", 15);
	set("class", "xian");
	set("attitude", "heroism");
        set("combat_exp", 850000);
  set("daoxing", 500000);

	set("max_kee", 1000);
	set("max_sen", 1000);
        set("force",800);
        set("max_force",800);
	set("force_factor", 40);
	set("mana", 800);
	set("max_mana", 800);
	set("mana_factor", 40);
        set_skill("unarmed",159);
        set_skill("dodge",159);
        set_skill("parry",159);
	set_skill("hammer", 159);
	set_skill("force", 159);
	set_skill("spells", 159);
 
        setup();
        carry_object("/d/obj/armor/tongjia")->wear();
	carry_object("/d/obj/weapon/hammer/tongchui")->wield();
}
 

ÿ