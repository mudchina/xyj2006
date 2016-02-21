// tian-jiang.c
#include <ansi.h>
inherit NPC;
string *first_name = ({ "ÕÔÀÏ´ó","Ç®ÓÐ¸£","Ëï´óÍ¨","ÀîÔª±ë","ÖÜÌìºÆ","Îâ¹ã¶È","Ö£Èçº£","ÍõËÄº£"});

varargs void drool(string msg, string who);

void create()
{
        string name, id;

        name = first_name[random(sizeof(first_name))];

        set_name(name, ({ "tian jiang", "tian", "jiang" }) );
        set("gender", "ÄÐÐÔ" );
        set("long", 
                "ÄÜÔÚÕâÀï»ìÉÏ¸öÌì½«µÄÎ»×Ó¿Ï¶¨»áÓÐÁ½ÏÂ×Ó¡£\n"
                "ËûÏ¸ÑüÕ§±Û£¬Ë«¼ç±§Â££¬Ò»¿´¾ÍÖªÎäÒÕ¸ßÇ¿¡£\n"
        );
	set("title", "Ìì½«");
        set("age", 25+random(10));
        set("str", 30);
        set("int", 25);
        set("combat_exp",300000+random(200000));
        set("force",500);
        set("max_force",500);
	set("force_factor", 20);
	set("max_kee", 800);
	set("max_sen", 600);
	set("max_mana", 400);
	set("mana", 400);
	set("mana_factor", 20);
        set_skill("unarmed",89);
        set_skill("dodge",89);
        set_skill("parry",89);
        set_skill("spear",89);
	set_skill("force",80);
        setup();
        carry_object("/d/obj/armor/yinjia")->wear();
        carry_object("/d/obj/weapon/spear/tieqiang")->wield();
}

ÿ