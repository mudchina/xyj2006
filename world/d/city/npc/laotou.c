inherit NPC;

void create()
{
        set_name("老头", ({"lao tou", "tou"}));
        set("gender", "男性");
        set("age", 65);
	set("con", 30);
	set("spi", 30);
        set("long",
"一个老头，手里还拿着一个油瓶子。\n");

        set("combat_exp", 200);

        setup();

        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/city/obj/youping")->wield();
        add_money("coin", 30);

}

