//Cracked by Roath
inherit NPC;

void create()
{
        set_name("Ä§Àñºì", ({ "guangmu tianwang","guangmu", "tianwang" }) );
        set("gender", "ÄÐÐÔ" );
	set("title", "¹ãÄ¿ÌìÍõ");
        set("long","¹ãÄ¿ÌìÍõÏ²¶¯²»Ï²¾²£¬²»Ô¸ÔÚÌìÉÏÊØÃÅ¡£
ÓñµÛ±ãÅÉËûÑ²ÓÎËÄ·½£¬±£ÎÀÖÚÏÉ¼Ò°²È«¡£\n");
        set("age",40);
        set("str",30);
        set("int",25);
	set("class", "xian");
        set("max_kee",1500);
        set("kee",1500);
        set("max_sen",1000);
        set("sen",1000);
        set("combat_exp",900000);

        set("force",3000);
        set("max_force",1500);
        set("mana",3000);
        set("max_mana",1500);

        set("force_factor", 100);
        set("mana_factor",70);

        set_skill("unarmed",150);
        set_skill("parry",150);
        set_skill("dodge",150);
        set_skill("spear",150);
        set_skill("bawang-qiang", 150);
        set_skill("force",150);
	set_skill("spells", 150);
	set_skill("moshenbu", 150);

	map_skill("dodge", "moshenbu");
        map_skill("spear","bawang-qiang");
        map_skill("parry","bawang-qiang");
        setup();
        carry_object("/d/obj/weapon/spear/jinqiang")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}
ÿ