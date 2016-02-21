//Cracked by Roath

inherit F_VENDOR_SALE;
void create()
{
        reload("hehua");
        set_name("荷花", ({"he hua", "hua"}));
        set("title", "卖花的");
        set("gender", "女性");
        set("age", 19);
        set("long", "一个很漂亮的小姑娘，真和她的名字相配。\n");
        set("per",30);
        set("combat_exp", 20000);
	set("daoxing",20000);		
        set("vendor_goods", ([
               "lan hua": "/d/jz/obj/lan",
                "xue mei": "/d/jz/obj/mei",
                "mu dan": "/d/jz/obj/mudan",
                "purple":"/d/jz/obj/purple",
        ]) );
        setup();
   add_money("silver", 5);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
     call_out("greeting",1,ob);
        }
        add_action("do_vendor_list", "list");

}
void greeting(object ob)
{
    if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(1) ) {
                case 0:
                      say( name()+"笑道：买朵花给你的情人吧！\n");
                        break;
        }
}
