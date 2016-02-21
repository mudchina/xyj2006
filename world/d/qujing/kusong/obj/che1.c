//Cracked by Roath

inherit ITEM;


void create()
{
        set_name("金车", ({ "jin che"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value",100);
                set("unit", "辆");
                set("no_get",1);
                set("long","一辆很不寻常的车。\n");
        }
}

void init()
{
        add_action("do_break","break");
}

int do_break(string arg)
{
        object ob = this_player();
        object where = environment();
        object hong=find_living("honghai er");

        if( ob->query("force") < 500 )
                return notify_fail("你的内力不够。\n");

        if( ! arg || arg != "jin che" )
                return notify_fail("你要砸什么？\n");

        if( present("honghai er",where) )
                {
               tell_object(ob,"红孩儿对你大吼一声：给我住手。\n"); 
               hong->kill_ob(ob);
               return 1;
                }

        message_vision("只见$N对着金车狠命的砸去，没多大时间，金车就被砸个稀巴烂。\n",ob);
        ob->set_temp("che1_broken",1);
        call_out("honghaier_appearing",1,ob);
        ob->set("force",10);   
        destruct(this_object());
        return 1;
}
void honghaier_appearing (object who)
{
	object honghaier = new ("/d/qujing/kusong/npc/honghaier");   
	honghaier->announce_success (who);
	
}   