// jiading.c
#include <ansi.h>
inherit NPC;

void create()
{
       set_name("小沙弥", ({"shami"}));

set("long","一个看院的小和尚，到也长得眉清目秀的。\n");
       set("gender", "男性");
       set("age", 10+random(15));
       set("attitude", "peaceful");
       set("shen_type", 1);
	set("combat_exp", 1000);
        set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);
	set("max_kee", 250);

	setup();
        add_money("silver", 5);

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(1) ) {

                case 0:
                        say(CYN  "小沙弥一和掌说道：“欢迎来到我华严寺。”\n" NOR);
                        break;
        }
}

