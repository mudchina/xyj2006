inherit NPC;

void create()
{
        set_name("野老鼠", ({ "rat" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只肥肥的大老鼠。瞪着一双小眼睛，滴溜溜的乱转，不知在想什么\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set_skill("dodge", 50);
	set("combat_exp", 1000);

        setup();
}

