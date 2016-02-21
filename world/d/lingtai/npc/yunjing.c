// worker.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("云静", ({"yun jing", "yun"}));
        set("gender", "男性" );
        set("age", 33);
        set("long", "方寸山三星洞第三代弟子中的杰出人物．\n");
        set("combat_exp", 70000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
	set("int", 25);
	set("class", "taoist");
        create_family("方寸山三星洞", 3, "弟子");
	
        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("spells", 40);  
        set_skill("dao", 40);
        set_skill("literate", 40);
        set_skill("stick", 40);  
        set_skill("qianjun-bang", 40);
        set_skill("puti-zhi", 40);  
        set_skill("jindouyun", 40);
        set_skill("dodge", 40);  
        set_skill("force", 40);   
        set_skill("wuxiangforce", 40);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");


        set("per", 30);
        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 10);
        set("mana", 450);
        set("max_mana", 300);
        set("mana_factor", 5);

        setup();
	carry_object("/d/lingtai/obj/daoguanq")->wear();
        carry_object("/d/lingtai/obj/cloth")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}

void init()
{
       object me,ob;
    me=this_player();
	ob=this_object();

        ::init();
        
		if (me->query_temp("fangcun/qiansi_gongxi")==1) 
		{
                 if( !me || !visible(me) || environment(me) != environment() ) return;
				message_vision("\n\n"NOR,me);
				command ("say " + "师叔终潜思大道,真是可喜可贺呀！" );
   				message_vision("\n"NOR,me);
                 call_out("destroy", 60, ob);
        }
        
}

void attempt_apprentice(object ob, object me)
{
        command("say 很好，" + RANK_D->query_respect(ob) +
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

void destroy(object ob)
{
        destruct(ob);
        return;
}
