// worker.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("云清", ({"yun qing", "yun"}));
        set("gender", "男性" );
        set("age", 33);
        set("long",
"方寸山三星洞第三代弟子中的杰出人物．\n虽不是很聪明，但师祖却很看重他．\n");
	set("int", 25);
	set("class", "taoist");
        set("combat_exp", 80000);
	set("daoxing", 100000);

        set("attitude", "peaceful");
        create_family("方寸山三星洞", 3, "弟子");

        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("spells", 50);  
        set_skill("dao", 50);
        set_skill("literate", 30);
        set_skill("stick", 50);  
        set_skill("qianjun-bang", 50);
        set_skill("puti-zhi", 50);  
        set_skill("jindouyun", 50);
        set_skill("dodge", 50);  
        set_skill("force", 50);   
        set_skill("wuxiangforce", 50);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");

	set("str", 30);
        set("per", 30);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
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
				command ("gongxi " + me->query("id") );
               message_vision("\n\n"NOR,me);
                call_out("destroy", 60, ob);
        }
        
}

void attempt_apprentice(object ob, object me)
{
        command("say 很好，" + RANK_D->query_respect(ob) +
"多加努力，他日必定有成。\n");
        command("recruit " + ob->query("id") );
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
return 1;
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

