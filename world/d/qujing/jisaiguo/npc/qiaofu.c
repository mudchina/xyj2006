inherit NPC;
void create()
{
        set_name("樵夫", ({ "qiao fu" }) );
        set("gender", "男性" );
        set("age", 33);
        set("per", 30);
        set("long", "一个买柴的樵夫。\n");
        set("combat_exp", 6000);
        set("attitude", "friendly");
        set("env/wimpy", 60);
        set_skill("axe", 20);
        set("chat_chance",10);
        set("chat_msg",({
        (:random_move:)
        }));
        set("chat_chance_combat", 50 );
        set("chat_msg_combat", ({
                "樵夫叫道：杀人哪！杀人哪！\n",
                "樵夫叫道：有土匪哪！光天化日下打劫哪！\n",
                (: command, "surrender" :),
        }) );
        setup();
        add_money("coin", 50);
	carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/lingtai/obj/axe")->wield();
}

