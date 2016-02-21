#include <ansi.h>

inherit NPC;

void create()
{
        set_name("侍官", ({"shi guan", "guan", "waiter"}));
        set("gender", "男性");
        set("long","皇宫中的小官，负责皇宫内部事务。\n");
        set("combat_exp", 1000+random(4000));
        set("attitude", "friendly");
        set("max_kee", 200);
        set("max_gin", 200);
	set("max_sen", 200);
        set("force", 100);
        set("max_force", 100);
        set("force_factor", 5);
        set_skill("unarmed", 15);
        set_skill("parry", 15);
        set_skill("dodge", 15);

        setup();
	carry_object("/d/obj/cloth/choupao")->wear();
}

