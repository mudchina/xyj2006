// worker.c

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("¹ãóÞ×Ó", ({"guang yunzi", "guang"}));
        set("gender", "ÄÐÐÔ" );
        set("age", 43);
        set("long", "·½´çÉ½ÈýÐÇ¶´µÚ¶þ´úµÜ×ÓÖÐµÄ½Ü³öÈËÎï£®\n");
        set("combat_exp", 160000);
  set("daoxing", 200000);

        set("attitude", "friendly");
        create_family("·½´çÉ½ÈýÐÇ¶´", 2, "Ê×Í½");
	set("int", 25+random(5));
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 100);  
        set_skill("dao", 60);
        set_skill("literate", 80);
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
        set("max_kee", 500);
        set("max_gin", 400);
        set("max_sen", 400);
        set("force", 450);
        set("max_force", 300);
        set("force_factor", 10);
        set("mana", 450);
        set("max_mana", 300);
        set("mana_factor", 8);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: cast_spell, "thunder" :),
        }) );

        setup();
        carry_object("/d/lingtai/obj/cloth")->wear();
        carry_object("/d/lingtai/obj/bang")->wield();
}
void attempt_apprentice(object ob)
{
	if ( ((int)ob->query("combat_exp") < 10000)) {
	command("say " + RANK_D->query_respect(ob) +
"ÊÇ·ñ»¹Ó¦ÔÚµÀµÂ¼°Îä¹¦·½Ãæ¶àÏÂÅ¬Á¦£¬À´ÈÕ·½³¤Âð£¡");
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

ÿ