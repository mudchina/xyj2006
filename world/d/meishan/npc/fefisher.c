
inherit NPC;

void create()
{
        set_name("渔姑", ({ "yu gu", "gu"}));
            set("gender", "女性" );
        set("age", 15+random(10));
        set("long","一位漂亮的渔家姑娘。");
        set("chat_chance", 20);
        set("chat_msg", ({
                (: random_move :)
        }));

        set("combat_exp", 2600+random(400));
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set_skill("unarmed", 10);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 30+random(20));
}

