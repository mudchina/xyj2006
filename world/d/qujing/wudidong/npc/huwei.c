// tian-jiang.c
#include <ansi.h>
inherit NPC;
void create()
{
       

        set_name("»¤ÎÀ", ({ "long shi", "long", "shi" }) );
        set("gender", "ÄÐÐÔ" );
        set("long", 
                "ÕâÊÇ´Óº£µ×¸÷×åÀï¾«Ñ¡³öÀ´µÄÎäÊ¿\n"
                "ËûÏ¸ÑüÕ§±Û£¬Ë«¼ç±§Â££¬Ò»¿´¾ÍÖªÎäÒÕ¸ßÇ¿¡£\n"
        );
	set("title", "ÁúÊ¿");
        set("age", 25+random(10));
        set("str", 35);
        set("int", 25);
        set("per", 14);
        set("combat_exp",600000);
        set("force",500);
        set("max_force",500);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("spear",100);

        setup();
        carry_object("/d/obj/armor/yinjia")->wear();
        carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}

ÿ