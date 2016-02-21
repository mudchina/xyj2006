inherit NPC;

void create()
{
        set_name("老牛", ({"niu"}));
        set("race", "野兽");
        set("age", 15);
        set("long", "一头老牛。\n");
        set("attitude", "friendly");

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 100);

	set("ride/msg", "骑");
  	set("ride/dodge", 10);
        set_temp("apply/armor", 20);

        setup();
}

