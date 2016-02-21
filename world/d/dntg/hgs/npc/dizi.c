inherit NPC;

void create()
{
        int skill;

set_name("武馆弟子", ({"wuguan dizi", "dizi", "trainee" }) );
        set("gender", "男性" );
        set("age", 18+random(10));
        set("long", "一位身材高大的汉子，正在辛苦地操练着。\n");

        skill=random(30)+10;
        set("combat_exp", 600+skill*10);


        set_skill("dodge", 10);
        set_skill("unarmed", 10);

        setup();
	add_money("coin", 100+random(200));
        carry_object("/d/obj/cloth/linen")->wear();
}

