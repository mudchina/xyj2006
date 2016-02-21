// worker.c

inherit NPC;

void create()
{
        set_name("小道士", ({"xiao dao", "dao"}));
        set("gender", "男性" );
        set("age", 13);
        set("long", "一个小道士，正跟着师父练武．\n");
        set("combat_exp", 30);
        set("attitude", "peaceful");
        setup();
}

void init()
{
       object me,ob;
    me=this_player();
	ob=this_object();

        ::init();
        
		if (me->query_temp("fangcun/qiansi_gongxi")==1) 
		{
                remove_call_out("greeting");
                call_out("greeting", 1, me);
                call_out("destroy", 60, ob);
        }
        
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;

				command ("say " + "龙．．．．．龙．．．．．师傅，快来看呀！" );

}

void destroy(object ob)
{
        destruct(ob);
        return;
}
