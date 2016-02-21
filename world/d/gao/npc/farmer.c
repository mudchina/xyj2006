inherit NPC;

void create()
{
        set_name("农夫", ({ "farmer" }) );
        set("gender", "男性" );
        set("age", 25+random(20));
        set("long", "你看到一位面色黝黑的农夫。\n");
        set("combat_exp", 150+random(800));
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "农夫叫道：杀人哪！杀人哪！\n",
                "农夫叫道：有土匪哪！光天化日下打劫哪！\n",
                (: command, "surrender" :),
        }) );
        setup();
        add_money("coin", 20);
}

