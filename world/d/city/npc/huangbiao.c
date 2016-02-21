// dog.c

inherit NPC;

void create()
{
        set_name("黄骠马", ({"huangbiao ma", "ma"}));
        set("race", "野兽");
        set("age", 20);
        set("long", "一只长得不很精神，一身黄毛的大马．\n");

	set("combat_exp", 10000);
        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite"}));

        set("chat_chance", 1);
        set("chat_msg", ({
                "黄骠马哼哼的叫了几声．\n"
}));

        set_temp("apply/attack", 10);
        set_temp("apply/armor", 20);

        setup();
}


