inherit ROOM;

void create ()
{
        set ("short", "静心堂");
        set ("long", @LONG

这里一片空灵，仿佛与世隔绝，你可以在这里思考，领悟你的武功，
恢复内力，以准备再次进入(enter)腥风血雨的门派战场。
LONG);

       	set("no_pkmeet", 1);
       	set("no_fight", 1);
        set("no_magic", 1);
        set("alternative_die",1);
        setup();
	
}


void init()
{
    add_action("do_enter", "enter");
    add_action("do_likai", "likai");
    add_action("do_get", "get");
       
}

int do_enter()
{
	object me;
	me = this_player();
	
	if(!me->query_temp("mpwar_chance"))
	    {write("你已经死了五次，不能再进入门派战场了，请离开(likai)这里。\n");
	     return 1;
	    }
	    
	if(me->is_busy())
	    {write("你正忙着呢。\n");
	     return 1;
	    }    
	        
	if(random(2)) me->move("/d/zhanchang/zhanchang1");
	        else  me->move("/d/zhanchang/zhanchang2"); 
	    
        me->set("eff_kee",me->query("max_kee"));
        me->set("eff_sen",me->query("max_sen"));
        me->set("kee",me->query("max_kee"));
        me->set("sen",me->query("max_sen"));
        message_vision("$N再次进入了门派战场。\n",me);
	return 1;
	    
}	

int do_likai()
{
	object me = this_player();
	if(me->query_temp("mpwar_chance"))
	  {write("你还有机会为自己门派争光，这么快就想离开了？\n");
	   return 1;
	  } 
	me->move("/d/city/kezhan");
	me->remove_all_killer();
	me->clear_condition();
	return 1;
}

int do_get()
{
	write("战场内不能用get。\n");
	   return 1;	  
}	   	   