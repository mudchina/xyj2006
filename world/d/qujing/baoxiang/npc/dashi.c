#include <ansi.h>

inherit NPC;

void create()
{
        set_name("大使", ({ "da shi", "shi" }) );
        set("title","阁门");
        set("gender", "男性");
        set("age", 65);
        set("combat_exp", 300000+random(20000));
        set("attitude", "heroism");

        set("str", 30);
        set("per", 30);
        set("max_kee", 600);
        set("max_gin", 600);
        set("force", 600);
        set("max_force", 600);
        set("force_factor", random(20)+25);
        set_skill("unarmed", 80);
        set_skill("parry", 80);
        set_skill("dodge", 80);

        setup();

        carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
}

