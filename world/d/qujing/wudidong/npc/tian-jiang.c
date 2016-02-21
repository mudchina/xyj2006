// tian-jiang.c
#include <ansi.h>
inherit NPC;
string *first_name = ({ "龙蚂蚱","龙小草","龙害虫","龙格格","龙雪豹","龙老蟹","龙未名","龙老余"});

varargs void drool(string msg, string who);

void create()
{
        string name, id;

        name = first_name[random(sizeof(first_name))];

        set_name(name, ({ "long shi", "long", "shi" }) );
        set("gender", "男性" );
        set("long", 
                "这是从海底各族里精选出来的武士\n"
                "他细腰乍臂，双肩抱拢，一看就知武艺高强。\n"
        );
	set("title", "龙士");
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

