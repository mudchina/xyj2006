// kid.c

inherit NPC;

void create()
{
	set_name("男孩",({ "boy" }) );
        set("gender", "男性" );
        set("age", 13);
	set("long", "这是个典型的城里少年，年纪不大，长得很机灵。\n");
	set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
        set("combat_exp", 100);
	set("attitude", "peaceful");

        setup();

        carry_object("/d/obj/cloth/linen")->wear();
	add_money("coin", 40);
}

