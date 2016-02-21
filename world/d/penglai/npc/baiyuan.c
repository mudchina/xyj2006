//Cracked by Roath
inherit NPC;

void create()
{
        set_name("°×Ô³", ({ "bai yuan", "yuan" }) );
        set("race", "Ò°ÊÞ");
        set("age", 80);
        set("long", "Ò»Ö»»ëÉí³¤×Å´çÐí³¤°×Ã«µÄÀÏÔ³¡£\n");

        set("str", 30);
        set("dex", 30);
	set("int", 30);
	set("con", 30);
	set("cor", 50);
	set("spi", 50);

        set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°½Å", "ºó½Å", "Î²°Í" }) );
        set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 999000);
  set("daoxing", 1200000);

	set_skill("unarmed", 150);
	set_skill("changquan", 150);
	set_skill("sword", 170);
	set_skill("xiaofeng-sword", 170);
	set_skill("parry", 170);
	set_skill("dodge", 150);
	set_skill("moshenbu", 150);
	set_skill("force", 150);
	set_skill("spells", 150);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "xiaofeng-sword");
	map_skill("sword", "xiaofeng-sword");
	map_skill("unarmed", "changquan");

	set("max_kee", 1600);
	set("max_sen", 1600);
	set("mana", 2000);
	set("max_mana", 1000);
	set("mana_factor", 60);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 120);

        set_temp("apply/attack", 20);
        set_temp("apply/armor", 50);

        setup();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

ÿ