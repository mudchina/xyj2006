// jiading.c

inherit NPC;

void create()
{
       set_name("土匪", ({"bandit"}));

set("long","一个体型魁悟，看起来孔武有力的大个子．\n正狠巴巴的瞪着你．\n");
       set("gender", "男性");
       set("age", 25+random(15));
       set("attitude", "aggressive");
       set("shen_type", 1);
	set("combat_exp", 5000+random(5000));
        set_skill("blade", 25+random(15));
	set_skill("parry", 25+random(15));
	set_skill("dodge", 25+random(15));
	setup();
        add_money("coin", 50);
        carry_object("/d/gao/obj/blade")->wield();

}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
		set_leader(ob);
        }
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
                        command("follow " + ob->query("id"));
                        break;
        }

}

