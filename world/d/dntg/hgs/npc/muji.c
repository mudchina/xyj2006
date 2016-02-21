inherit NPC;

void create()
{
        set_name("老母鸡", ({ "old hen", "hen" }) );
        set("race", "野兽");
	set("gender", "雌性");
        set("age", 5);
	set("long", "一只肥胖的老母鸡。\n");
        set("attitude", "friendly");
	set("str", 5);
	set("con", 20);
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite"}) );

	set_skill("dodge", 20);
        set_temp("apply/armor", 1);

        setup();
}

