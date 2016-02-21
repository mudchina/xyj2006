//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("ÓñÍÃ", ({"yu tu", "rabbit", "jade rabbit" }));
       set("long",
"ÓñÍÃÏÉÔ­±¾Ö»ÊÇæÏ¶ðµÄ³èÎï£¬Òò³ÔÁËæÏ¶ðµôÔÚµØÉÏµÄÁéÒ©¶ø³ÉÈËÐÎ¡£ÓñÍÃ
ÒòÁéÒ©Ö®ÊÂ±»ÍõÄ¸·£È¥µ·Ò©£¬¾Ã¶ø¾ÃÖ®¾¹ÆÄÍ¨Ò©µÀ¡£\n");
       set("gender", "Å®ÐÔ");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "ÏÉ¹Ã");
       set("per", 30);
	set("int", 30);
       set("max_kee", 500);
       set("max_gin", 500);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 200000);
  set("daoxing", 200000);


        set("eff_dx", 200000);
        set("nkgain", 100);

       set_skill("literate", 50);
       set_skill("unarmed",50);
       set_skill("dodge", 100);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("spells", 50);
        set_skill("moonshentong", 50);
        set_skill("baihua-zhang", 50);
        set_skill("moonforce", 80);
        set_skill("moondance", 100);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("dodge", "moondance");

create_family("ÔÂ¹¬", 2, "µÜ×Ó");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/daoyaochu")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Å®ÐÔ")){
           command("shake");
           command("say ÎÒÃÇÔÂ¹¬Ö»ÊÕÅ®Í½£¬ÕâÎ»" +
RANK_D->query_respect(ob) + "»¹ÊÇÁíÇë¸ß¾Í°É¡£\n");
           return;
        }

        command("pat "+ob->query("id"));
        command("say ºÃ£¬Ï£Íû" + RANK_D->query_respect(ob) +
"¶à¼ÓÅ¬Á¦£¬°ÑÎÒÃÇÔÂ¹¬·¢Ñï¹â´ó¡£\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}


ÿ