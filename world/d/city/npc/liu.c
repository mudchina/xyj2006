inherit F_VENDOR_SALE;
void create()
{
    reload("liuyuntian");
        set_name("柳云天", ({"liu yuntian", "liu"}));
        set("age", 22);
        set("gender", "男性");
        set("long",
"柳记布庄的少东家，也是年少有为，一副得意洋洋地样子。\n");
	set("title", "柳记布庄东家");
        set("attitude", "friendly");
        set("combat_exp", 20000);
        set("shen_type", 1);
	set("max_force", 400);
	set("force", 400);
	set("force_factor", 10);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set("vendor_goods", ([
                "boots": "/d/obj/cloth/huazheboots",
		"jin": "/d/obj/cloth/wulingjin",
                "shoes": "/d/obj/cloth/bullboots", 
                "choupao": "/d/obj/cloth/choupao", 
        ]) );
        setup();
	add_money("silver", random(5));
	carry_object("/d/obj/cloth/choupao")->wear();
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
        switch( random(1) ) {
                case 0:
                        say(name()+ "笑眯眯地迎上来：这位" + RANK_D->query_respect(ob) + "，要买些什么东西？\n");
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

