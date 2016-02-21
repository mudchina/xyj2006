inherit F_VENDOR_SALE;

string heal_me(object me);

void create()
{
	reload("yangzhongshun");
        set_name("杨中顺", ({"yang zhongshun", "yang", "boss"}));
        set("title", "药铺掌柜");
        set("gender", "男性");
        set("age", 37);
        set("long",
"杨老板是长安城里祖传的名医。虽然年轻，却早已名声在外。\n");
        set("kee", 300); 
        set("max_kee", 300);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("env/wimpy", 50);

        set("inquiry", ([
                "治伤": (: heal_me :),
                "疗伤": (: heal_me :),
                "开药": (: heal_me :),
        ]) );

        set("vendor_goods", ([
		"taogan": "/d/obj/drug/fake-tao",
                "yao": "/d/obj/drug/jinchuang",
                "dan": "/d/obj/drug/hunyuandan",
        ]) );

        set_skill("literate", 70);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
//         add_money("gold", 1);
}


string heal_me(object ob)
{
        int ratio;
        object me;
        me = this_player();
        ratio = (int)me->query("eff_kee") * 100 /
(int)me->query("max_kee");
        if( ratio >= 100 )
                return "这位" + RANK_D->query_respect(me) +
"，您看起来气色很好啊，不像有受伤的样子。";
        if( ratio >= 95 )
                return
"哦....我看看....只是些皮肉小伤，您买包金创药回去敷敷就没事了。";

}



void init()
{
        object ob;

        ::init();
        add_action("do_vendor_list", "list");


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

