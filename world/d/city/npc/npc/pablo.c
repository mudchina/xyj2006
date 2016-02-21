inherit NPC;

void create()
{
	set_name("董朴升", ({"dong pusheng", "dong", "boss"}));
	set("title", "当铺掌柜");
	set("gender", "男性");
	set("age", 47);
	set("kee", 500); 
	set("max_kee", 500);
	set("sen", 200);
	set("max_sen", 200);	
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("rank_info/respect", "掌柜的");
	set("env/wimpy", 50);
	set("chat_chance", 10);
	set_skill("parry", 60);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);

	setup();
        carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("/d/city/obj/jiezhi")->wear();

	add_money("silver", 10);
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
