inherit NPC;

void create()
{
       set_name("小贩", ({"xiao fan", "fan"}));
       set("long", "一个看起来精明能干的小贩。\n");
       set("gender", "男性");
        set("combat_exp", 3500);
       set("age", 28);
       set("attitude", "peaceful");
       set("shen_type", 1);
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
       add_money("coin", 40+random(30));
}
void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("chat_msg", ({
            "小贩打了个喷嚏．\n",
            "小贩上上下下打量了你几眼。\n",
            (: random_move :)
        }) );
}

