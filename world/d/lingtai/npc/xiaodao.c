// worker.c
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("扫地小童", ({"xiao tong"}));
        set("gender", "男性" );
        set("age", 13);
        set("long", "一个小童，正在轻轻的扫地");
        set("combat_exp", 1000);
	set_skill("stick", 20);
	set_skill("dodge", 40);
        set("attitude", "friendly");
        set("chat_chance_combat", 50 );
        setup();
	carry_object("/d/lingtai/obj/shaoba")->wield();
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

				message_vision("\n"NOR,ob);
                command ("say 啊.....啊......");
   				message_vision("\n看到巨龙张牙舞爪,抖须长吟,那小童早已面色苍白,双腿发抖!"NOR,ob);
				message_vision("\n吓的一屁股坐在地上,放声大哭起来!\n"NOR,ob);

}
void destroy(object ob)
{
        destruct(ob);
        return;
}
