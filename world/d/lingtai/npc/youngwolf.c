// cglaem.c
inherit NPC;

void create()
{
        set_name("小狼", ({ "wolf" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只浑身脏兮兮的小狼，一双眼睛正恶狠狠地瞪著你。\n");
        set("attitude", "friendly");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 100);

        set_temp("apply/armor", 5);

        setup();
}

