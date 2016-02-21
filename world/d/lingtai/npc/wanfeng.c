// worker.c

inherit NPC;

void create()
{
        set_name("晚风", ({"wan feng"}));
        set("title", "小厨子");
        set("gender", "男性" );
        set("age", 16);
        set("long", "一个吃的胖胖的小道士，正在烧火．\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
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
		add_action("do_yao", "yao");
}

int do_yao(string arg)
{
        object m,mm;
        message_vision("$N向晚风问道：道兄，开饭了吗？\n", this_player());

        if((int)this_player()->query("food") >=
(int)this_player()->max_food_capacity()*90/100 )
        return notify_fail("晚风笑道：没那，等开饭时再来吧！\n");

        if((present("bao zi", this_player())))
        return notify_fail("晚风笑道：不要拿着手里的，还看着锅里的！￥？\n");
	
	if ( present("bao zi", environment()) )
                return notify_fail("晚风笑道：那不是有一块呢嘛，吃完再说！\n");

        m=new("/d/obj/food/baozi");
        mm=new("/d/obj/food/baozi");


        m->move(this_player());
        mm->move(this_player());

        message_vision("晚风对$N笑道：饿了吧，慢点吃。\n", this_player());
return 1;
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;

				command ("say " + "师叔,这龙是你．．．．你变的？" );

}

void destroy(object ob)
{
        destruct(ob);
        return;
}
