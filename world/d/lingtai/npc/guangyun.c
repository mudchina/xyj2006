#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("¹ãóÞ×Ó", ({"guang yunzi", "guang"}));
        set("gender", "ÄÐÐÔ" );
        set("age", 43);
        set("long", "·½´çÉ½ÈýÐÇ¶´µÚ¶þ´úµÜ×ÓÖÐµÄ½Ü³öÈËÎï£®\n");
        set("combat_exp", 250000);
	set("daoxing", 400000);

        set("attitude", "friendly");
        create_family("·½´çÉ½ÈýÐÇ¶´", 2, "Ê×Í½");
	set("int", 25);
	set("class", "taoist");

        set("eff_dx", 90000);
        set("nkgain", 300);

        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 80);  
        set_skill("dao", 80);
        set_skill("literate", 70);
        set_skill("stick", 80);  
        set_skill("qianjun-bang", 80);
        set_skill("puti-zhi", 80);  
        set_skill("jindouyun", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);   
        set_skill("wuxiangforce", 80);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");


        set("per", 30);
	set("str", 25);
        set("max_kee", 800);
        set("max_gin", 800);
        set("max_sen", 800);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 40);
        set("mana", 450);
        set("max_mana", 300);
	set("mana_factor", 20);
        setup();
	carry_object("/d/lingtai/obj/daoguan")->wear();
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
        command("say " + "¹þ¹þ,ºÃ¸ö"+RANK_D->query_rude(me)+"ËûÈÕ³É¾Í±Ø¶¨¾ª¶¯¾ÅÌì£¡\n");
                            call_out("destroy", 60, ob);

		}
        
}

void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("combat_exp")+(int)ob->query("daoxing") < 30000)) {
	command("say " + RANK_D->query_respect(ob) +
"ÊÇ·ñ»¹Ó¦ÔÚµÀÐÐ¼°Îä¹¦·½Ãæ¶àÏÂÅ¬Á¦£¬À´ÈÕ·½³¤Âð£¡");
	return;
	}
        command("say ºÜºÃ£¬" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬ËûÈÕ±Ø¶¨ÓÐ³É¡£\n");
        command("recruit " + ob->query("id") );
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

ÿ
