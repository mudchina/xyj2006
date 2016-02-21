//zhudachang.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("朱老板", ({"boss dachang","dachang","boss"}));
        set("title","长安巨贾");
        set("gender", "男性" );
        set("age", 45);
        set("per",18);
        set("class","taoist");
        set("long", "朱老板原名猪大肠，当年是长安城两大流氓“左捣乱，右猪肠”
之一。有次被捣乱痛扁后卧床不起，百无聊赖之际读史解闷。读
到刘邦周处等人的故事时，悚然有悟。从此奋发读书，潜心习武，
文不成武不就后，毅然下海从商，终于成就了今天的局面。发迹
改名朱大常，身穿绸袍，俨然衣冠中人。\n");
        set("combat_exp", 25000);
        set("daoxing",25000);
        set("attitude", "peaceful");
        set_skill("unarmed",100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("literate",100);
        set_skill("spells", 100);
        set("max_kee", 700);
        set("max_gin", 700);
        set("max_sen", 700);
        set("max_force",800);
        set("force",800);
        set("max_mana",800);
        set("mana",800);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}