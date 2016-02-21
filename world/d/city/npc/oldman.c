inherit NPC;

void create()
{
        set_name("白世卿", ({"bai shiqin", "bai", "shiqin"}));
        set("gender", "男性");
        set("age", 65);
        set("long",
"一个文文净净的老人，好象很有学问的样子。\n");
	set("attitude", "friendly");
        set("combat_exp", 1000);
	set("per", 25);
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        setup();

        carry_object("/d/gao/obj/changpao")->wear();
        add_money("coin", 100);

}
int accept_fight(object me)
{
        command("say 对不住，小老二老骨头不禁打呀！");
        return 0;
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
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                        say( "老白头笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
                                + "，是写信还是写状子呀？\n");
                        break;
        }
}

