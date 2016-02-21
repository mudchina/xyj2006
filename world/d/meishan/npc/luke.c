
inherit NPC;

void create()
{
        set_name("旅客", ({ "traveller"}));
            set("gender", "男性" );
        set("age", 15+random(50));
        set("long","一位风尘朴朴的旅客。");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }));

        set("combat_exp", 600+random(400));
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set_skill("unarmed", 10);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 100+random(20));
}

