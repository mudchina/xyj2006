//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/baiyi.c
 
inherit NPC;
#include <ansi.h>

void create()
{
        set_name("白衣秀士", ({"baiyi xiushi","xiu shi"}));
        set("long", "一位身材很苗条的男子。\n");

        set("gender", "男性");
        set("attitude", "peaceful");

        set("age", 80);
        set("combat_exp", 50000);
        set("daoxing",30000);
        set("shen_type", 1);
        set("per", 10);
        set("max_kee", 380);
        set("max_gin", 300);
        set("force", 250);
        set("force_factor", 5);
        set_skill("force", 20+random(20));
        set_skill("unarmed", 20+random(20));
        set_skill("dodge", 20+random(20));
        set_skill("parry", 20+random(40));

        setup();
        carry_object("/d/obj/cloth/sengyi")->wear();

        setup();
}
void kill_ob(object ob)
{
        
    object where=environment(ob);
    object bear = present("hei xiong",where);
    object lingxu=present("lingxu zi",where);

        if ( bear )
        bear->kill_ob(ob);
        if ( lingxu )
        lingxu->kill_ob(ob);
        ::kill_ob(ob);
        return;
}        


void die()
{

        message_vision(HIY"白衣秀士翻了个身，死了。\n",this_object());
        message_vision("只见一条白花蛇落在地上。\n"NOR,this_object());
        this_object()->set_name("白花蛇",({"baihua she","snake"}));
        ::die();
}
    
