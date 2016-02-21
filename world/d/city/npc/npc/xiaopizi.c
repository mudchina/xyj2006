// dipi.c

inherit NPC;

void create()
{
        set_name("小痞子", ({"xiao pizi", "pizi", "punk"}) );
        set("gender", "男性" );
        set("age", 15+random(10));
        set("long", "这是一个整日里游手好闲的小痞子。\n");

	set("combat_exp", 1500+random(300));
	set("str", 15);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","heroism");
        setup();
	carry_object("/d/obj/cloth/linen")->wear();
}

