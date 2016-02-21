
inherit NPC;
void create()
{
        set_name("二妞", ({"er niu", "niu"}));
        set("gender", "女性" );
        set("age", 9);
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("per", 18);
        set("max_kee", 200);
        set("max_sen", 200);
        set("force", 200);  
	set("inquiry", 
([ "大花": "大花是我养的老母猪。\n", 
]) );

        setup();
        carry_object("/d/obj/cloth/shoes")->wear();
}
void init()
{       
        object ob=this_player();

        ::init();

                        remove_call_out("greeting");
                        call_out("greeting", 3, ob);
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(3) ) {
                case 0:
		message_vision("$N哭道：爹爹要卖了大花还债。\n", this_object());
		command("cry girl");
                break;
		case 1:
		message_vision("$N哭道：刘财主又来要债了！\n", this_object());
		command("slogan");
		break;
		case 2:
		message_vision("$N哭道：爹爹说还差五十两银子。\n", this_object());
		command("cry " + ob->query("id"));
		break;
        }
}

