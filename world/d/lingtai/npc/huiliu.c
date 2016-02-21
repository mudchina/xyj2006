// worker.c
#include <ansi.h>

inherit NPC;
void create()
{
        set_name("慧琉", ({"hui liu"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "一个相貌堂堂的道士．");
	set("title", "道长");
	set("class", "taoist");
        set("combat_exp", 45000);
	set("daoxing", 60000);

        set("attitude", "peaceful");
        create_family("方寸山三星洞", 4, "弟子");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("force", 30);   
        set_skill("wuxiangforce", 30);
        map_skill("force", "wuxiangforce");

        set("per", 30);
        set("max_kee", 500);
        set("max_sen", 300);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 5);
        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
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
                message_vision("\n\n"NOR,ob);
				command ("say " + "好个盘龙,师叔当真领悟了道家真髓！" );
                message_vision("\n"NOR,ob);
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

