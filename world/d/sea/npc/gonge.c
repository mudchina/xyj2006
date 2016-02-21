inherit NPC;

void create()
{
       set_name("宫娥", ({"gong e", "e"}));

	set("long","一个小丫环。\n");
       	set("gender", "女性");
	set("str", 20);
       	set("age", 16);
       	set("attitude", "peaceful");
        set("combat_exp", 400);
        setup();
        carry_object("/d/obj/cloth/pink_cloth")->wear();

}

