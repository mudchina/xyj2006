inherit NPC;
#include <ansi.h>

void reset_balance(object me);

void create()
{
        set_name("铁算盘", ({"tie suanpan", "tie", "zhanggui"}));
        set("title", "钱庄掌柜");
        set("gender", "男性");
        set("age", 54);
        set("kee", 800); 
        set("max_kee", 800);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 10);
/*        set("chat_msg", ({
        "铁算盘嘿嘿嘿地笑了几声：我这把算盘几十年来可从来没错过。\n",

"铁算盘骄傲的说道：提起本钱庄相老板，可以说是无人不晓。连当今皇上都跟他很熟。\n"
        }));
*/
        set_skill("unarmed", 60);
	set_skill("parry", 60);
        set_skill("dodge", 60);

        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}

void init()
{
    call_out("reset_balance", 1, this_player());
    ::init();
}
void reset_balance(object me)
{
    int myexp;
    int allowed, removed_gold;
    string myid;
    string NPCNAME=this_object()->name();

    if(!me) return;

    myexp=me->query("combat_exp")/1000;
    myid=me->query("id");

    if(myexp<1) myexp=1;
    if(myexp>100) myexp=100;
    allowed=myexp*1000000;//each year can have 100 gold, range 100-10000. 
    if (me->query("balance") > allowed)
    {
	me->set("balance_old", me->query("balance"));
	me->set("balance", allowed);
	removed_gold = (me->query("balance_old") - me->query("balance"))/10000;
	log_file("MONEY_RESET", ctime( time() )+"：魏大人收缴了"+me->query("name")+"("+me->query("id")+")"+removed_gold+"两黄金。\n");
	tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+RANK_D->query_respect(me)+
		"，这、这真不知怎么说是好．．．\n"NOR);
	tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
		"昨日魏大人派人前来察案，发觉你老的黄金来路．．．\n"NOR);
	tell_object(me, GRN+NPCNAME+"在你的耳边悄声说道："+
		"若不是在下帮你老辩解，你老的钱就全都充公了．．．\n"NOR);
    }
    return;
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

