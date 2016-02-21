inherit NPC;

void create()
{
       set_name("烧香老太太", ({"lao taitai", "woman"}));
       set("long", "一个远道来烧香还愿的老太太。\n");
	set("looking", "牙不关风，满头白发。");
       set("gender", "女性");
        set("combat_exp", 500);
       set("age", 78);
	set("kee", 200);
	set("sen", 200);
	set("gin", 200);
       set("attitude", "peaceful");
       set("shen_type", 1);
        setup();
        carry_object("/obj/cloth")->wear();
       add_money("coin", 40+random(30));
}
void init()
{
        object ob;

        ::init();
        set("chat_chance", 30);
        set("chat_msg", ({
            "老太太叹可口气。\n",
            "老太太说：请个愿居然要供奉！\n",
        }) );
}

