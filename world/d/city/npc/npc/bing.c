inherit NPC;

#include <greeting.h>

void create()
{
        set_name("小兵", ({ "xiao bing", "bing" }));
        set("age", 18+random(10));
        set("gender", "男性");
        set("long","这些兵士都是秦叔宝，程咬金等从部下中挑出来的精锐。\n");
        set("attitude", "peaceful");
	set("str", 20);
        set("combat_exp", 20000);
	set("max_kee", 400);
	set("max_sen", 400);
	set("max_force", 200);
	set("force", 200);
	set("force_factor", 10);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("blade", 40);
        set_skill("force", 40);

        setup();
        carry_object("/d/obj/weapon/blade/blade")->wield();
        carry_object("/d/obj/cloth/bingfu")->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
       	greeting1(this_player());
}

int accept_fight(object me)
{
        message_vision("小兵对$N喝道：大胆刁民，活得不耐烦了？\n", me);
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

