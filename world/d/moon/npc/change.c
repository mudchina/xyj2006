//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("æÏ¶ð", ({"chang e", "change", "chang","master"}));
       set("long",
"Î÷ÍõÄ¸µÄ´óµÜ×Ó¡£ÔçÄêÒò°ïÖúÕÉ·òµÁÈ¡Î÷ÍõÄ¸Ö®ÁéÒ©¶ø\nÓëÆäÊ¦ÊÆ³ÉË®»ð¡£ºóµÃºÍ½â²¢ÑûÎ÷ÍõÄ¸³öÕÆÔÂ¹¬Ò»ÃÅ¡£\n");
       set("title", "ÔÂ¹¬Ö÷ÈË");
       set("gender", "Å®ÐÔ");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "ÏÉ¹Ã");
       set("per", 30);
	set("int", 30);
       set("max_kee", 900);
       set("max_gin", 600);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 400000);
  set("daoxing", 800000);


        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 80);
       set_skill("unarmed", 80);
       set_skill("dodge", 180);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("spells", 80);
        set_skill("moonshentong", 80);
        set_skill("baihua-zhang", 80);
        set_skill("moonforce", 80);
        set_skill("snowsword", 80);
        set_skill("moondance", 200);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

create_family("ÔÂ¹¬", 2, "µÜ×Ó");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/feijian")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Å®ÐÔ")){
           command("shake");
           command("say ÎÒÃÇÔÂ¹¬Ö»ÊÕÅ®Í½£¬ÕâÎ»" +
RANK_D->query_respect(ob) + "»¹ÊÇÁíÇë¸ß¾Í°É¡£\n");
           return;}
        if ( (int)ob->query("per") <22){
	  command("shake");
	command("say ÒÔÎÒ¿´ÕâÎ»" +
RANK_D->query_respect(ob) + "µÄ×ÊÖÊ²¢²»ÊÊÓÚÌøÎè£¬»¹ÊÇÁíÇë¸ß¾Í°É¡£\n");
  ob->set_temp("denied_by_chang_e",1);
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
