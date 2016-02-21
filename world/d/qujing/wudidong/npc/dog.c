// wilddog.c
inherit NPC; 
void create()
{
        set_name("野狗", ({ "dog", "gou"}));
        set("race", "野兽");
        set("age", 4);
        set("long",
                "一条脏兮兮的野狗，看到你就跑来看看有什么吃的给它。\n");
        set("attitude", "friendly");
	set("str", 26);
	set("cor", 30);
	set("chat_chance", 40);
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 5);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 5);

	set("chat_msg", ({
                (: random_move :)
        }));
        setup();
}
