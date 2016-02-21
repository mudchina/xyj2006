inherit NPC;

void create()
{
        set_name("卖糖人的", ({"seller"}));
        set("age", 42);
        set("gender", "男性");
        set("long",
"一个卖糖人的，正拿着糖人逗小孩。\n");
        set("attitude", "peaceful");

        set("combat_exp", 2000);
        set("shen_type", 1);

        set_skill("dodge", 20);
        set_skill("parry", 20);
	set("chat_chance", 5);
	set("chat_msg", ({
"卖糖人的喊道：香喷喷的糖人，快来买呀！\n",
"卖糖人的喊道：香喷喷的糖人，五文一个！\n",
(: random_move :)
}) );
        setup();
        carry_object("/d/obj/cloth/linen")->wear();
}


