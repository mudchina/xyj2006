// cglaem.c
inherit NPC;

void create()
{
        set_name("老狼", ({ "wolf" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只浑身脏兮兮的老狼，一双眼睛正恶狠狠地瞪著你。\n");
        set("attitude", "aggressive");
	set("bellicosity", 20000);
        set("str", 20);
        set("cor", 30);
	set("max_kee", 300);
	set("max_sen", 200);
        set("limbs", ({ "头部", "身体", "前脚", "後脚"}) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 10000);

        set_temp("apply/damage", 5);
        set_temp("apply/armor", 10);

        setup();
}

