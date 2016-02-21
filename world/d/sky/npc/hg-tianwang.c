// huguo-tianwang.c
//created 4-8-97 pickle
inherit NPC;
 
void create()
{
        set_name("Ä§ÀñÊÙ", ({ "huguo tianwang", "huguo", "tianwang", "wang" }) );
        set("gender", "ÄÐÐÔ" );
        set("long","
»¤¹úÌìÍõÉíµ£×Å±£»¤ºó¹¬°²È«µÄÖØµ££¬·ÇÍ¬Ð¡¿É¡£ËûµÄÎä¹¦
ËÆºõÊô·ðÃÅÒ»ÅÉ£¬µ«³ýÂÖ»ØÕÈ·¨Ö®Íâ£¬»¤¹úÌìÍõ»¹ÓÐÁíÍâµÄ
É±ÊÖ¾øÕÐ£¬µ«Ã»ÓÐÈËÖªµÀÊÇÊ²Ã´¡£Ò²ÐíÕýÒòÎªÈç´Ë£¬Óñ»Ê²Å
·ÅÐÄÈÃËû¶Àµ£ÖØÈÎ¡£\n"
        );
	set("class", "xian");
	set("title", "»¤¹úÌìÍõ");
        set("age",43);
        set("str",30);
        set("int",37);
        set("max_kee",1200);
        set("kee",1100);
        set("max_sen",1100);
        set("sen",1100);
        set("combat_exp",1000000);
        set("force",2500);
        set("max_force",1500);
        set("mana",2500);
        set("max_mana",1500);
        set("force_factor", 70);
        set("mana_factor",80);

        set("eff_dx", 450000);
        set("nkgain", 450);

        set_skill("unarmed",140);
	set_skill("changquan", 150);
        set_skill("parry",140);
        set_skill("dodge",150);
        set_skill("staff",150);
	set_skill("spells", 140);
        set_skill("lunhui-zhang",150);
        set_skill("force",140);
	set_skill("moshenbu", 150);
	map_skill("dodge", "moshenbu");
        map_skill("staff","lunhui-zhang");
        map_skill("parry","lunhui-zhang");
	map_skill("unarmed", "changquan");
        set("inquiry", ([
                "name" : "ÔÚÏÂ¾ÍÊÇ»¤¹úÌìÍõ£¬·îÊ¥ÚÍ°ÑÊØ±±ÌìÃÅ¡£",
                "here" : "ÕâÀï¾ÍÊÇ±±ÌìÃÅ£¬ÀïÃæÊÇºó¹¬½ûµØ¡£",
        ]) );
        setup();
	carry_object("/d/obj/fabao/biyu-pipa");
        carry_object("/d/obj/weapon/staff/budd_staff")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}
ÿ