//Cracked by Roath

inherit NPC;

void create()
{
        set_name("卖鱼竿的", ({"seller"}));
        set("gender", "男性");
        set("age", 59);
        set("long", "这个卖鱼竿的已经在这呆了三十多年了。\n");
        set("per",30);
        set("combat_exp", 20000);
	set("daoxing",20000);	
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
}
void greeting(object ob)
{
    object map;
        
     if( !ob || !visible(ob) || environment(ob) != environment() ) return;
     if( !map=present("yu gan", ob))    
     say( name()+"喊道：客官来钓鱼啊，五两银子就可以买到鱼竿。\n");
}

int accept_object(object who, object ob)
{
       object yugan;

       if (ob->query("money_id") && ob->value() >= 500)
       {
        tell_object(who,"这是鱼竿，您拿好了。\n");
        yugan = new("/d/jz/obj/yugan");
        yugan->move(this_player());
        return 1;
        }
    else 
        return 0;
} 
