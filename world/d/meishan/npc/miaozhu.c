
inherit NPC;
void create()
{
       set_name("庙祝", ({"miao zhu", "keeper"}));
	set("long", "二郎庙里的庙祝。\n");
       set("gender", "男性");
       set("age", 46);
       set("attitude", "peaceful");
       set("shen_type", 1);
        set("combat_exp", 5000);
        set_skill("unarmed", 35);
        set_skill("dodge", 30);
        set_skill("parry", 15);
set("inquiry", ([
"供奉": "时下需要一头猪。\n",
"here": "二郎庙是也，如诚心供奉，二郎真君定会保佑你。\n",
]) );

        setup();
       add_money("silver", 3+random(5));
        carry_object("/d/ourhome/obj/choupao")->wear();
}
void init()
{       
        object ob=this_player();

        ::init();

                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;

        switch( random(1) ) {
                case 0:
                message_vision("$N说道：只要诚心供奉，二郎真君定会保佑你。\n",
this_object());
                break;
        }
}

int accept_object(object who,object ob)
{
        object m;
        if (ob->query("id")=="old pig") {
                say("庙祝笑道：多谢"  + RANK_D->query_respect(who) +
"，二郎真君定会保佑你。\n");
	who->set_temp("erlangpass", 1);
        call_out("destroy", 1, ob);
        return 1;
        }
        else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

