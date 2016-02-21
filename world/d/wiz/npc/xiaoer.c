inherit F_VENDOR_SALE;

void create()
{
	reload("jin");
       	set_name("金不换", ({"jin buhuan","jin","buhuan"}));
       	set("gender", "男性");
        set("combat_exp", 10000);
       	set("age", 26);
//	set("title", "珠宝行老板");
//	set("shop_title","珠宝行");
	set("shop_id",({"laoban","jin","buhuan"}));
       	set("per", 14);
       	set("attitude", "friendly");
       	set("shen_type", 1);
	set_skill("dodge", 30);
	set_skill("parry", 30);
       	set_skill("unarmed", 30);
        set("vendor_goods", ([
                "jiezhi": "/d/qujing/biqiu/obj/ring",
                "wanlian": "/d/qujing/biqiu/obj/wrists",
                "xiangquan": "/d/qujing/biqiu/obj/neck",
		"yupei": "/d/obj/misc/pai",
        ]) );

      	setup();
       	carry_object("/d/obj/cloth/choupao")->wear();
       	add_money("silver", 3);
}
void init()
{
	        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( name()+"笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
                                + "，进来看看，不怕货比货，就怕你不识货呦。\n");
                        break;
        }
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}

