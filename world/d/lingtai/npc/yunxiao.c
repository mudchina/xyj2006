// worker.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("云霄", ({"yun xiao", "yun"}));
        set("gender", "男性" );
        set("age", 33);
        set("long",
"方寸山三星洞第三代弟子中的杰出人物。
在场边转来转去发些牢骚。\n");
	set("int", 25);
	set("class", "taoist");
        set("combat_exp", 80000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
        create_family("方寸山三星洞", 3, "弟子");
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("spells", 50);  
        set_skill("dao", 50);
        set_skill("literate", 30);
        set_skill("stick", 50);  
        set_skill("puti-zhi", 50);  
        set_skill("jindouyun", 50);
        set_skill("dodge", 50);  
        set_skill("force", 50);   
        set_skill("wuxiangforce", 50);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("dodge", "jindouyun");

	set("str", 30);
        set("per", 30);
        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 20);
        set("mana", 450);
        set("max_mana", 300);
        set("mana_factor", 5);

        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
}


void init()
{
 //       object ob;
       object me,ob;
    me=this_player();
	ob=this_object();

        ::init();
 /*       set("chat_chance", 10);
        set("chat_msg", ({
            "云霄打了个喷嚏．\n",
            "云霄上上下下打量了你几眼。\n",
	    "云霄哼了一声。\n"
        }) );
*/
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
				command ("say " + "我来迟了,我来迟了,哈哈！" );
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
