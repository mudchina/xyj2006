
inherit NPC;

void create()
{
        set_name("老母猪", ({ "old pig", "pig" }) );
        set("race", "野兽");
        set("gender", "雌性");
        set("age", 10);
        set("long", "一只肥胖的老母猪，屁股上不知被谁用黑炭歪歪扭扭的写了“阿花”两字。\n");
        set("attitude", "friendly");
	set("looking", "肥肥胖胖，看起来足有二百来斤。");
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
	this_object()->add("time", 1);
	if ( (int)this_object()->query("time") > 3 ) {
        message("vision",
               name() + "哼哼叽叽地叫了几声，扭着屁股跑了。\n", environment(),
                this_object() );
        destruct(this_object());
	}
	return;
}
