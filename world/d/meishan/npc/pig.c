
inherit NPC;

void create()
{
        set_name("大胖狗熊熊", ({ "fat bear", "bear" }) );
        set("race", "野兽");
        set("gender", "雌性");
        set("age", 10);
        set("long", "一只肥胖的大胖狗熊熊，屁股上不知被谁用黑炭歪歪扭扭的写了“贺礼”两字。\n");
        set("attitude", "friendly");
	set("looking", "肥肥胖胖，小鼻小眼。");
        set("str", 20);
        set("con", 40);
	set("kee", 300);
	set("sen", 300);
        set("limbs", ({ "头部", "身体" }) );
        set("verbs", ({ "bite"}) );
	set("combat_exp", 2000);
        set_skill("dodge", 20);
        set_temp("apply/armor", 30);

        setup();
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",
               name() + "哼哼叽叽地叫了几声，扭着屁股跑了。\n", environment(),
                this_object() );
        destruct(this_object());
}

